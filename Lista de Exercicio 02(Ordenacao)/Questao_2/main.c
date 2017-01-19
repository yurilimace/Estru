#include <stdio.h>
#include <stdlib.h>
#include<time.h>

void Bubblesort(int aux,int Vetor[])
{
    int i,j,aux2;
    for(i=0;i<aux;i++)
    {
        for(j=i+1;j<aux;j++)
        {
            if(Vetor[i]>Vetor[j])
            {
                aux2=Vetor[i];
                Vetor[i]=Vetor[j];
                Vetor[j]=aux2;
            }
        }
    }


}

void Selectionsort(int aux,int Vetor[])
{
    int i,j,menor,aux2;
    for(i=0;i<aux;i++)
    {
        menor=Vetor[i];
        for(j=i+1;j<aux;j++)
        {
            if(Vetor[j]<menor)
            {
                aux2=Vetor[j];
                Vetor[j]=menor;
                menor=aux2;
            }
          Vetor[i]=menor;
        }
    }


}



void InsertionSort(int aux,int Vetor[])
{
    int i,j,aux2;
    for(i=0;i<aux;i++)
    {
        aux2=Vetor[i];
        j=i-1;

        while(j>=0 && aux2<Vetor[j])
        {
            Vetor[j+1]=Vetor[j];
            j=j-1;
        }

        Vetor[j+1]=aux2;

    }
}



void quicksort(int Vetor[],int inicio,int aux)
{
    int i=inicio;
    int j=aux; //aux=fim
    int aux2;

    if(i>=j)
    {
        return;
    }

    int pivo=Vetor[((inicio+aux)/2)];

    while(i<j)
    {
        while(i<j && Vetor[i] < pivo)
        {
            i++;
        }
        while(i<j && Vetor[j]>pivo)
        {
            j--;
        }

        if(i<j)
        {
            aux2=Vetor[i];
            Vetor[i]=Vetor[j];
            Vetor[j]=aux2;
            i++;
            j--;
        }
    }

    if(j<i)
        {
            aux2=j;
            j=i;
            i=aux2;
        }
    quicksort(Vetor,inicio,i);
    if(i==inicio)
    {
        quicksort(Vetor,i+1,aux);
    }
    else
    {
        quicksort(Vetor,i,aux);
    }
}


void Preenchendo(int Vetor[],int aux)
{
    int i;
    for(i=0;i<aux;i++)
    {
        Vetor[i]=rand()%1000;
    }
}


int main()
{
    int Vetor[10000];
    Preenchendo(Vetor,10000);
    clock_t ini,fim,res=0;

    ini=clock();
    Bubblesort(10000,Vetor);
    fim=clock();
    res=fim-ini;
    printf(" %d\n\n\n",(int)res);
    //Selectionsort(100,Vetor);
    //InsertionSort(100,Vetor);
    //quicksort(Vetor,0,100);
    //system("pause");


    return 0;
}
