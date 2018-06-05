#pragma once
#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED


/**************************** INCLUSION DE LIBRERIAS PERSONALES **********************************/
#include "General.h"
#include "Menu.h"

/**************************** CONSTANTES *********************************************************/
#define EMPLOYEE_EMPTY 1
#define EMPLOYEE_OCCUPIED 0
#define EMPLOYEE_EMPTY_LEGEND "Empty"
#define EMPLOYEE_OCCUPIED_LEGEND "Occupied"
#define TRUE "true"
#define FALSE "false"
#define EMPLOYEE_PRINT_PAGESIZE 1000

/**************************** LIMITES ************************************************************/
#define EMPLOYEE_LARGO_NAME 51
#define EMPLOYEE_LARGO_LAST_NAME 51
#define EMPLOYEE_ID_MIN 1
#define EMPLOYEE_ID_MAX 1000000
#define EMPLOYEE_LARGO_RESERVAS 10

/**************************** MASCARAS ***********************************************************/
#define EMPLOYEE_PRINT_MASK "\n%d \t %-20s \t %-20s \t %s"
#define EMPLOYEE_PARSE_MASK "%[^,],%[^,],%[^,],%[^\n]\n"

/**************************** TITULOS ************************************************************/
#define EMPLOYEE_ALTA_TITULO "ALTA DE EMPLOYEE"
#define EMPLOYEE_BAJA_TITULO "BAJA DE EMPLOYEE"
#define EMPLOYEE_MODIFICACION_TITULO "MODIFICACION DE EMPLOYEE"
#define EMPLOYEE_LISTADO_TITULO "LISTADO DE EMPLOYEES"
#define EMPLOYEE_ORDEN_TITULO "ORDEN DE EMPLOYEES"
#define EMPLOYEE_PARSEO_TITULO "PARSEO ARCHIVO CSV DE EMPLOYEES"

/**************************** MENSAJES ERROR *****************************************************/
#define EMPLOYEE_MSJ_ID_NO_EXISTE "\nEl ID de Employee ingresado no existe"
#define EMPLOYEE_MSJ_LISTA_VACIA "\n\nLa lista de Employees esta vacia o todos los registros se dieron de baja"
#define EMPLOYEE_MSJ_NO_MAS_LUGAR "\nNo hay mas lugares disponibles para altas de Employee"
#define EMPLOYEE_MSJ_REINGRESE_ID "\nEl ID debe ser un numero mayor que cero. Reingrese un ID valido: "
#define EMPLOYEE_MSJ_REINGRESE_NOMBRE "\nNombre no valido. Reingrese por favor hasta 50 caracteres: "
#define EMPLOYEE_MSJ_REINGRESE_APELLIDO "\nApellido no valido. Reingrese por favor hasta 50 caracteres: "

/**************************** MENSAJES INFO ******************************************************/
#define EMPLOYEE_MSJ_CONFIRMAR_BAJA "Confirma que desea dar de baja dicha Employee?"
#define EMPLOYEE_MSJ_ALTA_OK "\nLa Employee se dio de alta"
#define EMPLOYEE_MSJ_BAJA_OK "\nLa Employee se dio de baja"
#define EMPLOYEE_MSJ_MODIFICACION_SIN_CAMBIOS "\nNo hubo cambio alguno"
#define EMPLOYEE_MSJ_MODIFICACION_OK "\nLa Employee se modifico"
#define EMPLOYEE_MSJ_REGISTRO_ACTUAL "\n\nREGISTRO DE EMPLOYEE ACTUAL:\n----------------------------"
#define EMPLOYEE_MSJ_REGISTRO_MODIFICADO "\n\nREGISTRO MODIFICADO:\n--------------------"
#define EMPLOYEE_MSJ_ORDEN_OK "\n\nSe ordeno listado por nombre"

/**************************** MENSAJES INPUT *****************************************************/
#define EMPLOYEE_MSJ_INGRESE_ID "\n\nIngrese el ID de Employee: "
#define EMPLOYEE_MSJ_INGRESE_NOMBRE "\nIngrese Nombre: "
#define EMPLOYEE_MSJ_INGRESE_APELLIDO "\nIngrese Apellido: "

/**************************** LISTADOS ***********************************************************/
#define EMPLOYEE_PRINT_MASK_CABECERA "\nID \t- NOMBRE \t\t- APELLIDO \t\t- ES VACIO"


/**************************** ORDENAMIENTO *******************************************************/
#define EMPLOYEE_ORDEN_ASC 1
#define EMPLOYEE_ORDEN_DESC 0

