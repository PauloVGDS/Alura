#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include "main.h"

MAPA mapa1;
POSICAO atual;
bool red_pill = false;

int acabou() {
    POSICAO pos;

    int find = findPos(&mapa1, &pos, HEROI);
    return !find;
}

int phantomWalk(int xatual, int yatual, int* xdestino, int* ydestino) {
    int opcoes[4][2] = {
    {xatual, yatual + 1},
    {xatual + 1, yatual},
    {xatual, yatual - 1},
    {xatual - 1, yatual}
    };

    srand(time(0));

    for (int i = 0; i < 10; i++) {
        int posicao = rand() % 4;

        if(canWalk(&mapa1, FANTASMA, opcoes[posicao][0], opcoes[posicao][1])) {
            *xdestino = opcoes[posicao][0];
            *ydestino = opcoes[posicao][1];
            return 1;
        }
    }
    
}

void copiamapa(MAPA* destino, MAPA* origem) {
    destino->linhas = origem->linhas;
    destino->colunas = origem->colunas;

    *destino = allocMap(*destino);
    for (int i = 0; i < origem->linhas; i++)
    {
        strcpy(destino->matriz[i], origem->matriz[i]);  
    }
}

void fantasmas() {
    MAPA copia;
    copiamapa(&copia, &mapa1);

    for (int i = 0; i < mapa1.linhas; i++)
    {
        for (int j = 0; j < mapa1.colunas; j++)
        {
            if (copia.matriz[i][j] == FANTASMA)
            {
                int xdestino;
                int ydestino;

                int find = phantomWalk(i, j, &xdestino, &ydestino);

                if (find)
                {
                    walk(&mapa1, i, j, xdestino, ydestino);
                }   
            }   
        }
    }
    freeMap(&copia);
    
}

void move(char direcao) {
    
    if (!moviment(direcao)) return;

    int nextx = atual.x;
    int nexty = atual.y;

    switch (direcao)
    {
    case CIMA:
        nextx--;
        break;
    case ESQUERDA:
        nexty--;
        break;
    case BAIXO:
        nextx++;
        break;
    case DIREITA:
        nexty++;
        break;
    }

    if(!canWalk(&mapa1, HEROI, nextx, nexty)) return;

    if(isProta(&mapa1, PILULA, nextx, nexty)) {
        red_pill = true;
    }

    walk(&mapa1, atual.x, atual.y, nextx, nexty);
    atual.x = nextx;
    atual.y = nexty;

}

void pillExplode() {

    if (!red_pill) return;

    pillExplode2(atual.x, atual.y, 0, 1, 3);
    pillExplode2(atual.x, atual.y, 0, -1, 3);
    pillExplode2(atual.x, atual.y, 1, 0, 3);
    pillExplode2(atual.x, atual.y, -1, 0, 3);

    red_pill = false; 
}

void pillExplode2(int x, int y, int somax, int somay, int qnt) {
    
    if (qnt == 0) return;
    
    int novox = x + somax;
    int novoy = y + somay;

    if (isWall(&mapa1, novox, novoy)) return;
    if (!isValid(&mapa1, novox, novoy)) return;

    mapa1.matriz[novox][novoy] = CAMINHO;
    pillExplode2(novox, novoy, somax, somay, qnt - 1);
}


int main() {

    FILE* arquivo;
    arquivo = fopen("mapa.txt", "r");

    if (arquivo == NULL) {
        printf("Erro na leitura do arquivo!");
        exit(1);
    }


    mapa1.linhas = 5;
    mapa1.colunas = 10;


    fscanf(arquivo, "%d %d", &(mapa1.linhas), &(mapa1.colunas));

    // printf("linhas %d colunas %d\n", linhas, colunas);

    mapa1 = allocMap(mapa1);

    readMap(arquivo, &mapa1);
    
    findPos(&mapa1, &atual, HEROI);
    
    do
    {
        printf("E redpill? %s\n", red_pill == true ? "SIM" : "NAO");
        printMap(&mapa1);

        char direction;
        printf("Qual direcao: ");
        scanf(" %c", &direction);
        printf("\n");
        move(direction);
        
        if (direction == BOMBA) pillExplode();

        fantasmas();
        
    } while (!acabou());
    

    freeMap(&mapa1);
    
    fclose(arquivo);
    
    
}

