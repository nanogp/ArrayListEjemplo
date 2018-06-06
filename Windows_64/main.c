/**************************** INCLUSION DE LIBRERIAS PERSONALES **********************************/
#include "General.h"
#include "Menu.h"
#include "Archivo.h"
#include "ArrayList.h"
#include "Employee.h"
#include "Parser.h"


/**************************** INCLUSION DE LIBRERIAS ESTANDAR ************************************/
#include <stdio.h>
#include <stdlib.h>

/**************************** MENUS **************************************************************/
#define MAIN_MENU_TITULO "ARRAY LIST"
#define MAIN_MENU_CANT 7//8
#define MAIN_MENU_DETALLE1  "1. Parse del archivo data.csv"
#define MAIN_MENU_DETALLE2  "2. Listar Empleados"
#define MAIN_MENU_DETALLE3  "3. Ordenar por nombre"
#define MAIN_MENU_DETALLE4  "4. Agregar un elemento"
#define MAIN_MENU_DETALLE5  "5. Elimina un elemento"
#define MAIN_MENU_DETALLE6  "6. Listar Empleados (Desde/Hasta)"
//#define MAIN_MENU_DETALLE7  "7. Listar Empleados Con Vacios"
#define MAIN_MENU_DETALLE0  "0. Salir"

int main()
{
   eMenu menuPrincipal = {/*titulo del menu*/{MAIN_MENU_TITULO},
                          /*cantidad de opciones*/MAIN_MENU_CANT,
                          /*codigos*/{1,2,3,4,5,6,//7,
                                      0},
                          /*descripciones*/{MAIN_MENU_DETALLE1,
                                            MAIN_MENU_DETALLE2,
                                            MAIN_MENU_DETALLE3,
                                            MAIN_MENU_DETALLE4,
                                            MAIN_MENU_DETALLE5,
                                            MAIN_MENU_DETALLE6,
                                            //MAIN_MENU_DETALLE7,
                                            MAIN_MENU_DETALLE0}};
   int opcion;
   char salirDelPrograma = 'N';


   /************************* ARRAYS DE ESTRUCTURAS **********************************************/
   ArrayList* empleados;

   /************************* INICIALIZACION *****************************************************/
   empleados = al_newArrayList();

   /************************* GENERA DATOS POR HARDCODE PARA DEBUG *******************************/
   /************************* (SOLO SI EL ARCHIVO BINARIO NO EXISTE) *****************************/

   do
   {
      /********************** MENU PRINCIPAL *****************************************************/
      ejecutarEnConsola(LIMPIAR_PANTALLA);
      opcion = pedirOpcion(&menuPrincipal);
      switch(opcion)
      {
         case 1:
            /**************** EMPLOYEE PARSE *****************************************************/
            eEmployee_gestionParsear(empleados);
            break;
         case 2:
            /**************** EMPLOYEE LISTAR ****************************************************/
            eEmployee_gestionListar(empleados);
            break;
         case 3:
            /**************** EMPLOYEE ORDENAR ***************************************************/
            eEmployee_gestionOrdenar(empleados);
            break;
         case 4:
            /**************** EMPLOYEE ALTA ******************************************************/
            eEmployee_gestionAlta(empleados);
            break;
         case 5:
            /**************** EMPLOYEE BAJA ******************************************************/
            eEmployee_gestionBaja(empleados);
            break;
         case 6:
            /**************** EMPLOYEE LISTAR DESDE/HASTA ****************************************/
            eEmployee_gestionListarDesdeHasta(empleados);
            break;
         //case 7:
         //   /**************** EMPLOYEE LISTAR CON VACIOS *****************************************/
         //   eEmployee_printListWithEmpty(empleados);pausa();
         //   break;
         case 0:
            /************ SALIR DEL PROGRAMA *****************************************************/
            salirDelPrograma = pedirConfirmacion(MSJ_SALIR_DEL_PROGRAMA);
            break;
      }

   }
   while(salirDelPrograma == 'N');
   return 0;
}
