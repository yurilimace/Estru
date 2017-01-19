#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<string.h>
#include<locale.h>

struct Data
{
    int dia;
    int mes;
    int ano;
};

typedef struct Data TData;


struct Livro_Caixa
{
    char situacao;
    TData Data_lan;
    char tipo_lan;
    char historico[120];
    float valor;

};

typedef struct Livro_Caixa TLivro;


void preenchendo(int aux,TLivro Caixa[])
{
    int i,sorteio;
    for(i=0;i<aux;i++)
    {
       sorteio=rand()%2;
       Caixa[i].situacao='*';
       if(sorteio==0)
       {
           Caixa[i].situacao='X';
       }


       sorteio=rand()%3;
       Caixa[i].tipo_lan='D';
       if(sorteio==0)
       {
           Caixa[i].tipo_lan='R';
       }

       sorteio=1+rand()%30;
       Caixa[i].Data_lan.dia=sorteio;

       sorteio=1+rand()%12;
       Caixa[i].Data_lan.mes=sorteio;

       Caixa[i].Data_lan.ano=2005;

       float x=1+rand()%1000;
       Caixa[i].valor=x;

       strcpy(Caixa[i].historico,"Desc mov");




    }




}


void Calculo_Saldo(int aux,TLivro Caixa[])
{
    int i;
    float salant,somador=0,somador2=0;
    printf("Digite o saldo inical:\n");
    scanf("%f",&salant);
    for(i=0;i<aux;i++)
    {
        if((Caixa[i].tipo_lan=='D' || Caixa[i].tipo_lan=='d') && Caixa[i].Data_lan.mes==03 && Caixa[i].situacao=='x')
        {
            somador+=Caixa[i].valor;
        }
        if((Caixa[i].tipo_lan=='R' || Caixa[i].tipo_lan=='r') && Caixa[i].Data_lan.mes==03 && Caixa[i].situacao=='x')
        {
            somador2+=Caixa[i].valor;
        }
    }

    salant=salant+somador2-somador;
    printf("Saldo de marco eh :%0.2f\n",salant);


}







void Saldo(int aux,TLivro Caixa[],float sal)
{
   int i,cont=0;
    float somD=0,SomR=0;
    for(i=0;i<aux;i++)
    {
        if((Caixa[i].Data_lan.mes==03 && Caixa[i].Data_lan.ano==2005 && (Caixa[i].tipo_lan=='D'||Caixa[i].tipo_lan=='d')))
        {
                somD+=Caixa[i].valor;
        }

        if((Caixa[i].Data_lan.mes==03 && Caixa[i].Data_lan.ano==2005 && (Caixa[i].tipo_lan=='R'||Caixa[i].tipo_lan=='r')))
        {
               SomR+=Caixa[i].valor;
        }
    }

    printf("o saldo no mes de marco eh:%f",sal+SomR-somD);

}


void DispesaeReceita2005(int aux,TLivro Caixa[])
{
    int i,cont=0;
    float somD=0,SomR=0;
    for(i=0;i<aux;i++)
    {
        if((Caixa[i].Data_lan.ano==2005 && (Caixa[i].tipo_lan=='D'||Caixa[i].tipo_lan=='d')))
        {
                somD+=Caixa[i].valor;
        }

        if((Caixa[i].Data_lan.ano==2005 && (Caixa[i].tipo_lan=='R'||Caixa[i].tipo_lan=='r')))
        {
               SomR+=Caixa[i].valor;
        }
    }

    printf("A soma do total de lancamentos tipo receita eh :%0.2f\n",SomR);
    printf("A soma do total de lancamentos tipo Dispesa eh :%0.2f\n",somD);
    printf("A soma do total dispesa e receita em 2005 eh :%0.2f\n",SomR+somD);
    printf("\n\n\n");
}


void Janeiro(int aux,TLivro Caixa[])
{
    int i,cont=0;
    for(i=0;i<aux;i++)
    {
        if((Caixa[i].tipo_lan=='D' ||Caixa[i].tipo_lan=='d') && Caixa[i].Data_lan.mes==01
           && Caixa[i].Data_lan.ano==2005)
        {
            cont++;
        }
    }

    printf("o Numero de lancamentos do tipo dispesa em janeiro de 2005 eh %d\n\n\n\n\n",cont);
}




void Imprime(int aux,TLivro Caixa[])
{
    int i;
    printf("Situacao  Tipo    Data     Valor     Historico   \n");
    for(i=0;i<aux;i++)
    {
        printf(" %3c %7c   %d/%d/%d   %0.2f  %s    \n",Caixa[i].situacao,Caixa[i].tipo_lan,Caixa[i].Data_lan.dia,
               Caixa[i].Data_lan.mes,Caixa[i].Data_lan.ano,Caixa[i].valor,Caixa[i].historico);
    }
}







int Menu()
{
    int op;
    printf("1 - A quantidade de lancamentos do tipo despesa realizados no mes de janeiro de 2005\n");
    printf("2 - A soma dos lancamentos de despesa e de receita realizados no ano de 2005\n");
    printf("3 - O saldo (saldo anterior + receitas - despesas) do livro caixa no mes de marco de 2005\n");
    scanf("%d",&op);
    return op;
}


int main()
{



    srand(time(NULL));
    int aux,op=1;
    printf("Digite o numero de Lançamentos para teste:\n");
    scanf("%d",&aux);
    TLivro Caixa[aux];
    preenchendo(aux,Caixa);
    Imprime(aux,Caixa);



    while(op!=0)
    {

        switch(Menu())
        {
        case 1:
            {
             system("cls");
             Imprime(aux,Caixa);
             Janeiro(aux,Caixa);
             break;
            }
        case 2:
            {
                system("cls");
                Imprime(aux,Caixa);
                DispesaeReceita2005(aux,Caixa);
                break;
            }
        case 3:
            {
                system("cls");
                Imprime(aux,Caixa);
                Calculo_Saldo(aux,Caixa);
                break;
            }
        default:
            printf("Digite uma opcao valida");
        }
    }





    return 0;
}
