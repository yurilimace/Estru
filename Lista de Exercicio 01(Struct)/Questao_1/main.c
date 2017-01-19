#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
struct Funcionario
{
char Nome[35];
int idade;
char Sexo[2];
char Exp[3];
};
typedef struct Funcionario TFun;

TFun CriaFuncionario()
{
    TFun Emp;
    printf("Digite o nome:\n");
    fflush(stdin);
    gets(Emp.Nome);
    printf("Digite a idade:\n");
    scanf("%d",&Emp.idade);
    printf("Digite o Sexo (M ou F):\n");
    fflush(stdin);
    gets(Emp.Sexo);
    printf("Digite se tem experencia na empresa:(Sim ou Nao)\n");
    gets(Emp.Exp);

    return Emp;


}



int HomensXMulheres(int aux,TFun Emp[])
{
    int i,cont=0,j=0;
    for(i=0;i<aux;i++)
        {
            //strcmp compara strings
            if(Emp[i].Sexo[j]=='M')
            {
                cont++;
            }

        }
    printf("\n");
    printf("o numero de Homens e igual a: %d\n",cont);
    printf("o numero de mulheres e igual a: %d\n",i-cont);
    return cont++;
}


void IdadeMedia(int aux,TFun Emp[])
{
    int i,j=0,cont=0,idade=0;
    for(i=0;i<aux;i++)
        {
            if(Emp[i].Sexo[j]=='M' && Emp[i].Exp[j]=='S')
                {
                    cont++;
                    idade+=Emp[i].idade;

                }

        }
        printf("\n");
        //printf("%d\n",cont);
        //printf("%d\n\n",idade);
        printf("A media de idade dos Homens com Experiencia acima de 45 anos eh: %d",idade/cont);
        printf("\n\n");


}



void MulhercomExp(int aux,TFun Emp[])
{
    int i,j=0,cont=0;
    for(i=0;i<aux;i++)
        {
            if(Emp[i].Sexo[j]=='F' && Emp[i].Exp[j]=='S' && Emp[i].idade<35 )
                {
                    cont++;


                }

        }
        printf("\n");
        printf("o numero de mulheres com idade maior que 35 anos e com experiencia eh: %d\n\n",cont);
}


void PorcentagemHomens(int aux,TFun Emp[])
{
    int i,j=0,cont=0;
      for(i=0;i<aux;i++)
        {
            if(Emp[i].Sexo[j]=='M' && Emp[i].idade>45)
            {
                cont++;

            }

        }

        printf("\n\n");
        int x=HomensXMulheres(aux,Emp);
        float d=(cont*1000)/(x*10);
        //printf("%f",d);
        printf("A porcentagem de Homens que tem idade maior que 45 anos eh %0.1f%%\n\n\n",(float)d);

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



void Imprime_Lista(int aux,TFun Emp[])
{
    int i;
    for(i=0;i<aux;i++)
        {
            printf("%s %d %s %s \n",Emp[i].Nome,Emp[i].idade,Emp[i].Sexo,Emp[i].Exp);

        }

}

void Imprime(TFun Emp)
{
    printf("%s %d %s %s",Emp.Nome,Emp.idade,Emp.Sexo,Emp.Exp);

}



int Menu()
{
    int op;
    printf("1- Numero de candidatos do Sexo Masculino e Feminino\n");
    printf("2- Idade Media dos Homens que tem experiencia no servico\n");
    printf("3- A porcentagem dos homens com mais de 45 anos entre o total de homens\n");
    printf("4- O número de mulheres que têm idade inferior a 35 anos e comexperiência no serviço\n");
    printf("0- para sair");
    printf("\n Digite sua opccao:\n");
    scanf("%d",&op);
    return op;


}



int main()
{
   int aux,op=200;
   printf("Digite a quantidade de Funcionarios que deseja criar para teste\n");
   scanf("%d",&aux);
   TFun Lista_Fun[aux];
   Insere_Na_Lista(aux,Lista_Fun);


   while(op!=0)
   {
       //system("cls");
       op=Menu();
       switch(op)
        {
       case 1:
            {
              system("cls");
              Imprime_Lista(aux,Lista_Fun);
              HomensXMulheres(aux,Lista_Fun);
              break;
            }

       case 2:
           {
            system("cls");
            Imprime_Lista(aux,Lista_Fun);
            IdadeMedia(aux,Lista_Fun);
            break;
           }
       case 3:
           {
              system("cls");
              Imprime_Lista(aux,Lista_Fun);
              PorcentagemHomens(aux,Lista_Fun);
              break;
           }
       case 4:
           {
              system("cls");
              Imprime_Lista(aux,Lista_Fun);
              MulhercomExp(aux,Lista_Fun);
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
