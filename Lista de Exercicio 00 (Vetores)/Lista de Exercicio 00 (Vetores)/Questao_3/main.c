#include <stdio.h>
#include <stdlib.h>


int Busca(int VetorX[],int aux)
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
    int aux,aux2,i,j=0;
    printf("Digite a quantidade de termos que deseja na lista:\n");
    scanf("%d",&aux);
    int VetorA[aux];
    int VetorB[aux];
    aux2=aux*2;
    int VetorC[aux2];

    for(i=0;i<aux;i++)
        {
            printf("Digite o elemento da %d posicao (indice %d):\n",i+1,i);
            scanf("%d",&VetorA[i]);
        }
    for(i=0;i<aux;i++)
        {
            printf("Digite o elemento da %d posicao (indice %d):\n",i+1,i);
            scanf("%d",&VetorB[i]);
        }
    for(i=0;i<aux2;i++)
        {
            if(i%2==0)
                {
                    VetorC[i]=VetorA[j];
                }
            else
                {
                    VetorC[i]=VetorB[j];
                    j++;
                }
        }







    Imprime(VetorA,aux);
    Imprime(VetorB,aux);
    Imprime(VetorC,aux2);

    int x=Busca(VetorC,aux2);
    if(x==0)
    {
        printf("Valor Encontrado");
    }
    else
    {
        printf("Valor nao existe na lista");
    }
    printf("\n");

    system("Pause");
    return 0;
}
