#include <stdio.h>
#include <stdlib.h>
#define tam 10
int main()
{
    int i,edades[tam],contador0_18=0,contador19_35=0,contador36_o_mas=0,mayor,flag=0;

    for(i=0; i<tam; i++)
    {
        printf("ingrese edad %d:",i+1);
        scanf("%d", &edades[i]);
        if(edades[i]<19)
        {
            contador0_18++;
        }
        else
        {
            if(edades[i]<36)
            {
                contador19_35++;
            }
            else
            {
                contador36_o_mas++;
            }
        }
    }
    if(contador0_18 >= contador19_35 && contador0_18 >= contador36_o_mas)
    {
        mayor=contador0_18;
    }
    else
    {
        if(contador19_35 >= contador0_18 && contador19_35 >= contador36_o_mas)
        {
            mayor=contador19_35;
        }
        else
        {
            mayor=contador36_o_mas;
        }
    }
        for(i=mayor; i>0; i--)
        {
            if(i<=contador0_18)
            {
                printf("*");
            }
            if(i<=contador19_35)
            {
                printf("\t*");
                flag=1;
            }
            if(i<=contador36_o_mas)
            {
                if(flag==0)
                {
                    printf("\t\t*");
                }
                else
                {
                    printf("\t*");
                }
            }
            printf("\n");
        }
        printf("<18\t19-35\t>35");





    /*
        int i,rango1=13,rango2=5,rango3=11,flag2=0,mayor,edades[tam];
        if(rango1 >= rango2  && rango1>=rango3 )
        {
            mayor=rango1;
        }
        else
        {
            if (rango2>=rango1 && rango2>=rango3)
            {
                mayor=rango2;
            }
            else
            {
                mayor=rango3;
            }
        }
        for(i=mayor;i>0;i--)
        {
            if(i<=rango1)
            {
                printf("*");
                //flag1=1;
            }
            if(i<=rango2)
            {
                printf("\t*");
                flag2=1;
            }
            if(i<=rango3)
            {
                if(flag2==0)
                {
                    printf("\t\t*");
                }
                if(flag2==1)
                {
                    printf("\t*");
                }

            }
            printf("\n");

        }
        printf("<18\t19-35\t>35");
        return 0;
    }

    */
    return 0;
}
