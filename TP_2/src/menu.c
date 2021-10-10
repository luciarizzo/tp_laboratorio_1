/*
 * menu.c
 *
 *  Created on: 8 oct. 2021
 *      Author: Luc�a
 */
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include <string.h>
#include "arrayEmployees.h"
#include "informes.h"
#define CANTEMPLEADOS 1000

void mostrarMenu(char *mensaje, int opcionSalir) {

	Employee arrayEmployees[CANTEMPLEADOS];

	int flagPrimerEjecucion;
	flagPrimerEjecucion = 0;
	int opcionMenu;
	int opcionSubMenuModificar;
	int opcionSubMenuInformar;
	int flagHuboCargaEmpleado = 0;
	if (mensaje != NULL) {
		do {
			if (flagPrimerEjecucion == 0) {
				printf("BIENVENIDO. POR FAVOR, ELIJA UNA OPCI�N:");
				initEmployees(arrayEmployees, CANTEMPLEADOS);
				flagPrimerEjecucion = 1;
			}
			if (utn_getNumero(&opcionMenu, mensaje,
					"\n La opci�n ingresada no est� dentro del rango solicitado\n",
					1, opcionSalir, 3) == 0) {
				switch (opcionMenu) {
				case 1:
					if (altaEmpleado(arrayEmployees, CANTEMPLEADOS) != -1) {
						flagHuboCargaEmpleado = 1;
					}
					printf("\n�Desea ingresar otro empleado?\n");
					while (utn_getCaracterSiNo() == 0) {
						altaEmpleado(arrayEmployees, CANTEMPLEADOS);
					}
					fflush(stdin);
					break;
				case 2:
					if (flagHuboCargaEmpleado == 0) {
						printf(
								"\nError. Para ingresar a esta opci�n debe cargar un empleado primero.\n");
					} else {
						utn_getNumero(&opcionSubMenuModificar,
								"\nElija qu� desea modificar: \n2.1: Nombre \n2.2 Apellido \n2.3 Salario \n2.4 Sector\n",
								"\n La opci�n ingresada no est� dentro del rango solicitado\n",
								1, opcionSalir, 3);
						switch (opcionSubMenuModificar) {
						case 1:
							modifiedEmployeeName(arrayEmployees, CANTEMPLEADOS);
							break;
						case 2:
							modifiedEmployeeLastName(arrayEmployees,
									CANTEMPLEADOS);
							break;
						case 3:
							modifiedEmployeeSalary(arrayEmployees,
									CANTEMPLEADOS);
							break;
						case 4:
							modifiedEmployeeSectorId(arrayEmployees,
									CANTEMPLEADOS);
							break;
						}
					}
					break;
				case 3:
					if (flagHuboCargaEmpleado == 0) {
						printf(
								"\nError. Para ingresar a esta opci�n debe cargar un empleado primero.\n");
					} else {
						removeEmployee(arrayEmployees, CANTEMPLEADOS);
					}
					break;
				case 4:
					if (flagHuboCargaEmpleado == 0) {
						printf(
								"\nError. Para ingresar a esta opci�n debe cargar un empleado primero.\n");
					} else {
						utn_getNumero(&opcionSubMenuInformar,
								"\nElija qu� desea informar: \n4.1: Listado ordenado alfab�ticamente por Apellido y Sector \n4.2 Total y promedio de salaros \n4.3 Cu�ntos superan el salario promedio\n",
								"\n La opci�n ingresada no est� dentro del rango solicitado\n",
								1, opcionSalir, 3);
						switch (opcionSubMenuInformar) {
						case 1:
							printEmployeesbyLastNameOrSector(arrayEmployees,
							CANTEMPLEADOS);
							break;
						case 2:
							printTotal(arrayEmployees, CANTEMPLEADOS);
							printPromedio(arrayEmployees, CANTEMPLEADOS);
							break;
						case 3:
							printEmployeesSuperiorSalary(arrayEmployees,
							CANTEMPLEADOS);
							break;
						}
					}
					break;
				}
			} else {
				printf("\n Error, ingrese un n�mero v�lido para el men�.\n");
			}

		} while (opcionMenu != opcionSalir);
	}
}
