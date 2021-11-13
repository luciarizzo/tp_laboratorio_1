#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"
/****************************************************
 Menu:
 1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
 2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
 3. Alta de empleado
 4. Modificar datos de empleado
 5. Baja de empleado
 6. Listar empleados
 7. Ordenar empleados
 8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
 9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
 10. Salir
 *****************************************************/

int main() {
	setbuf(stdout, NULL);

	//int option = 0;
	int option;
	int flagPrimeraCarga = -1;
	LinkedList *listaEmpleados = ll_newLinkedList();

	do {
		utn_getNumero(&option,
				"Menu:\n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n  2. Cargar los datos de los empleados desde el archivo data.csv (modo binario) \n  3. Alta de empleado\n  4. Modificar datos de empleado\n  5. Baja de empleado\n  6. Listar empleados\n  7. Ordenar empleados\n  8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n  9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n  10. Salir\n",
				"\n La opción ingresada no está dentro del rango solicitado\n",
				1, 10, 2);

		switch (option) {
		case 1: //Cargar los datos de los empleados desde el archivo data.csv (modo texto).
			if (controller_loadFromText("data.csv", listaEmpleados) == 0) {
				flagPrimeraCarga = 0;
			}
			break;

		case 2: //Cargar los datos de los empleados desde el archivo data.csv (modo binario).
			if (controller_loadFromBinary("data.bin", listaEmpleados) == 0) {
				flagPrimeraCarga = 0;
			}
			break;

		case 3: //Alta de empleado
			if (flagPrimeraCarga == 0){
				controller_addEmployee(listaEmpleados);
			} else {
				printf("\nError. Debe cargar los datos de empleados primero con la opcion 2 o 3 del menu\n");
			}
			break;

		case 4: //Modificar datos de empleado
			controller_editEmployee(listaEmpleados);
			break;

		case 5: //Baja de empleado
			controller_removeEmployee(listaEmpleados);
			break;

		case 6: //Listar empleados
			controller_ListEmployee(listaEmpleados);
			break;

		case 7: //Ordenar empleados
			controller_sortEmployee(listaEmpleados);
			break;

		case 8: //Guardar los datos de los empleados en el archivo data.csv (modo texto).
			controller_saveAsText("data_copia.csv", listaEmpleados);
			break;

		case 9: //Guardar los datos de los empleados en el archivo data.csv (modo binario).
			controller_saveAsBinary("data.bin", listaEmpleados);
			break;
		}
	} while (option != 10);

	return 0;
}

