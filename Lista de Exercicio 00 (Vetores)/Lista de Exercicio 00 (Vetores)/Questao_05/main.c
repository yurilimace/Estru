#include <stdio.h>
#include <stdlib.h>




int Repetido(int Vetor[],int aux)
{
    int i,j,cont=0;
    for(i=0;i<aux;i++)
    {
        for(j=i+1;j<aux;j++)
            {
                 if(Vetor[i]==Vetor[j])
                    {
                        cont++;
                    }

            }
    }
    if(cont==0)
        {
            printf("OK\n\n");
            return 0;
        }
    else
        {
            printf("Existe elementos Repetidos\n\n");
            return 1;
        }

}


void RetiraRepetido(int Vetor[],int aux)
{
    int i,j,k,cont=0;
    for(i=0;i<aux;i++)
    {
        for(j=i+1;j<aux;j++)
        {
            if(Vetor[i]==Vetor[j])
            {   cont++;
                for(k=j+1;k<aux;k++)
                {
                    Vetor[k-1]=Vetor[k];
                }
                aux--;
            }
        }
    }
    printf("foram retirados %d numeros repetidos\n\n",cont);
    Imprime(Vetor,aux);

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
    int aux,i;
    printf("Digite a quantidade de termos que deseja na lista:\n");
    scanf("%d",&aux);
    int VetorA[aux];
    for(i=0;i<aux;i++)
    {
        printf("Digite o %d da lista (indice %d):\n",i+1,i);
        scanf("%d",&VetorA[i]);
    }

    printf("\n\n");
    //Repetido(VetorA,aux);
    if(Repetido(VetorA,aux)==0)
    {
        Imprime(VetorA,aux);
    }
    else
    {
        Imprime(VetorA,aux);
        RetiraRepetido(VetorA,aux);
    }



    return 0;
}
