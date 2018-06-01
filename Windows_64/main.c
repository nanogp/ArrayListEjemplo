#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"
#include "d:\github\TP3\TP3\General.h"
#include "d:\github\TP3\TP3\General.c"

/****************************************************
    Menu:
        1. Parse del archivo data.csv
        2. Listar Empleados
        3. Ordenar por nombre
        4. Agregar un elemento
        5. Elimina un elemento
        6. Listar Empleados (Desde/Hasta)
*****************************************************/

int charToInt(char* cadena)
{
   int retorno = NULL;

   sprintf(cadena, "%d", retorno);

   return retorno;
}

int charToIsEmpty(char* cadena)
{
    int retorno = OCCUPY;

    if(stricmp(cadena,TRUE) == EMPTY)
    {
        retorno = EMPTY;
    }

    return retorno;
}

int main()
{
    ArrayList* empleados;
    Employee unEmpleado;
    char auxId[10];
    char auxIsEmpty[10];
    FILE* pArchivo;

    empleados = al_newArrayList();

    pArchivo = fopen("data.csv", "r");
    if(pArchivo == NULL)
    {
        printf("\nNo se pudo abrir el archivo");
    }
    else
    {
        //primera falsa lectura
        fscanf(pArchivo, "%[^,],%[^,],%[^,],%[^\n]\n", auxId, (char*)&unEmpleado.name, (char*)&unEmpleado.lastName, auxIsEmpty);

        do
        {
            fscanf(pArchivo, "%[^,],%[^,],%[^,],%[^\n]\n", auxId, (char*)&unEmpleado.name, (char*)&unEmpleado.lastName, auxIsEmpty);

            employee_setId(&unEmpleado, charToInt(auxId));
            employee_setIsEmpty(&unEmpleado, charToIsEmpty(auxIsEmpty));

            al_add(empleados, &unEmpleado);

        }while(!feof(pArchivo));
    }
    fclose(pArchivo);

    for(int i=0 ; i<al_len(empleados);i++)
    {
        employee_print(al_get(empleados,i));
        //printf(" i:%d",i);
    }

    return 0;
}
