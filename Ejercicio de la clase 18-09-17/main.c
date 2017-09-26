#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM_C 10
#define TAM_I 5
/*
    ACTIVIDAD: 1)Harcodeo de datos X
               2)Mostrar:
               a)Todos los interpretes X
               b)Todas las canciones X
               c)Todas las canciones con el nombre del interprete X
               d)Todas las canciones de interpretes Argentinos X
               e)Por c/d interprete todos sus temas X
*/

typedef struct
{
    int id; //PRIMARY KEY
    char nombre[30];
    char nacionalidad[25];
} eInterprete;

typedef struct
{
    int idCancion; //PRIMARY KEY
    char titulo[40];
    int interprete; //FOREING KEY ---> id eInterprete
    int duracion;
} eCancion;

void harcodearInterpretes(eInterprete[], int);
void harcodearCanciones(eCancion[], int);
void listarInterpretes(eInterprete[], int);
void listarCanciones(eCancion[], eInterprete[], int, int);
void listarCancionesDeInterArg(eCancion[], eInterprete[], int, int);
void listarInterpretesConSusTemas(eCancion[], eInterprete[], int, int);
void duracionXInterprete(eCancion [], int, eInterprete[], int );
void maxCanciones(eCancion [],int,eInterprete [],int);

int main()
{
    eInterprete interprete[TAM_I];
    eCancion cancion[TAM_C];

    printf("\t\t\t\tSPOTIFY\n\t\t\t-----------------------");

    harcodearInterpretes(interprete, TAM_I);
    harcodearCanciones(cancion, TAM_C);

    listarInterpretes(interprete, TAM_I);
    printf("*************************************************************");
    listarCanciones(cancion, interprete, TAM_C, TAM_I);
    printf("*************************************************************");
    listarCancionesDeInterArg(cancion, interprete, TAM_C, TAM_I);
    printf("*************************************************************");
    listarInterpretesConSusTemas(cancion, interprete, TAM_C, TAM_I);
    printf("*************************************************************\n");
    duracionXInterprete(cancion,TAM_C,interprete,TAM_I);
    printf("*************************************************************\n");
    maxCanciones(cancion,TAM_C,interprete,TAM_I);
    return 0;
}

void harcodearInterpretes(eInterprete interpretes[], int tam)
{
    int IdInterpretes[5] = {1001, 1002, 1003, 1004, 1005};
    char Nombre[5][30] = {"Carlos","Henry","Pablo","Matias","Rodrigo"};
    char Nacionalidad[5][35] = {"Uruguayo","Paraguayo","Argentino","Colombiano","Aleman"};

    int i;
    for(i=0; i<tam; i++)
    {
        interpretes[i].id = IdInterpretes[i];
        strcpy(interpretes[i].nombre, Nombre[i]);
        strcpy(interpretes[i].nacionalidad, Nacionalidad[i]);
    }
}

void harcodearCanciones(eCancion canciones[], int tam)
{
    int IdCancion[10] = {101, 102, 103, 104, 105, 106, 107, 108, 109, 110};
    char Titulo[10][50] = {"cancion1","cancion2","cancion3","cancion4","cancion5","cancion6","cancion7","cancion8","cancion9","cancion10"};
    int Interprete[10] = {1003, 1002, 1004, 1004, 1001, 1003, 1002, 1001, 1003, 1004};
    int Duracion[10] = {3, 4, 1, 4, 3, 2, 5, 5, 2,5};

    int i;
    for(i=0; i<tam; i++)
    {
        canciones[i].idCancion = IdCancion[i];
        strcpy(canciones[i].titulo, Titulo[i]);
        canciones[i].interprete = Interprete[i];
        canciones[i].duracion = Duracion[i];
    }

}

void listarInterpretes(eInterprete interpretes[], int tam)
{
    int i;
    printf("\nINTERPRETES\n\nID\tNOMBRE\tNACIONALIDAD\n");
    for(i=0; i<tam; i++)
    {
        printf("%d\t%s\t%s\n", interpretes[i].id, interpretes[i].nombre, interpretes[i].nacionalidad);
    }

}

