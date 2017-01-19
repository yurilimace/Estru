#include <stdio.h>
#include <stdlib.h>

//Função que mostra o menu
int Menu()
{

       int op;
       printf("1-Ordene os números lidos em ordem decrescente\n");
       printf("2-Informar quantos são ímpares e quantos são pares\n");
       printf("3-Apresente a média dos números ímpares maiores que 50\n");

       printf("Escolha uma opcao:\n");
       scanf("%d",&op);
       printf("\n");

       return op;

}

//Função que imprime o Vetor
void Imprime(int Vetor[],int aux)
{
    int i;
    for(i=0;i<aux;i++)
        {
            printf("%d ",Vetor[i]);
        }
    printf("\n");
}


//Função que mostra a quantidade de numeros pares e impares
void ehpar(int Vetor[],int aux)
{
    int i,contpar=0;
    for(i=0;i<aux;i++)
    {
        if(Vetor[i]%2==0)
            {
                contpar++;
            }
    }
    printf("O numero de numeros pares e :%d\n",contpar);
    printf("O numero de numeros pares e :%d\n",aux-contpar);
    printf("\n");
}

//Função que ordena o Vetor de forma decresente
void Ordenar(int Vetor[],int aux)
{
    int i,j,helper;

    for(i=0;i<aux;i++)
        {
            for(j=i+1;j<aux;j++)
                {
                    if(Vetor[i]<Vetor[j])
                    {
                        helper=Vetor[i];
                        Vetor[i]=Vetor[j];
                        Vetor[j]=helper;
                    }

                }
        }
        printf("\n");
}


//Função tira a média dos elementos que forem maiores que 50
void Media(int Vetor[],int aux)
{
    int i,somador=0,contador=0;
    float media;
    for(i=0;i<aux;i++)
    {
        if(Vetor[i]>50)
            {
                somador+=Vetor[i];
                contador++;

            }
    }
    printf("A media dos numeros maiores que 50 eh %0.1f",(float)somador/contador);
    printf("\n");


}



int main()
{
    int i=0,aux,aux2,op;

    //Determina quantidade de elementos do Vetor não deixando ser maior que 100 elementos
    printf("Digite a quantidade de termos do Vetor(Max 100)\n");
    scanf("%d",&aux);

    while(aux>100)
    {
        printf("Digite a quantidade de termos do Vetor(Max 100)\n");
        scanf("%d",&aux);

    }


    int Vetor[aux];

    //preenchendo o Vetor
    while(i<aux)
        {
            printf("Digite o %d º numero da lista\n",i+1);
            scanf("%d",&aux2);
            if(aux2<256)
                {
                    Vetor[i]=aux2;
                    i++;
                }
        }

  //menu com os itens da questão
  while(op!=0)
    {
        op=Menu();
        switch(op)
        {
            //ordenar de forma decrescente
            case 1:
            {
              printf("Vetor Ordenado Decrescente\n");
              Ordenar(Vetor,aux);
              Imprime(Vetor,aux);
              break;
            }

            //mostrar a quantidade de par e impar no vetor
            case 2:
            {
                Imprime(Vetor,aux);
                ehpar(Vetor,aux);
                break;
            }
            //mostra a media dos elementos maiores que 50
            case 3:
            {
              Media(Vetor,aux);
              break;
            }


        }
    }




}
