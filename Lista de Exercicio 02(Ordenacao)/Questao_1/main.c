#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<windows.h>

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
    //Verifica se é necessario a ordenação
    if(i>=j)
    {
        return 0;
    }

    //define o pivo como o elemento da posicao central do vetor
    int pivo=Vetor[((inicio+aux)/2)];

    //percorre o vetor ate o indice que se encontra o pivo
    while(i<j)
    {

        /*os dois whiles a seguir testam se o numero e maior ou menos que o pivo */

        //se o indice i for menor que o do pivo e o elemento[i]<pivo nao precisa ser trocado
        //por isso incrementa o i passado para o proximo elemento
        while(i<j && Vetor[i] < pivo)
        {
            i++;
        }

        //se o indice i for menor que o do pivo e o elemento[j]<pivo nao precisa ser trocado
        //por isso decrementa  o j passado para o proximo elemento
        while(i<j && Vetor[j]>pivo)
        {
            j--;
        }

       //troca os valroes colocando os menores a esquerda do pivo e os maiores a direita do pivo
       if(i<j)
        {
            aux2=Vetor[i];
            Vetor[i]=Vetor[j];
            Vetor[j]=aux2;
            i++;
            j--;
        }
    }

    //ajusta os valores caso j < i deixando novamente i menor que j
    if(j<i)
        {
            aux2=j;
            j=i;
            i=aux2;
        }

    //chama recursivamnte o metodo pegando do inicio ate o pivo
    quicksort(Vetor,inicio,i);
    //se o elemento central  estiver na posição correta
    if(i==inicio)
    {
        //do elemento central  para frente
        quicksort(Vetor,i+1,aux);
    }

    else
    {
        //orddena junto com o elemento central
        quicksort(Vetor,i,aux);
    }
}


void Preenchendo(int Vetor[],int aux)
{
    int i;
    srand(time(NULL));
    for(i=0;i<aux;i++)
    {
        Vetor[i]=rand()%1000;
    }
}


void Imprime(int Vetor[],int aux)
{
    int i;
    for(i=0;i<aux;i++)
    {
        printf("%d ",Vetor[i]);
    }

    printf("\n\n\n");


}


int Menu()
{
    int op;
    printf("Metodos de Ordenacao:\n");
    printf("1- Metodo da Bolha (Bubblesort)\n");
    printf("2- Metodo da insercao (Insertion sort)\n");
    printf("3- Metodo da selecao (Selection sort sort)\n");
    printf("4- Quicksort\n");
    printf("0 - para sair\n");
    printf("Escolha uma opcao\n");
    scanf("%d",&op);
    return op;
}

int main()
{
    int aux,op;
    printf("Digite o numero de elementos do vetor\n");
    scanf("%d",&aux);
    int Vetor[aux];
    Preenchendo(Vetor,aux);
    Imprime(Vetor,aux);


    while(op=!0)
    {
       op=Menu();
    switch(op)
    {
    case 1:
        {
            Bubblesort(aux,Vetor);
            Imprime(Vetor,aux);
            break;
        }
    case 2:
        {
            InsertionSort(aux,Vetor);
            Imprime(Vetor,aux);
            break;
        }
    case 3:
        {
          Selectionsort(aux,Vetor);
          Imprime(Vetor,aux);
          break;
        }
     case 4:
         {
           quicksort(Vetor,0,aux);
           Imprime(Vetor,aux);
           break;
         }

     default:
        printf("digite uma opcao valida");
        break;

       }
    }








    //Selectionsort(aux,Vetor);
    //InsertionSort(aux,Vetor);
    //quicksort(Vetor,0,aux);
    //Imprime(Vetor,aux);

    return 0;
}