void listarCanciones(eCancion canciones[], eInterprete interpretes[], int tam_c, int tam_i)
{
    int i, j;
    printf("\nCANCIONES\n\nIDCANCION\tTITULO\t\tINTERPRETE\tDURACION\n");
    for(i=0; i<tam_c; i++)
    {
        printf("%d\t\t%s\t%d\t\t%d\n", canciones[i].idCancion, canciones[i].titulo, canciones[i].interprete, canciones[i].duracion);
    }

    printf("*****************************************************\nCANCIONES CON INTERPRETE\n\nIDCANCION\tTITULO\t\tINTERPRETE\tDURACION\n");
    for(i=0; i<tam_c; i++)
    {
        for(j=0; j<tam_i; j++)
        {
            if(canciones[i].interprete == interpretes[j].id)
            {
                printf("%d\t\t%s\t%s\t\t%d Minutos\n", canciones[i].idCancion, canciones[i].titulo, interpretes[j].nombre, canciones[i].duracion);
            }
        }
    }
}

void listarCancionesDeInterArg(eCancion canciones[], eInterprete interpretes[], int tam_c, int tam_i)
{
    int i, j;
    printf("\nCANCIONES DE INTERPRETES ARGENTINOS\n\nIDCANCION\tTITULO\t\tINTERPRETE\tDURACION\n");
    for(i=0; i<tam_c; i++)
    {
        for(j=0; j<tam_i; j++)
        {
            if(strcmp(interpretes[j].nacionalidad, "Argentino") == 0 && interpretes[j].id == canciones[i].interprete)
            {
                printf("%d\t\t%s\t%s\t\t%d Minutos\n", canciones[i].idCancion, canciones[i].titulo, interpretes[j].nombre, canciones[i].duracion);
            }
        }
    }
}

void listarInterpretesConSusTemas(eCancion canciones[], eInterprete interpretes[], int tam_c, int tam_i)
{
    int i, j;
    printf("\nINTERPRETE CON SUS TEMAS\n\n");
    for(j=0; j<tam_i; j++)
    {
        printf("%s\n", interpretes[j].nombre);
        for(i=0; i<tam_c; i++)
        {
            if(canciones[i].interprete == interpretes[j].id)
            {
                //printf("%s\t\t%d\t\t%s\t%d Minutos\n", interpretes[j].nombre, canciones[i].idCancion, canciones[i].titulo, canciones[i].duracion);
                printf("\n%s\n", canciones[i].titulo);
            }
        }
    }

    /*   int i, j;

       for(i=0; i<tam_i; i++)
       {
           printf("\n%s\n", interpretes[i].nombre);

           for(j=0; j<tam_c; j++)
           {
               if(canciones[j].interprete == interpretes[i].id)
               {
                   printf("\n%s\n", canciones[j].titulo);
               }

           }

       }*/
}

void duracionXInterprete(eCancion listaCanciones[],int tam_c,eInterprete listaInterpretes[],int tam_i)
{
    int i,j,verificacion=0;
    int acumuladorTiempo;
    char auxChar[50];
    listarInterpretes(listaInterpretes, tam_i);
    do
    {
        printf("\nIngrese nombre del interprete p/ determinar la duracion:");
        fflush(stdin);
        gets(auxChar);
        for(i=0; i<tam_i; i++)
        {
            //hasta aca llega
            if(stricmp(listaInterpretes[i].nombre,auxChar)==0)
            {
                acumuladorTiempo=0;
                printf("%s-->",listaInterpretes[i].nombre);

                for(j=0; j<tam_c; j++)
                {
                    if(listaCanciones[j].interprete==listaInterpretes[i].id)
                    {
                        acumuladorTiempo+=listaCanciones[j].duracion;

                    }
                }
                printf("duracion:%d\n",acumuladorTiempo);
                verificacion=1;
            }
        }

    }
    while(verificacion==0);

}

void maxCanciones(eCancion listaCanciones[],int tam_c,eInterprete listaInterpretes[],int tam_i)
{

    int i,j,flag=0;
    int maximos;
    int contadorCanciones[tam_i];
    for(i=0; i<tam_i; i++)
    {
        contadorCanciones[i]=0;
    }
    for(i=0; i<tam_i; i++)
    {
        for(j=0; j<tam_c; j++)
        {
            if(listaCanciones[j].interprete==listaInterpretes[i].id)
            {
                contadorCanciones[i]++;


            }
        }

    }//cargo los contadores de canciones
    for(i=0; i<tam_i; i++)
    {
        if(flag==0)
        {
            maximos=contadorCanciones[i];
            flag=1;
        }
        if(maximos<contadorCanciones[i])
        {
            maximos=contadorCanciones[i];
        }

    }
    for(i=0;i<tam_i;i++)
    {
        if(contadorCanciones[i]==maximos)
        {
             printf("\nArtista con mas canciones:%s-->%d\n",listaInterpretes[i].nombre,contadorCanciones[i]);
        }
    }

}