/**************************** MENUS **************************************************************/
#define EMPLOYEE_MENU_MODIFICAR_UNO_TITULO "Que desea modificar?"
#define EMPLOYEE_MENU_MODIFICAR_UNO_CANT 8
#define EMPLOYEE_MENU_MODIFICAR_UNO_DETALLE1 "1. Titulo"
#define EMPLOYEE_MENU_MODIFICAR_UNO_DETALLE2 "2. Genero"
#define EMPLOYEE_MENU_MODIFICAR_UNO_DETALLE3 "3. Duracion"
#define EMPLOYEE_MENU_MODIFICAR_UNO_DETALLE4 "4. Descripcion"
#define EMPLOYEE_MENU_MODIFICAR_UNO_DETALLE5 "5. Puntaje"
#define EMPLOYEE_MENU_MODIFICAR_UNO_DETALLE6 "6. Link a imagen"
#define EMPLOYEE_MENU_MODIFICAR_UNO_DETALLE9 "9. Finalizar modificacion"
#define EMPLOYEE_MENU_MODIFICAR_UNO_DETALLE0 "0. Cancelar"


/**************************** ESTRUCTURAS ********************************************************/
struct
{
    int id;
    char name[EMPLOYEE_LARGO_NAME];
    char lastName[EMPLOYEE_LARGO_LAST_NAME];
    int isEmpty;

}typedef eEmployee;


/**************************** GET Y SET **********************************************************/
int eEmployee_getId(eEmployee* this);
//-----------------------------------------------------------------------------------------------//
int eEmployee_getIsEmpty(eEmployee* this);
//-----------------------------------------------------------------------------------------------//
char* eEmployee_getIsEmptyLegend(eEmployee* this);
//-----------------------------------------------------------------------------------------------//
char* eEmployee_getName(eEmployee* this);
//-----------------------------------------------------------------------------------------------//
char* eEmployee_getLastName(eEmployee* this);
//-----------------------------------------------------------------------------------------------//
int eEmployee_setId(eEmployee* this, int id);
//-----------------------------------------------------------------------------------------------//
int eEmployee_setIsEmpty(eEmployee* this, int isEmpty);
//-----------------------------------------------------------------------------------------------//
int eEmployee_setName(eEmployee* this, char* name);
//-----------------------------------------------------------------------------------------------//
int eEmployee_setLastName(eEmployee* this, char* lastName);
//-----------------------------------------------------------------------------------------------//


/**************************** INICIALIZACIONES ***************************************************/
void eEmployee_initHardcode(eEmployee* listadoEmployees);
//-----------------------------------------------------------------------------------------------//
int eEmployee_init(ArrayList* this);


/**************************** BUSQUEDA ***********************************************************/
int eEmployee_estaVacio(ArrayList* this);
//-----------------------------------------------------------------------------------------------//
int eEmployee_informarListadoVacio(ArrayList* this);
//-----------------------------------------------------------------------------------------------//
int eEmployee_nextId(ArrayList* this);
//-----------------------------------------------------------------------------------------------//
int eEmployee_searchById(ArrayList* this, int id);
//-----------------------------------------------------------------------------------------------//
eEmployee* eEmployee_getById(ArrayList* this);
//-----------------------------------------------------------------------------------------------//


/**************************** ENTRADA DE DATOS ***************************************************/
eEmployee* eEmployee_new(void);
//-----------------------------------------------------------------------------------------------//
eEmployee* eEmployee_newParam(int id, char* name, char* lastName, int isEmpty);
//-----------------------------------------------------------------------------------------------//
int eEmployee_pedirId();
//-----------------------------------------------------------------------------------------------//
char* eEmployee_pedirName();
//-----------------------------------------------------------------------------------------------//
char* eEmployee_pedirLastName();
//-----------------------------------------------------------------------------------------------//
eEmployee* eEmployee_pedirIngreso(ArrayList* this);
//-----------------------------------------------------------------------------------------------//

/**************************** LISTADO DE DATOS ***************************************************/
void eEmployee_print(eEmployee* this);
//-----------------------------------------------------------------------------------------------//
void eEmployee_printList(ArrayList* this, int pageSize);
//-----------------------------------------------------------------------------------------------//
void eEmployee_printListWithEmpty(ArrayList* this);
//-----------------------------------------------------------------------------------------------//


/**************************** GESTION DE DATOS ***************************************************/
void eEmployee_delete(eEmployee* this);
//-----------------------------------------------------------------------------------------------//
void eEmployee_gestionParsear(ArrayList* this);
//-----------------------------------------------------------------------------------------------//
void eEmployee_gestionListar(ArrayList* this);
//-----------------------------------------------------------------------------------------------//
void eEmployee_gestionOrdenar(ArrayList* this);
//-----------------------------------------------------------------------------------------------//
int eEmployee_gestionAlta(ArrayList* this);
//-----------------------------------------------------------------------------------------------//
int eEmployee_gestionBaja(ArrayList* this);
//-----------------------------------------------------------------------------------------------//


/**************************** ORDENAMIENTO *******************************************************/
int eEmployee_compareByName(void* pEmployeeA,void* pEmployeeB);
//-----------------------------------------------------------------------------------------------//
int eEmployee_sort(ArrayList* this);
//-----------------------------------------------------------------------------------------------//
#endif // EMPLOYEE_H_INCLUDED
