/**************************** INCLUSION DE LIBRERIAS PERSONALES **********************************/
#include "Parser.h"
#include "ArrayList.h"
#include "Employee.h"
#include "Archivo.h"
/**************************** INCLUSION DE LIBRERIAS ESTANDAR ************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**************************** GESTION DE DATOS ***************************************************/
int charToIsEmpty(char* texto)
{
    int retorno = EMPLOYEE_OCCUPIED;

    if(stricmp(texto,TRUE) == 0)
    {
        retorno = EMPLOYEE_EMPTY;
    }
    else
    {
       retorno = EMPLOYEE_OCCUPIED;
    }

    return retorno;
}
//-----------------------------------------------------------------------------------------------//
int parserEmployee(FILE* pFile, ArrayList* pArrayListEmployee)
{
   int returnAux = -1;
   eEmployee* auxEmpleado;
   char auxId[10];
   char auxName[EMPLOYEE_LARGO_NAME];
   char auxLastName[EMPLOYEE_LARGO_LAST_NAME];
   char auxIsEmpty[10];

   if(pArrayListEmployee != NULL)
   {
      returnAux = 0;
      auxEmpleado = eEmployee_new();

      //primera falsa lectura para saltear las cabeceras del archivo
      fscanf(pFile, EMPLOYEE_PARSE_MASK, auxId, auxName, auxLastName, auxIsEmpty);

      while(!feof(pFile))
      {
         auxEmpleado = eEmployee_new();

         fscanf(pFile, EMPLOYEE_PARSE_MASK, auxId, auxName, auxLastName, auxIsEmpty);

         if(feof(pFile)) break; //por bug de fin de archivo que repite ultima lectura


         eEmployee_setId(auxEmpleado, charToInt(auxId));
         eEmployee_setName(auxEmpleado, auxName);
         eEmployee_setLastName(auxEmpleado, auxLastName);
         eEmployee_setIsEmpty(auxEmpleado, charToIsEmpty(auxIsEmpty));

         al_add(pArrayListEmployee, auxEmpleado);

      }
   }
   return returnAux;
}
//-----------------------------------------------------------------------------------------------//
void eEmployee_gestionParsear(ArrayList* this)
{
   FILE* pArchivo;

   limpiarPantallaYMostrarTitulo(EMPLOYEE_PARSEO_TITULO);

   pArchivo = eArchivoTexto_abrir(ARCHIVO_TEXTO_NOMBRE);
   if(pArchivo != NULL)
   {
      parserEmployee(pArchivo, this);
      eArchivoTexto_cerrar(pArchivo);
      printf(PARSER_OK_MASK, al_len(this));
   }
   else
   {
      imprimirEnPantalla("\nNo se pudo abrir el archivo");
   }
   pausa();

}
