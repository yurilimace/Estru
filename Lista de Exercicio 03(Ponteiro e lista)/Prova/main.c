#include <stdio.h>
#include <stdlib.h>


int Soma(int a,int b)
{
    //int somador=a;
    if(b == a+1)
    {
        return 0;
    }
    else
    {


        a++;
        //printf("A %d  somador %d \n",a,somador);
        return a+Soma(a,b);

    }

}



int main()
{
    int x=Soma(1,5);
    printf("%d\n",x);
    return 0;
}
