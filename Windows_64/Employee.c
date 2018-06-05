/**************************** INCLUSION DE LIBRERIAS PERSONALES **********************************/
#include "ArrayList.h"
#include "Employee.h"
/**************************** INCLUSION DE LIBRERIAS ESTANDAR ************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**************************** BUSQUEDA ***********************************************************/
int eEmployee_estaVacio(ArrayList* this)
{
   int returnAux = 1;

   for(int i=0 ; i<al_len(this); i++)
   {
      if(eEmployee_getIsEmpty(al_get(this,i)) == EMPLOYEE_OCCUPIED)
      {
         returnAux = 0;
         break;
      }
   }

   return returnAux;
}
//-----------------------------------------------------------------------------------------------//
int eEmployee_informarListadoVacio(ArrayList* this)
{
   int returnAux = -1;

   if(this != NULL)
   {
      returnAux = eEmployee_estaVacio(this);

      if(returnAux == 1)
      {
         imprimirEnPantalla(EMPLOYEE_MSJ_LISTA_VACIA);
      }
   }

   return returnAux;
}
//-----------------------------------------------------------------------------------------------//
int eEmployee_nextId(ArrayList* this)
{
   eEmployee* unEmpleado;
   int id = 1;

   for(int i=0; i<al_len(this); i++)
   {
      unEmpleado = al_get(this,i);

      if(eEmployee_getIsEmpty(unEmpleado) == EMPLOYEE_OCCUPIED && eEmployee_getId(unEmpleado) > id)
      {
         id = eEmployee_getId(unEmpleado);
      }
   }

   return (id++);
}
//-----------------------------------------------------------------------------------------------//


