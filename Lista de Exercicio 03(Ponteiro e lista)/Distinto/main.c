#include <stdio.h>
#include <stdlib.h>

int main()
{
    int lista[5]={1,1,2,3,4};
    int i,j,aux=0;


    for(i=0;i<5;i++)
    {
        for(j=i+1;j<5;j++)
        {
            if(lista[i]==lista[j])
            {
                aux++;
                break;
            }
        }
    }
    if (5-aux == 1)
    {
        printf("Não a algarismos distintos");
    }
    else
    {

             printf("Distintos  %d",5-aux);
    }

    //printf("Distintos  %d",5-aux);
    return 0;

}
