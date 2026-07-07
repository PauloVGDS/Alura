#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include "forca.h"

#define break_line printf("\n");

char secretword[20];
char chutes[26];
int chutesdados = 0;

void abertura() {
    printf("--------------------\n");
    printf("JOGO DA FORCA\n");
    printf("--------------------\n");
}

void escolhepalavra() {
    FILE* arquivo;
    arquivo = fopen("words.txt", "r");
    if (arquivo == NULL) {
        printf("Falha ao abrir o arquivo.");
        exit(1);
    }
    int wordscount;
    fscanf(arquivo, "%d", &wordscount);

    srand(time(0));
    int aleatorio = rand() % wordscount;

    for (int i = 0; i < aleatorio; i++)
    {
        fscanf(arquivo, "%s", secretword);
    }
    
    fclose(arquivo);
}

void chuta() {
    char chute;
    printf("Digite o seu chute: ");
    scanf(" %c", &chute);
    break_line
    chutes[chutesdados] = chute;
    chutesdados++;
}

bool jachutou(char letra) {
    for (int i = 0; i < chutesdados; i++)
    {
        if (chutes[i] == letra) return true;
    }
    return false;
}

void desenhaforca() {
    printf("Foram %d chutes ate agora.\n", chutesdados);
    for (int i = 0; i < strlen(secretword); i++)
    {
        if (jachutou(secretword[i])) {
            printf("%c ", secretword[i]);
        }
        else {
            printf("_ ");
        }
    }
    break_line
}

bool ganhou() {
    for (int i = 0; i < strlen(secretword); i++)    
    {
        if (!jachutou(secretword[i])) {
            return false;
        }
    }
    printf("Parabens, voce ganhou em %d tentativas!'\n", chutesdados);
    break_line
    desenhaforca();
    break_line
    return true;
    
}

bool enforcou() {
    int erros = 0; 

    for (int i = 0; i < chutesdados; i++)
    {
        bool exists = false;
        for (int j = 0; j < strlen(secretword); j++) {
            if (chutes[i] == secretword[j]) {
                exists = true;
                break;
            }
        }
        
        if (!exists) erros++;
       
    }

    return erros >= 5;
}

int main() {
    abertura();
    escolhepalavra();
    do
    {
        desenhaforca();
        chuta();

    } while (!ganhou() && !enforcou());

}