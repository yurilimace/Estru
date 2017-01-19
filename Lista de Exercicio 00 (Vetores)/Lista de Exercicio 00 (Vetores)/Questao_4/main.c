#include <stdio.h>
#include <stdlib.h>


int Primo(int ent)
{
    int i;
    int cont=0;
    for(i=1;i<=ent;i++)
    {
        if(ent%i==0)
        {
            cont++;
        }
    }

    if(cont==2)
    {
        //printf("%d eh primo\n",ent);
        return 0;

    }
    else
    {
        //printf("%d nao e primo\n",ent);
        return 1;
    }
}




void PrimoAnterior(int ent,int Vetor[])
{
    int cont1=0,i=1,j;
    int aux=ent;
    while(cont1<2)
    {
       aux--;
       j=Primo(aux);
       if(j==0)
        {
            Vetor[i]=aux;
            cont1++;
            i--;
        }

    }




}


void PrimoPosterior(int ent,int Vetor[])
{
    int cont1=0,i=3,j;
    int aux=ent;
    while(cont1<2)
    {
       aux++;
       j=Primo(aux);
       if(j==0)
        {
            Vetor[i]=aux;
            cont1++;
            i++;
        }

    }




}

void Imprime(int Vetor[])
{
    int i;
    for(i=0;i<=4;i++)
        {
            printf("%d ",Vetor[i]);

        }
    printf("\n\n");
}


int main()
{
    int ent,Vetor[4],aux;
    while(Primo(ent)!=0)
    {
      printf("Digite um numero:\n");
      scanf("%d",&ent);
      Primo(ent);
    }

    Vetor[2]=ent;
    PrimoPosterior(ent,Vetor);
    aux=Vetor[2];
    PrimoAnterior(aux,Vetor);
    Imprime(Vetor);
    system("pause");
    return 0;
}
