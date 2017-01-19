#include <stdio.h>
#include <stdlib.h>

int Elementosy(int VetorX[],int aux)
{
    int i;
    int cont=0;
    for(i=0;i<aux;i++)
        {
            if(VetorX[i]>=10 && VetorX[i]<=40)
                {
                    cont++;
                }
        }
        return cont;
}

void Filtro1040(int VetorX[],int VetorY[],int aux)
{
    int i,j=0;
    for(i=0;i<aux;i++)
    {
        if(VetorX[i]>=10 && VetorX[i]<=40)
                {
                    VetorY[j]=VetorX[i];
                    j++;
                }
    }

}



int Elementosw(int VetorX,int aux)
{
    int i;
    int cont=0;
    for(i=0;i<aux;i++)
        {
            if(i%2==0)
                {
                    cont++;
                }
        }
        return cont;
}


void PosicaoPar(int VetorX[],int VetorY[],int aux)
{
    int i,j=0;
    for(i=0;i<aux;i++)
    {
        if(i%2==0)
            {
                VetorY[j]=VetorX[i];
                j++;
            }
    }

}


int Pesquisa(int VetorX[],int aux)
{
    int bus;
    int i;
    printf("digite o termo que deseja encontrar:\n");
    scanf("%d",&bus);
    for(i=0;i<aux;i++)
    {
        if(bus==VetorX[i])
        {
            return 0;
        }

    }
    return -1;
}

void MaioreMenor(int VetorX[],int aux)
{
    int i,j,menor=VetorX[0],maior=VetorX[0];
    for (i=0;i<aux;i++)
    {
        if(VetorX[i]>maior)
            {
                maior=VetorX[i];
            }
        if(VetorX[i]<menor)
            {
                menor=VetorX[i];
            }


    }

    printf("o maior numero eh:%d e o menor eh%d",maior,menor);
}



void Imprime(int Vetor[],int aux)
{
    int i;
    for(i=0;i<aux;i++)
        {
            printf("%d ",Vetor[i]);

        }
    printf("\n\n");
}



int main()
{
    int aux,aux2,i;
    printf("Digite a quantidade de termos que deseja na lista:\n");
    scanf("%d",&aux);
    int VetorX[aux];

    for(i=0;i<aux;i++)
        {
            printf("Digite o elemento da %d posicao (indice %d):\n",i+1,i);
            scanf("%d",&VetorX[i]);
        }

    //item a
    aux2=Elementosy(VetorX,aux);
    int VetorY[aux2];
    Filtro1040(VetorX,VetorY,aux);
    printf("Vetor Y com elementos na faixa entre 10 e 40\n");
    Imprime(VetorY,aux2);

    //item b
    printf("\n\n");
    aux2=Elementosw(VetorX,aux);
    int VetorW[aux2];
    PosicaoPar(VetorX,VetorW,aux);
    printf("Vetor W com os elementos de indice par \n");
    Imprime(VetorW,aux2);

    // item c
    printf("Busca de Elementos no Vetor\n");
    int c=Pesquisa(VetorX,aux);
    if(c==0)
    {
       printf("Valor Encontrado");
    }
    else
    {
        printf("Valor não Encontrado");
    }

    //item d
    printf("\n");
    printf("Mostra maior e menor elemento do Vetor\n");
    MaioreMenor(VetorX,aux);




    return 0;
}
