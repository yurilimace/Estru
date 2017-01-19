#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct No
{
    int info;
    struct No *direita;
    struct No *esquerda;
};

typedef struct No Tnoh;
Tnoh *Raiz;

Tnoh *Inicializar()
{

    return NULL;
}

void Vazia(Tnoh *raiz)
{
    if(raiz==NULL)
    {
        printf("Arvore Vazia\n");
    }
    else
    {
        printf("Arvore nao Vazia\n");
    }
}

Tnoh *Cria_Raiz(int a)
{
    Tnoh *novo=(Tnoh *)malloc(sizeof(Tnoh));
    novo->info=a;
    novo->direita=NULL;
    novo->esquerda=NULL;
    return novo;

}

Tnoh *Cria_NO(int b)
{
    Tnoh *novo=(Tnoh *)malloc(sizeof(Tnoh));
    novo->info=b;
    novo->direita=NULL;
    novo->esquerda=NULL;
    return novo;

}

Tnoh *Insere(Tnoh *raiz,int b)
{
    if(raiz == NULL)
    {
        Tnoh *novo=(Tnoh *)malloc(sizeof(Tnoh));
        novo->info=b;
        novo->direita=NULL;
        novo->esquerda=NULL;
        raiz=novo;
    }
    if(raiz->info < b)
    {
        raiz->direita=Insere(raiz->direita,b);

    }
    if(raiz->info>b)
    {
      raiz->esquerda=Insere(raiz->esquerda,b);

    }
   return raiz;
}

void Pre_Ordem (Tnoh *r)
{
   if (r != NULL)
    {
      if(r->direita!=NULL && r->esquerda!=NULL){
        printf ("%d [ %d %d ]\n",r->info,r->esquerda->info,r->direita->info);
      }
      if(r->direita==NULL && r->esquerda!=NULL){
        printf ("%d [ %d nulo ]\n",r->info,r->esquerda->info);
      }
      if(r->direita!=NULL && r->esquerda==NULL){
        printf ("%d [ nulo %d ]\n",r->info,r->direita->info);
      }
      if(r->direita==NULL && r->esquerda==NULL){
        printf ("%d [ nulo nulo ]\n",r->info);
      }

      Pre_Ordem(r->esquerda);
      Pre_Ordem(r->direita);

   }
}


void Ordem(Tnoh *r)
{
    if(r!=NULL)
    {
      Ordem(r->esquerda);
      printf("%d ",r->info);
      Ordem(r->direita);
    }


}

void Pos_Ordem(Tnoh *r)
{
     if(r!=NULL)
    {
      Pos_Ordem(r->esquerda);
      Pos_Ordem(r->direita);
      printf("%d ",r->info);

    }

}



void Consulta(Tnoh *raiz,int b)
{
    if(raiz==NULL){
        printf(" nao encontrado\n");
    }
    else{
        if(raiz->info==b){
            printf(" encontrado\n");
        }
        else{
            if(b<raiz->info){
                Consulta(raiz->esquerda,b);
            }
            else{
                Consulta(raiz->direita,b);
            }
        }
    }
}




void imprime(Tnoh *raiz)
{
    if(Raiz!=NULL)
    {
        printf ("%d\n", Raiz->info);

    }
}

