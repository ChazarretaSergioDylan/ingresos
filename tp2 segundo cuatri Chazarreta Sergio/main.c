#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define C 20



typedef struct
{
    char nombre[40];
    int estado;
    int edad;
    int dni;
} eIndividuo;
void inicializarIndiv(eIndividuo[],int);
eIndividuo crearIndividuo(char[],int,int);
void mostrarPersona(eIndividuo[],int);
void mostrarGente(eIndividuo);
void ordenarPersona(eIndividuo[],int);
int buscarEspacio(eIndividuo[],int);



int main()
{
    eIndividuo gente[C];
    inicializarIndiv(gente,C);
    char seguir='s';
    int opcion,posicion,flagCapacidad,auxInt,flagExiste=0;
    char nombre[30],respuesta;
    int dni, edad;




    while(seguir=='s')
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            flagCapacidad=0;
            posicion= buscarEspacio(gente,C);
            if(posicion!=-1)
            {
                printf("1.Agregar persona:\n");
                printf("Ingrese DNI: \n");
                scanf("%d",&dni);
                printf("Ingrese nombre\n");
                fflush(stdin);
                gets(nombre);
                printf("Ingrese edad: \n");
                scanf("%d",&edad);

                gente[posicion]=crearIndividuo(nombre,edad,dni);
                mostrarGente(gente[posicion]);
                system("pause");
                system("cls");
            }
            else
            {
                printf("no hay espacio para mas personas.\n");
                system("pause");
                system("cls");
            }
            break;
        case 2:
            flagCapacidad=0;
            printf("ingrese dni de la persona que desea dar de baja: \n");
            scanf("%d",&auxInt);
            int i;
            for(i=0; i<C; i++)
            {
                if(gente[i].estado==1 &&auxInt == gente[i].dni)
                {

                    flagExiste=1;
                    mostrarGente(gente[i]);

                    printf("Esta seguro de dar de baja? s/n\n");
                    respuesta = getche();
                    if(respuesta=='s'&&flagCapacidad==0)
                    {
                        gente[i].estado=0;
                        printf("dado de baja exitoso.\n");
                        system("pause");
                        system("cls");
                    }
                    else
                    {
                        printf("Accion cancelada por el usuario.\n");
                        system("pause");
                        system("cls");
                    }
                    flagCapacidad=1;
                    break;
                }


            }
            if(flagExiste==0)
                {
                    printf("no se encontro el dni.\n");
                }
            break;
        case 3:
            ordenarPersona(gente,C);
            mostrarPersona(gente,C);
            system("pause");
            system("cls");
            break;
        case 4:

            break;
        case 5:
            seguir = 'n';
            break;
        }
    }
    return 0;
}



eIndividuo crearIndividuo(char nombre[],int edad,int dni)
{
    eIndividuo persona;
    persona.dni=dni;
    persona.edad=edad;
    strcpy(persona.nombre,nombre);
    persona.estado=1;
    return persona;
}
void inicializarIndiv(eIndividuo indiv[],int tam )
{
    int i;
    for(i=0; i<tam; i++)
    {
        indiv[i].estado=0;
    }

}
void ordenarPersona(eIndividuo indiv[],int tam )
{
    int i,j;
    eIndividuo auxiliarIndiv;
    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(strcmp(indiv[i].nombre,indiv[j].nombre)>0)
            {
                auxiliarIndiv=indiv[i];
                indiv[i]=indiv[j];
                indiv[j]=auxiliarIndiv;
            }
        }
    }
}
void mostrarPersona(eIndividuo individuos[],int tam )
{
    int i;
    for(i=0; i<tam; i++)
    {
        if(individuos[i].estado!=0)
        {
            mostrarGente(individuos[i]);
        }
    }
}
void mostrarGente(eIndividuo indiv)
{
    printf("\n dni: %d\tnombre: %s\tedad:%d\n",indiv.dni,indiv.nombre,indiv.edad);
}
int  buscarEspacio(eIndividuo indiv[],int tam)
{
    int lugar=-1;
    int i;
    for(i=0; i<tam; i++)
    {
        if(indiv[i].estado==0)
        {
            lugar=i;
            break;
        }
    }
    return lugar;
}


