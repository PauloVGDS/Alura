#include "constants.h"

/*
Preenche o mapa com o conteúdo do arquivo
*/
int readMap(FILE *arq, MAPA* m) {
    for (int i = 0; i < m->linhas; i++)
    {
        fscanf(arq, "%s", m->matriz[i]);
    }
    return 0;
}

int printMap(MAPA* m)
{

    for (int i = 0; i < m->linhas; i++)
    {
        printf("%s\n", m->matriz[i]);
    }
    return 0;
}

struct map allocMap(MAPA m)
{
    m.matriz = malloc(sizeof(char *) * m.linhas);
    for (int i = 0; i < m.linhas; i++)
    {
        m.matriz[i] = malloc(sizeof(char) * (m.colunas + 1));
    }

    return m;
}

int freeMap(MAPA* m)
{
    for (int i = 0; i < m->linhas; i++)
    {
        free(m->matriz[i]);
    }
    free(m->matriz);

    return 0;
}


int findPos(MAPA* m, POSICAO* p, char c) {
    for (int i = 0; i < m->linhas; i++) {
        for (int j = 0; j < m->colunas; j++) {
            if (m->matriz[i][j] == c) {
                p->x = i;
                p->y = j;
                return 1;
            }
        }
    }
    return 0;
    
}

int moviment(char direcao) {
    return direcao == CIMA || direcao == ESQUERDA || direcao == BAIXO || direcao == DIREITA;
}

int isValid(MAPA* m, int x, int y)  {
    if (x >= m->linhas || y >= m->colunas) return 0;
    return 1;
}

int isPath(MAPA* m, int x, int y) {
    return m->matriz[x][y] == CAMINHO;
}

int isWall(MAPA* m, int x, int y) {
    return m->matriz[x][y] == PAREDE_VERTICAL || m->matriz[x][y] == PAREDE_HORIZONTAL;
}

int isProta(MAPA* m, char prota, int x, int y) {
    return m->matriz[x][y] == prota;
}

int canWalk(MAPA* m, char prota, int x, int y) {
    return isValid(m, x, y) && !isWall(m, x, y) && !isProta(m, prota, x, y);
}

void walk(MAPA* m, int xo, int yo, int xd, int yd) {
    char persona = m->matriz[xo][yo];
    m->matriz[xd][yd] = persona;
    m->matriz[xo][yo] = CAMINHO;
}