/**************************** GET Y SET **********************************************************/
int eEmployee_getId(eEmployee* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
        returnAux = this->id;
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
int eEmployee_getIsEmpty(eEmployee* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
        returnAux = this->isEmpty;
    }
    return returnAux;
}//-----------------------------------------------------------------------------------------------//
char* eEmployee_getIsEmptyLegend(eEmployee* this)
{
    char* returnAux = NULL;

    returnAux = (char*)malloc(sizeof(char)*10);

    if(this != NULL && returnAux != NULL)
    {
        if(eEmployee_getIsEmpty(this) == EMPLOYEE_EMPTY)
        {
            strcpy(returnAux, EMPLOYEE_EMPTY_LEGEND);
        }
        else
        {
           strcpy(returnAux, EMPLOYEE_OCCUPIED_LEGEND);
        }
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
char* eEmployee_getName(eEmployee* this)
{
    char* returnAux = NULL;
    if(this != NULL)
    {
        returnAux = this->name;
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
char* eEmployee_getLastName(eEmployee* this)
{
    char* returnAux = NULL;
    if(this != NULL)
    {
        returnAux = this->lastName;
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
int eEmployee_setId(eEmployee* this, int id)
{
    int returnAux = -1;
    if(this != NULL)
    {
        returnAux = 0;
        this->id = id;
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
int eEmployee_setIsEmpty(eEmployee* this, int isEmpty)
{
    int returnAux = -1;
    if(this != NULL)
    {
        returnAux = 0;
        this->isEmpty = isEmpty;
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
int eEmployee_setName(eEmployee* this, char* name)
{
    int returnAux = -1;
    if(this != NULL)
    {
        returnAux = 0;
        strcpy(this->name, name);
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
int eEmployee_setLastName(eEmployee* this, char* lastName)
{
    int returnAux = -1;
    if(this != NULL)
    {
        returnAux = 0;
        strcpy(this->lastName, lastName);
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//

/**************************** ENTRADA DE DATOS ***************************************************/
eEmployee* eEmployee_new(void)
{
    eEmployee* returnAux = NULL;

    returnAux = (eEmployee*)malloc(sizeof(eEmployee));

    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
eEmployee* eEmployee_newParam(int id, char* name, char* lastName, int isEmpty)
{
    eEmployee* returnAux;

    returnAux = eEmployee_new();

    eEmployee_setId(returnAux,id);
    eEmployee_setIsEmpty(returnAux,isEmpty);
    eEmployee_setName(returnAux,name);
    eEmployee_setLastName(returnAux,lastName);

    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
int eEmployee_pedirId()
{
   return pedirIntValido(EMPLOYEE_MSJ_INGRESE_ID, EMPLOYEE_MSJ_REINGRESE_ID, EMPLOYEE_ID_MIN, EMPLOYEE_ID_MAX);
}
//-----------------------------------------------------------------------------------------------//
char* eEmployee_pedirName()
{
   char* returnAux = (char*)malloc(sizeof(char)*EMPLOYEE_LARGO_NAME);

   pedirStringValido(returnAux, EMPLOYEE_MSJ_INGRESE_NOMBRE, EMPLOYEE_MSJ_REINGRESE_NOMBRE, EMPLOYEE_LARGO_NAME);

   return returnAux;
}
//-----------------------------------------------------------------------------------------------//
char* eEmployee_pedirLastName()
{
   char* returnAux = (char*)malloc(sizeof(char)*EMPLOYEE_LARGO_LAST_NAME);

   pedirStringValido(returnAux, EMPLOYEE_MSJ_INGRESE_APELLIDO, EMPLOYEE_MSJ_REINGRESE_APELLIDO, EMPLOYEE_LARGO_LAST_NAME);

   return returnAux;
}
//-----------------------------------------------------------------------------------------------//
eEmployee* eEmployee_pedirIngreso(ArrayList* this)
{
   eEmployee* unEmpleado;

   unEmpleado = eEmployee_new();

   eEmployee_setId(unEmpleado, eEmployee_nextId(this));

   eEmployee_setName(unEmpleado, eEmployee_pedirName());

   eEmployee_setLastName(unEmpleado, eEmployee_pedirLastName());

   eEmployee_setIsEmpty(unEmpleado, EMPLOYEE_OCCUPIED);

   return unEmpleado;
}
//-----------------------------------------------------------------------------------------------//

/**************************** LISTADO DE DATOS ***************************************************/
void eEmployee_print(eEmployee* this)
{
   printf(EMPLOYEE_PRINT_MASK, this->id, this->name, this->lastName, eEmployee_getIsEmptyLegend(this));
}
//-----------------------------------------------------------------------------------------------//
void eEmployee_printList(ArrayList* this, int pageSize)
{
   eEmployee* empleado;
   int contador = 0;

   imprimirEnPantalla(EMPLOYEE_PRINT_MASK_CABECERA);

   for(int i=0 ; i<al_len(this) ; i++)
   {
      empleado = al_get(this,i);

      if(eEmployee_getIsEmpty(empleado) != EMPLOYEE_EMPTY)
      {
         eEmployee_print(empleado);
         contador++;

         if(contador%pageSize == 0)
         {
            pausa();
            imprimirEnPantalla(EMPLOYEE_PRINT_MASK_CABECERA);
         }
      }
   }
}
//-----------------------------------------------------------------------------------------------//
void eEmployee_printListWithEmpty(ArrayList* this)
{
   eEmployee* empleado;
   int contador = 0;

   limpiarPantallaYMostrarTitulo(EMPLOYEE_LISTADO_TITULO);
   imprimirEnPantalla(EMPLOYEE_PRINT_MASK_CABECERA);

   for(int i=0 ; i<al_len(this) ; i++)
   {
      empleado = al_get(this,i);

      eEmployee_print(empleado);
      contador++;

      if(contador%EMPLOYEE_PRINT_PAGESIZE == 0)
      {
         pausa();
         limpiarPantallaYMostrarTitulo(EMPLOYEE_LISTADO_TITULO);
         imprimirEnPantalla(EMPLOYEE_PRINT_MASK_CABECERA);
      }
   }
}
//-----------------------------------------------------------------------------------------------//


/**************************** ALTA DE REGISTRO ***************************************************/
int eEmployee_gestionAlta(ArrayList* this)
{
   int returnAux = -1;
   eEmployee* registro;
   char confirmacion;

   if(this != NULL)
   {
      returnAux = 0;
      limpiarPantallaYMostrarTitulo(EMPLOYEE_ALTA_TITULO);

      registro = eEmployee_pedirIngreso(this);

      limpiarPantallaYMostrarTitulo(EMPLOYEE_ALTA_TITULO);
      imprimirEnPantalla(EMPLOYEE_PRINT_MASK_CABECERA);
      eEmployee_print(registro);

      confirmacion = pedirConfirmacion(MSJ_CONFIRMA_CORRECTOS);

      if(confirmacion == 'S')
      {
         al_add(this, registro);
         imprimirEnPantalla(EMPLOYEE_MSJ_ALTA_OK);
      }
      else
      {
         imprimirEnPantalla(MSJ_CANCELO_GESTION);
      }
      pausa();
   }
   return returnAux;
}
//-----------------------------------------------------------------------------------------------//


/**************************** BAJA DE REGISTRO ****************************************************/
int eEmployee_gestionBaja(ArrayList* this)
{
   eEmployee* unEmpleado;
   char confirmacion;
   int posicion;
   int id;

   limpiarPantallaYMostrarTitulo(EMPLOYEE_BAJA_TITULO);

   if(!eEmployee_informarListadoVacio(this))
   {
      limpiarPantallaYMostrarTitulo(EMPLOYEE_BAJA_TITULO);

      unEmpleado = eEmployee_pedirIdYBuscar(this);

      limpiarPantallaYMostrarTitulo(EMPLOYEE_BAJA_TITULO);
      imprimirEnPantalla(EMPLOYEE_MOSTRAR_UNO_CABECERA);
      eEmployee_mostrarUno(unEmpleado);

      confirmacion = pedirConfirmacion(EMPLOYEE_MSJ_CONFIRMAR_BAJA);

      if(confirmacion == 'S')
      {
         idPelicula = (listadoPeliculas+posicion)->idPelicula;
         (listadoPeliculas+posicion)->estado = LIBRE;
         imprimirEnPantalla(EMPLOYEE_MSJ_BAJA_OK);
      }
      else
      {
         imprimirEnPantalla(MSJ_CANCELO_GESTION);
      }
   }

   pausa();
   return id;
}
//-----------------------------------------------------------------------------------------------//


/**************************** GESTION DE DATOS ***************************************************/
void eEmployee_delete(eEmployee* this)
{
    free(this);
}
//-----------------------------------------------------------------------------------------------//
void eEmployee_gestionListar(ArrayList* this)
{
   limpiarPantallaYMostrarTitulo(EMPLOYEE_LISTADO_TITULO);

   if(!eEmployee_informarListadoVacio(this))
   {
      eEmployee_printList(this, EMPLOYEE_PRINT_PAGESIZE);
   }
   pausa();
}
//-----------------------------------------------------------------------------------------------//
void eEmployee_gestionOrdenar(ArrayList* this)
{
   limpiarPantallaYMostrarTitulo(EMPLOYEE_ORDEN_TITULO);

   if(!eEmployee_informarListadoVacio(this))
   {
      eEmployee_sort(this);
      imprimirEnPantalla(EMPLOYEE_MSJ_ORDEN_OK);
   }
   pausa();
}
//-----------------------------------------------------------------------------------------------//


/**************************** ORDENAMIENTO *******************************************************/
int eEmployee_compareByName(void* pEmployeeA,void* pEmployeeB)
{
   /*
   int returnAux;
   eEmployee* a;
   eEmployee* b;

   a = (eEmployee*) pEmployeeA;
   b = (eEmployee*) pEmployeeB;

   returnAux = strcmp(a->name, b->name);

   return returnAux;
   */
   return strcmp(((eEmployee*)pEmployeeA)->name, ((eEmployee*)pEmployeeB)->name);
}
//-----------------------------------------------------------------------------------------------//
int eEmployee_compareByLastName(void* pEmployeeA,void* pEmployeeB)
{
   return strcmp(((eEmployee*)pEmployeeA)->lastName, ((eEmployee*)pEmployeeB)->lastName);
}
//-----------------------------------------------------------------------------------------------//
int eEmployee_sort(ArrayList* this)
{
   int returnAux = -1;

   if(this!=NULL)
   {
      returnAux = 0;
      al_sort(this, eEmployee_compareByName, EMPLOYEE_ORDEN_ASC);
   }

   return returnAux;
}
//-----------------------------------------------------------------------------------------------//