Tnoh *Retira(Tnoh *raiz,int b)
{
    if(raiz == NULL)
    {
        return NULL;
    }
    else
    {
/////////////////////////////////////////////////////////////////////////
//PERCORRENDO A ÁRVORE CONFORME CONDIÇÃO DAS DIFERENÇAS
        if(b < raiz->info)
        {
            raiz->esquerda = Retira(raiz->esquerda,b);
        }
        else
        {
            if(b > raiz->info)
            {
                raiz->direita = Retira(raiz->direita,b);
            }

            else
            {
                if(raiz->esquerda == NULL && raiz->direita == NULL)//RETIRA QUANDO NÃO HÁ FILHOS
                {
                    free(raiz);
                    raiz = Inicializar();
                }
                else
                {
                    if(raiz->esquerda == NULL && raiz->direita!=NULL)//RETIRA QUANDO HÁ UM FILHO À DIREITA
                    {

                        Tnoh *temp=raiz;
                        raiz = raiz->direita;
                        free(temp);


                    }
                     if(raiz->direita == NULL && raiz->esquerda!=NULL)//RETIRA QUANDO HÁ UM FILHO À ESQUERDA
                    {

                        Tnoh *temp=raiz;
                        raiz = raiz->esquerda;
                        free(temp);

                    }


                    if(raiz->direita!=NULL && raiz->esquerda!=NULL && Raiz->info > b )//retira a esquerda com 2 filhos
                    {

                          Tnoh* temp=raiz;
                          raiz = raiz->esquerda;
                          raiz->direita= temp->direita;
                          raiz->esquerda=raiz->esquerda;
                          free(temp);
                    }
                    if(raiz->direita!=NULL && raiz->esquerda!=NULL && Raiz->info < b )//retira a direita com 2 filhos
                    {

                          Tnoh* temp=raiz;
                          raiz = raiz->direita;
                          raiz->esquerda= temp->esquerda;
                          raiz->direita=raiz->direita;
                          free(temp);
                    }

                }
            }
        }
        return raiz;
    }

}

Tnoh* Esvaziar(Tnoh *raiz)
{
    if (raiz!=NULL)
    {
        Esvaziar(raiz->direita);
        Esvaziar(raiz->esquerda);
        free(raiz);
    }
    return Raiz = Inicializar();
}

int Menu()
{
    int op;
    printf("1-Inicializa Arvore\n");
    printf("2-Cria Raiz Arvore\n");
    printf("3-Vazia(Arvore)\n");
    printf("4-Inserir item\n");
    printf("5-Pesquisa item\n");
    printf("6-Percorrer em Ordem\n");
    printf("7-Percorrer em Pre Ordem\n");
    printf("8-Percorre rem Pos Ordem\n");
    printf("9-Exclui um elemento\n");
    printf("10-Esvazia Arvore\n");
    printf("0-Sair\n");
    printf("digite sua opcao:\n");
    scanf("%d",&op);
    return op;

}


int main()
{

    int op=200;
    while(op!=0)
    {
        op=Menu();
        switch(op)
        {
       case 1:
            {
              system("cls");
              Raiz=Inicializar();
              printf("Arvore criada\n");
              break;
            }

       case 2:
           {
            system("cls");
            int b;
            printf("deseja o valor que deseja inserir na raiz:\n");
            scanf("%d",&b);
            Raiz=Cria_Raiz(b);
            break;
           }
       case 3:
           {
              system("cls");
               Vazia(Raiz);
              break;
           }
       case 4:
           {
               system("cls");
               int b;
               printf("deseja o valor que deseja inserir na arvore:\n");
               scanf("%d",&b);
               Insere(Raiz,b);
               break;
           }

       case 5:
           {
            system("cls");
            int b;
            printf("deseja o valor que deseja pesquisar na arvore:\n");
            scanf("%d",&b);
            Consulta(Raiz,b);
            break;
           }

       case 6:
           {
               system("cls");
               Ordem(Raiz);
               printf("\n");
               break;
           }



       case 7:
           {
               system("cls");
               Pre_Ordem(Raiz);
               printf("\n");
               break;
           }
       case 8:
        {
            system("cls");
            Pos_Ordem(Raiz);
            printf("\n");
            break;
        }

       case 9:
        {
            system("cls");
            int b;
            printf("deseja o valor que deseja excluir na arvore:\n");
            scanf("%d",&b);
            Retira(Raiz,b);
            break;

        }

       case 10:
        {
            //destruir

             Esvaziar(Raiz);
            printf("Arvore vazia");
        }

       case 0:
        {
            break;
        }
       default:
        {
            printf("Opcao invalida digite uma opcao valida.");
        }

      }
    }







    return 0;
}
