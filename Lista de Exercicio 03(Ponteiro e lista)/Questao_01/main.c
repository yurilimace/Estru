#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Pilha
{
    char item[30];
    struct Pilha *prox;
};

typedef struct Pilha Tpilha;
Tpilha *Topo;


void Cabeca(Tpilha Topo)
{
    Topo=(Tpilha *)malloc(sizeof(Tpilha));
    Topo->prox=NULL;

}

int Vazia(Tpilha Topo)
{
    return(Topo->prox==NULL);
}


int main()
{
    Cabeca(Topo);
    Vazia(Topo);
    return 0;
}
