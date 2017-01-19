#include <stdio.h>
#include <stdlib.h>


struct Funcionario
{
char Nome[35];
char Sexo[2];
int producao;

};

typedef struct Funcionario TFun;


TFun CriaFuncionario()
{
    TFun Emp;
    printf("Digite o nome:\n");
    fflush(stdin);
    gets(Emp.Nome);
    printf("Digite o Sexo (M ou F):\n");
    fflush(stdin);
    gets(Emp.Sexo);
    printf("Digite o numero de peças produzidas pelo Funcionario\n");
    scanf("%d",&Emp.producao);
    return Emp;


}



void prodhomensemulheres(int aux,TFun Emp[])
{
    int i,j=0,cont=0,cont2=0;
    for(i=0;i<aux;i++)
    {
        if(Emp[i].Sexo[j]=='M')
        {
            cont+=Emp[i].producao;
        }
        else
        {
            cont2+=Emp[i].producao;
        }
    }

    printf("a producao total de homens foi: %d\n ",cont);
    printf("a producao total de mulheres foi: %d\n\n",cont2);

}


void maiorprod(int aux,TFun Emp[])
{
    int i,j,cont=0;
    for(i=0;i<aux;i++)
    {
        for(j=i+1;j<aux;j++)
            {
                if(Emp[i].producao<Emp[j].producao)
                {
                    TFun mes=Emp[i];
                    Emp[i]=Emp[j];
                    Emp[j]=mes;
                }
                if(Emp[i].producao==Emp[j].producao)
                {
                    cont++;
                }
            }

    }

    if(cont==0)
    {
        printf("Funcionario(a) do mes eh %s com producao de %d pecas\n\n\n",Emp[0].Nome,Emp[0].producao);
    }
    else
    {
        printf("nao houve Funcionario do (mes) pois houve empate entre os funcionarios");
    }


}






void Imprime_Lista(int aux,TFun Emp[])
{
    int i;
    for(i=0;i<aux;i++)
        {
            printf("%s %s %d \n",Emp[i].Nome,Emp[i].Sexo,Emp[i].producao);

        }

}



void Insere_Na_Lista(int aux,TFun Emp[])
{
    int i;
    for(i=0;i<aux;i++)
        {
            Emp[i]=CriaFuncionario();
            system("cls");
        }


}


int main()
{
    int aux;
    printf("Digite a quantidade de Funcionarios que deseja criar para teste\n");
    scanf("%d",&aux);
    TFun Lista_Fun[aux];
    Insere_Na_Lista(aux,Lista_Fun);
    Imprime_Lista(aux,Lista_Fun);
    prodhomensemulheres(aux,Lista_Fun);
    printf("\n\n\n\n");
    maiorprod(aux,Lista_Fun);

    return 0;



}
