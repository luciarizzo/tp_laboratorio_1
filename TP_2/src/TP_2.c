/*
 ============================================================================
 Name        : TP_2.c
 Author      : Lucia
 Version     :
 Copyright   : Your copyright notice
 Description :

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "arrayEmployees.h"

#define CANTEMPLEADOS 1000


int main(void) {
	setbuf(stdout,NULL);
	Employee arrayEmployees[CANTEMPLEADOS];
	int opcionMenu;
	//int IdEmployee;
	//IdEmployee = 1000;

	//mostrarMenu(&opcionMenu, "\nIngrese un número para elegir una opción: \n1-Dar alta empleado \n2-Modificar \n3-Dar de baja empleado \n4-Informar \n5-Salir\n", 5);
	initEmployees(arrayEmployees, CANTEMPLEADOS);
	altaEmpleado(arrayEmployees, CANTEMPLEADOS);
	/*findEmployeeById(arrayEmployees, CANTEMPLEADOS);
	removeEmployee(arrayEmployees, CANTEMPLEADOS);
	modifiedEmployeeName(arrayEmployees, CANTEMPLEADOS);
	modifiedEmployeeLastName(arrayEmployees, CANTEMPLEADOS);*/
	//modifiedEmployeeSalary(arrayEmployees, CANTEMPLEADOS);
	modifiedEmployeeSectorId(arrayEmployees, CANTEMPLEADOS);

	EXIT_SUCCESS;
}
