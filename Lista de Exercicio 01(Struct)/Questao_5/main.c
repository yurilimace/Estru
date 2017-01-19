#include <stdio.h>
#include <stdlib.h>

struct Moradores
{
    int sexo;
    int Estado_civil;
    int idade;
    float renda;

};

typedef struct Moradores TMor;


float Menu4()
{
    float op;
    printf("Digite sua Renda Anual:\n");
    scanf("%f",&op);
    return op;
}




int Menu3()
{
    int op;
    printf("Digite sua idade:\n");
    scanf("%d",&op);
    return op;

}


int Menu2()
{
    int op;
    printf("0 - Solteiro\n");
    printf("1 - Casado\n");
    printf("2 - Viuvo\n");
    printf("3 - Divorciado\n");
    printf("Escolha seu Estado Civil:\n");
    scanf("%d",&op);
    return op;

}




int Menu()
{
    int op;
    printf("1 - Masculino\n");
    printf("2 - Feminino\n");
    printf("Escolha seu sexo:\n");
    scanf("%d",&op);
    return op;

}


void Preenchendo_Lista(int aux,TMor Moradores[])
{
    int i;
    for(i=0;i<aux;i++)
    {
        Moradores[i].sexo=Menu();
        system("cls");
        Moradores[i].Estado_civil=Menu2();
        system("cls");
        Moradores[i].idade=Menu3();
        system("cls");
        Moradores[i].renda=Menu4();
        system("cls");
    }
}

void HomensXMulheres(int aux,TMor Moradores[])
{
    int i,cont=0;
    for(i=0;i<aux;i++)
    {
        if(Moradores[i].sexo==1)
            {
                cont++;
            }
    }

    printf("O numero de Homens eh: %d \n",cont);
    printf("O numero de Mulheres eh: %d \n",aux-cont);
}

void Solteiras(int aux,TMor Moradores[])
{
    int i,cont=0;
    for(i=0;i<aux;i++)
    {
        if(Moradores[i].sexo==2 && Moradores[i].Estado_civil==0)
        {
            cont++;
        }
    }

    printf("O numero de Mulheres solteiras eh: %d\n\n",cont);
}


void Porcentagem(int aux,TMor Moradores[])
{
    int i,cont=0,cont2=0;
    for(i=0;i<aux;i++)
    {

        if(Moradores[i].sexo==1)
        {
            cont++;
        }

        if(Moradores[i].sexo==1 && Moradores[i].Estado_civil==3)
        {
            cont2++;
        }
    }


    int por=(cont2*1000)/(cont*10);
    printf("A porcentagem de Homens divorciados eh: %0.1f \n\n",(float)por);



}


void RendaMulheres(int aux,TMor Moradores[])
{
     int i,cont=0;
     float somador=0;
    for(i=0;i<aux;i++)
    {

        if(Moradores[i].sexo==2 && Moradores[i].idade>=20 && Moradores[i].idade<=40)
        {
            somador+=Moradores[i].renda;
            cont++;
        }
    }

    if(cont>0)
    {
        printf("A renda anual media das mulheres entre 20 e 40 Anos  eh: %f \n\n",somador/(float)cont);
    }
    else
    {
        printf("A renda anual media das mulheres entre 20 e 40 Anos  eh: 0");
    }
}



int main()
{
    int aux;
    printf("Digite o numero de Moradores que Responderam a Pesquisa:\n");
    scanf("%d",&aux);
    TMor Moradores[aux];
    Preenchendo_Lista(aux,Moradores);
    HomensXMulheres(aux,Moradores);
    Porcentagem(aux,Moradores);
    RendaMulheres(aux,Moradores);
    return 0;
}
