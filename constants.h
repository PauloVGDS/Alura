struct map {
    char** matriz;
    int linhas;
    int colunas;
};

struct pos {
    int x;
    int y;
};

typedef struct map MAPA;
typedef struct pos POSICAO;

#define FANTASMA 'F'
#define HEROI '@'
#define PILULA 'P'
#define BOMBA 'b'
#define PAREDE_VERTICAL '|'
#define PAREDE_HORIZONTAL '-'
#define CAMINHO '.'
#define CIMA 'w'
#define BAIXO 's'
#define ESQUERDA 'a'
#define DIREITA 'd'

