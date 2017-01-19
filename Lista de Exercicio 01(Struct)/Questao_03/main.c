#include <stdio.h>
#include <stdlib.h>


struct Feriado
{
    int Destino;
    int Veiculo;

};

typedef struct Feriado TFer;


int Menu2()
{
    int OP;
    printf("Digite o destino da Viagem\n");
    printf("1 - Automovel\n");
    printf("2 - Caminhao\n");
    printf("3 - Onibus\n");
    printf("4 - Outros Veiculos\n");
    printf("Digite uma opcao\n");
    scanf("%d",&OP);
    return OP;
}


int Menu()
{
    int OP;
    printf("Digite o destino da Viagem\n");
    printf("1 - Camocim\n");
    printf("2 - Morro Branco\n");
    printf("3 - Aracati\n");
    printf("4 - Guaramiranga\n");
    printf("5 - Outro Destino\n");
    printf("Digite uma opcao\n");
    scanf("%d",&OP);
    return OP;
}



void Preenchendo_Lista(int aux,TFer Feriado[])
{
    int i;
    for(i=0;i<aux;i++)
    {
        Feriado[i].Destino=Menu();
        system("cls");
        Feriado[i].Veiculo=Menu2();
        system("cls");
    }
}



void Caminhao(int aux,TFer Feriado[])
{
    int i,cont=0,cont2=0;;
    for(i=0;i<aux;i++)
    {

        if(Feriado[i].Veiculo==2)
        {
            cont2++;
        }

        if(Feriado[i].Destino==1 && Feriado[i].Veiculo==2)
        {
            cont++;
        }
    }

    int media=(cont*1000)/(cont2*10);
    printf("A porcentagem de caminhoes com destino a Camocim eh: %0.1f %% \n\n",(float)media);


}



void Onibus(int aux,TFer Feriado[])
{
    int i,cont=0,cont2=aux;
    for(i=0;i<aux;i++)
    {
        if(Feriado[i].Veiculo==3)
        {
            cont++;
        }
    }

    int media=(cont*1000)/(cont2*10);
    printf("A porcentagem de onibus que passaram pela estrada eh: %f %%s \n\n",(float)media);

}



void AutoAracati(int aux,TFer Feriado[])
{
    int i,cont=0;
    for(i=0;i<aux;i++)
    {
        if(Feriado[i].Destino==3 && Feriado[i].Veiculo==1)
        {
            cont++;
        }
    }

    printf("o numero de Pessoas que foram a Aracati com automovel foi %d\n\n",cont);

}



void imprime(int aux,TFer Feriado[])
{
    int i;
    for(i=0;i<aux;i++)
    {
        printf("%d %d ",Feriado[i].Destino,Feriado[i].Veiculo);
    }
}

int main()
{
    int aux,i;
    printf("Numero de pessoas que deseja realizar o levantamento\n");
    scanf("%d",&aux);
    TFer Feriado[aux];
    Preenchendo_Lista(aux,Feriado);
    //imprime(aux,Feriado);
    AutoAracati(aux,Feriado);
    //Caminhao(aux,Feriado);
    Onibus(aux,Feriado);


    return 0;
}
