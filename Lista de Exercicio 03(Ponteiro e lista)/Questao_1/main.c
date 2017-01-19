#include <stdio.h>
#include <stdlib.h>
#include<locale.h>
struct Box
{
    char conteudo;
    struct Box *proximo;
};

typedef struct Box TBox;

 TBox *inicio;
 TBox *novo;
 TBox *fim;
 TBox *temp2;
 TBox *aux;
 TBox *temp1;





int main()
{


    setlocale(LC_ALL, "Portuguese");
    //celula cabeça
    inicio=(TBox *)malloc(sizeof(TBox));
    inicio->proximo=NULL;
    fim=inicio;

    //inicializando a lista com o X
    fim->proximo=(TBox *)malloc(sizeof(TBox));
    fim=fim->proximo;
    fim->conteudo='X';
    fim->proximo=NULL;
    temp2=fim;


    for(aux=inicio->proximo;aux!=NULL;aux=aux->proximo)
    {
        printf("%c ",aux->conteudo);
    }

    printf("\n\n\n");


    //Questao 1
    fim->proximo=(TBox *)malloc(sizeof(TBox));
    fim=fim->proximo;
    fim->conteudo='A';
    fim->proximo=NULL;
    temp1=fim;

    printf("Questao 1 Insira um elemento contendo a letra A no final da lista \n");
    for(aux=inicio->proximo;aux!=NULL;aux=aux->proximo)
    {
        printf("%c ",aux->conteudo);
    }

    printf("\n\n");


    //Questao 2

    novo=(TBox *)malloc(sizeof(TBox));
    inicio->proximo=novo;
    novo->conteudo='B';
    novo->proximo=temp2;

    printf("Questao 2 Insira um elemento contendo a letra B no inicio da lista. \n");
    for(aux=inicio->proximo;aux!=NULL;aux=aux->proximo)
    {
        printf("%c ",aux->conteudo);
    }

    printf("\n\n");



   //Questao 3
   fim->proximo=(TBox *)malloc(sizeof(TBox));
   fim=fim->proximo;
   fim->conteudo='C';
   fim->proximo=NULL;
   temp2=fim;

   printf("Questao 3 Insira um elemento contendo a letra C no final da lista.\n");
    for(aux=inicio->proximo;aux!=NULL;aux=aux->proximo)
    {
        printf("%c ",aux->conteudo);
    }

    printf("\n\n");



   //Questao 4
   fim->proximo=(TBox *)malloc(sizeof(TBox));
   fim=fim->proximo;
   fim->conteudo='D';
   fim->proximo=NULL;

   printf("Questao 4 Insira um elemento contendo a letra D no final da lista.\n");
    for(aux=inicio->proximo;aux!=NULL;aux=aux->proximo)
    {
        printf("%c ",aux->conteudo);
    }

    printf("\n\n");





   //Questao 5
   temp1->proximo=(TBox *)malloc(sizeof(TBox));
   temp1=temp1->proximo;
   temp1->conteudo='E';
   temp1->proximo=temp2;


    printf("Questao 5 Insira um elemento contendo a letra E entre os elementos de conteúdo A e C.\n");
    for(aux=inicio->proximo;aux!=NULL;aux=aux->proximo)
    {
        printf("%c ",aux->conteudo);
    }

    printf("\n\n");



    //Questao 6
    novo=temp2;
    temp1->proximo=novo->proximo;
    free(novo);


    printf("Questao 6 Exclua o elemento de conteúdo C.\n");
    for(aux=inicio->proximo;aux!=NULL;aux=aux->proximo)
    {
        printf("%c ",aux->conteudo);
    }

    printf("\n\n");


    //Questao 7

   fim->proximo=(TBox *)malloc(sizeof(TBox));
   fim=fim->proximo;
   fim->conteudo='F';
   fim->proximo=NULL;

    printf("Questao 7 Insira um elemento contendo a letra F no final da lista.\n");
    for(aux=inicio->proximo;aux!=NULL;aux=aux->proximo)
    {
        printf("%c ",aux->conteudo);
    }

    printf("\n\n");

    //Questao 8
    temp1=inicio->proximo;
    novo=(TBox *)malloc(sizeof(TBox));
    novo->conteudo='G';
    inicio->proximo=novo;
    novo->proximo=temp1;

    printf("Questao 8 Insira um elemento contendo a letra G no inicio da lista.\n");
    for(aux=inicio->proximo;aux!=NULL;aux=aux->proximo)
    {
        printf("%c ",aux->conteudo);
    }

    printf("\n\n");

    //Questao 9
    temp1=inicio->proximo;
    //retirando o ultimo elemento
    for(aux=inicio->proximo;aux!=NULL;aux=aux->proximo)
    {
        if(aux->proximo!=NULL)
        {
            temp1=aux;
        }
    }
    temp1->proximo=NULL;
    free(fim);
    fim=temp1;

    //retirando o primeiro termo da lista
    temp2=inicio->proximo;
    temp1=temp2->proximo;
    inicio->proximo=temp1;
    free(temp2);



    printf("Questao 9 Exclua o último elemento e o primeiro elemento.\n");
    for(aux=inicio->proximo;aux!=NULL;aux=aux->proximo)
    {
        printf("%c ",aux->conteudo);
    }

    printf("\n\n");


    //Questao 10
    for(aux=inicio->proximo;aux!=NULL;aux=aux->proximo)
    {
        if(aux->conteudo=='A')
        {
            temp1=aux;
        }
        if(aux->conteudo=='E')
        {
            temp2=aux;
        }
    }
    temp1->proximo=(TBox *)malloc(sizeof(TBox));
    temp1=temp1->proximo;
    temp1->conteudo='H';
    temp1->proximo=temp2;

    printf("Questao 10 Insira um elemento contendo a letra H entre os elementos de conteúdo A e E.\n");
    for(aux=inicio->proximo;aux!=NULL;aux=aux->proximo)
    {
        printf("%c ",aux->conteudo);
    }

    printf("\n\n");


    //Questao 11


    for(aux=inicio->proximo;aux->proximo!=NULL;aux=aux->proximo)
    {

        if(aux->proximo->conteudo=='A')
        {
            temp1=aux->proximo;
            temp2=aux->proximo->proximo;
            aux->proximo=temp2;
            free(temp1);
        }


    }

    printf("Questao 11 Exclua o elemento de conteúdo A.\n");
    for(aux=inicio->proximo;aux!=NULL;aux=aux->proximo)
    {
        printf("%c ",aux->conteudo);
    }

    printf("\n\n");




    //Questao 12
    for(aux=inicio->proximo;aux!=NULL;aux=aux->proximo)
    {
        if(aux->conteudo=='E')
        {
            temp1=aux;
        }
        if(aux->conteudo=='D')
        {
            temp2=aux;
        }
    }
    temp1->proximo=(TBox *)malloc(sizeof(TBox));
    temp1=temp1->proximo;
    temp1->conteudo='I';
    temp1->proximo=temp2;


    printf("Questao 12 Insira um elemento contendo a letra I entre os elementos de conteúdo E e D.\n");
    for(aux=inicio->proximo;aux!=NULL;aux=aux->proximo)
    {
        printf("%c ",aux->conteudo);
    }

    printf("\n\n");




    //Questao 13
    fim->proximo=(TBox *)malloc(sizeof(TBox));
    fim=fim->proximo;
    fim->conteudo='J';
    fim->proximo=NULL;


    printf("Questao 13 Insira um elemento contendo a letra J no final da lista.\n");
    for(aux=inicio->proximo;aux!=NULL;aux=aux->proximo)
    {
        printf("%c ",aux->conteudo);
    }

    printf("\n\n");

    //Questao 14
    for(aux=inicio->proximo;aux!=NULL;aux=aux->proximo)
    {
        if(aux->conteudo=='B')
        {
            temp1=aux;
        }
        if(aux->conteudo=='H')
        {
            temp2=aux;
        }



    }
    novo=temp1->proximo;
    inicio->proximo=novo;
    novo->proximo=temp1;
    temp1->proximo=(TBox *)malloc(sizeof(TBox));
    temp1=temp1->proximo;
    temp1->conteudo='K';
    temp1->proximo=temp2;




        printf("Questao 14 Insira um elemento contendo a letra K entre os elementos de conteúdo B e H.\n");
    for(aux=inicio->proximo;aux!=NULL;aux=aux->proximo)
    {
        printf("%c ",aux->conteudo);

    }
    printf("\n\n");




    //Questao 15

    for(aux=inicio->proximo;aux->proximo!=NULL;aux=aux->proximo)
    {
        if(aux->conteudo=='B')
        {
            temp1=inicio->proximo;
            inicio->proximo=aux->proximo;
            //free(temp1);
        }
        if(aux->proximo->conteudo=='I')
        {
            temp1=aux->proximo;
            temp2=aux->proximo->proximo;
            aux->proximo=temp2;
            free(temp1);
        }
        if(aux->conteudo=='K')
        {
            temp1=inicio->proximo;
            inicio->proximo=aux->proximo;
            //free(temp1);
        }
        if(aux->proximo->conteudo=='D')
        {
            temp1=aux->proximo;
            temp2=aux->proximo->proximo;
            aux->proximo=temp2;
            free(temp1);
        }

    }

    printf("Questao 15 Exclua o elemento de conteúdo D, K, I e B\n");
    for(aux=inicio->proximo;aux!=NULL;aux=aux->proximo)
    {
        printf("%c ",aux->conteudo);

    }
    printf("\n\n");


    //Questao 16
    fim->proximo=(TBox *)malloc(sizeof(TBox));
    fim=fim->proximo;
    fim->conteudo='L';
    fim->proximo=NULL;


    printf("Questao 16 Insira um elemento contendo a letra L no final da lista\n");
    for(aux=inicio->proximo;aux!=NULL;aux=aux->proximo)
    {
        printf("%c ",aux->conteudo);
    }

    printf("\n\n");












return 0;
}
