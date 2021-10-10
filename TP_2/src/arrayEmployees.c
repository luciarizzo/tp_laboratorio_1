/*
 * arrayEmployees.c
 *
 *  Created on: 8 oct. 2021
 *      Author: Lucía
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "utn.h"
#include "arrayEmployees.h"

int initEmployees(Employee lista[], int len) {
	int i;
	int retorno;
	retorno = -1;
	if (lista != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			lista[i].isEmpty = 1;
		}
		retorno = 0;
	}
	return retorno;
} //la testeé y funciona.

int BuscarPrimerEspacioLibre(Employee lista[], int len) {
	int i;
	int index;
	index = -1;
	if (lista != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			if (lista[i].isEmpty == 1) {
				index = i;
				break;
			}
		}
	}
	return index;
}

int BuscarId(Employee lista[], int len, int id) {
	int i;
	int index;
	index = -1;
	if (lista != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			if (lista[i].isEmpty == 0 && lista[i].idEmployee == id) {
				index = i;
				break;
			}
		}
	}
	return index;
}


Employee addEmployee(Employee lista[], int len) {
	int id;
	char name[100];
	char lastName[100];
	float salary;
	int sectorId;
	Employee empleado;

	do{
		utn_getNumero(&id, "\nIngrese el número de ID del empleado\n",
				"\nIngrese un ID válido, debe ser entre 1 y 1000\n", 1, 1000,
				2);
	}while(BuscarId(lista, len, id) != -1);

	empleado.idEmployee = id;


	utn_getString(name, "\n Ingrese el nombre del empleado\n",
			"\nError, ingrese un nombre válido\n", 2);
	strcpy(empleado.nameEmployee, name);

	utn_getString(lastName, "\n Ingrese el apellido del empleado\n",
			"\nError, ingrese un apellido válido\n", 2);
	strcpy(empleado.lastNameEmployee, lastName);

	utn_getNumeroFlotante(&salary, "\nIngrese el salario del empleado\n",
			"\nError. Ingrese un salario válido\n", 1, 100000, 2);
	empleado.salaryEmployee = salary;

	utn_getNumero(&sectorId, "\nIngrese el número de sector ID del empleado\n",
			"\nError, ingrese un sector ID válido, debe ser entre 1 y 5\n", 1,
			5, 2);
	empleado.sectorIdEmployee = sectorId;

	empleado.isEmpty = 0; //ocupado.
	printf("\n Finalizó la carga del nuevo empleado.\n");
	return empleado;
}

int altaEmpleado(Employee lista[], int len) {
	int i;
	i = BuscarPrimerEspacioLibre(lista, len);
	if (i != -1) {
		if (lista != NULL && len > 0 && i != -1) {
			lista[i] = addEmployee(lista, len);
		}
	}
	return i;
}

int findEmployeeById(Employee lista[], int len) {
	int retorno;
	retorno = -1;
	int i;
	int idIngresado;
	utn_getNumero(&idIngresado,
			"\nIngrese el número de ID del empleado que desea buscar\n",
			"\nError, ingrese un ID válido, debe ser entre 1 y 1000\n", 1, 1000,
			2);
	for (i = 0; i < len; i++) {
		if (lista[i].isEmpty == 0 && lista[i].idEmployee == idIngresado) {
			printf("\nEl empleado fue encontrado.\n");
			retorno = idIngresado;
		}
	}
	if (retorno == -1) {
		printf("\nNingun empleado fue encontrado con ese ID.\n");
	}

	return retorno;
}

int removeEmployee(Employee lista[], int len) {
	int i;
	int id;
	id = findEmployeeById(lista, len);
	int retorno;
	retorno = -1;
	for (i = 0; i < len; i++) {
		if (lista[i].isEmpty == 0 && lista[i].idEmployee == id) {
			printf("\n¿Desea eliminar el empleado con esos datos?\n");
			print1Employee(lista[i]);
			if (utn_getCaracterSiNo() == 0) {
				lista[i].isEmpty = 1;
				retorno = 0;
				printf("\n Se eliminó el empleado\n");
			}
			break;
		}
	}
	return retorno;
}

int modifiedEmployeeName(Employee lista[], int len) {
	int i;
	int empleadoAModificar;
	char name[100];
	int retorno;
	retorno = 0;
	empleadoAModificar = findEmployeeById(lista, len);

	for (i = 0; i < len; i++) {
		if (lista[i].isEmpty == 0
				&& lista[i].idEmployee == empleadoAModificar) {
			printf("\nEstá a punto de modificar el empleado con nombre %s\n",
					lista[i].nameEmployee);
			utn_getString(name, "\n Ingrese el nuevo nombre del empleado\n",
					"\nError, ingrese un nombre válido\n", 2);
			strcpy(lista[i].nameEmployee, name);
			printf("\nEl nombre se ha modificado correctamente por: %s\n",
					lista[i].nameEmployee);
			//mostrar todos los datos acá
			retorno = 1;
			break;
		}
	}

	return retorno;

}

int modifiedEmployeeLastName(Employee lista[], int len) {
	int i;
	int empleadoAModificar;
	char lastName[100];
	int retorno;
	retorno = 0;
	empleadoAModificar = findEmployeeById(lista, len);

	for (i = 0; i < len; i++) {
		if (lista[i].isEmpty == 0
				&& lista[i].idEmployee == empleadoAModificar) {
			printf("\nEstá a punto de modificar el empleado con nombre: %s\n",
					lista[i].lastNameEmployee);
			utn_getString(lastName,
					"\n Ingrese el nuevo apellido del empleado\n",
					"\nError, ingrese un apellido válido\n", 2);
			strcpy(lista[i].lastNameEmployee, lastName);
			printf("\nEl apellido se ha modificado correctamente por: %s\n",
					lista[i].lastNameEmployee);
			retorno = 1;
			break;
		}
	}
	return retorno;
}

int modifiedEmployeeSalary(Employee lista[], int len) {
	int i;
	int empleadoAModificar;
	int retorno;
	retorno = 0;
	float salary;
	empleadoAModificar = findEmployeeById(lista, len);

	for (i = 0; i < len; i++) {
		if (lista[i].isEmpty == 0
				&& lista[i].idEmployee == empleadoAModificar) {
			printf("\nEstá a punto de modificar el empleado con nombre: %s\n",
					lista[i].nameEmployee);
			utn_getNumeroFlotante(&salary,
					"\nIngrese el salario del empleado\n",
					"\nError. Ingrese un salario válido\n", 1, 100000, 2);
			lista[i].salaryEmployee = salary;
			printf("\nEl salario se ha modificado correctamente por: %f\n",
					lista[i].salaryEmployee);
			retorno = 1;
			break;
		}
	}
	return retorno;
}

int modifiedEmployeeSectorId(Employee lista[], int len) {
	int i;
	int empleadoAModificar;
	int retorno;
	retorno = 0;
	int sectorId;
	empleadoAModificar = findEmployeeById(lista, len);

	for (i = 0; i < len; i++) {
		if (lista[i].isEmpty == 0
				&& lista[i].idEmployee == empleadoAModificar) {
			printf("\nEstá a punto de modificar el empleado con nombre: %s\n",
					lista[i].nameEmployee);
			utn_getNumero(&sectorId,
					"\nIngrese el nuevo número de sector ID del empleado\n",
					"\nError, ingrese un sector ID válido, debe ser entre 1 y 5\n",
					1, 5, 2);
			lista[i].sectorIdEmployee = sectorId;
			printf("\nEl sector se ha modificado correctamente por %d\n",
					lista[i].sectorIdEmployee);
			retorno = 1;
			break;
		}
	}
	return retorno;
}

void sortEmployeesbyLastNameOrSector(Employee lista[], int len) {
	Employee auxEmpleado;
	for (int i = 0; i < len - 1; i++) {
		for (int j = i + 1; j < len; j++) {
			if (strcmp(lista[i].lastNameEmployee, lista[j].lastNameEmployee)
					> 0) {
				auxEmpleado = lista[i];
				lista[i] = lista[j];
				lista[j] = auxEmpleado;
			} else if (strcmp(lista[i].lastNameEmployee,
					lista[j].lastNameEmployee) == 0) {
				if (lista[i].sectorIdEmployee > lista[j].sectorIdEmployee) {
					auxEmpleado = lista[i];
					lista[i] = lista[j];
					lista[j] = auxEmpleado;
				}
			}
		}
	}
}

void print1Employee(Employee unEmpleado) {
	printf("%2d %12s %20s %14.2f %12d \t", unEmpleado.idEmployee,
			unEmpleado.nameEmployee, unEmpleado.lastNameEmployee,
			unEmpleado.salaryEmployee, unEmpleado.sectorIdEmployee);
	printf(
			"\n____________________________________________________________________\n");
}

int printEmployees(Employee lista[], int len) {
	int retorno = -1;
	printf("\n____________________________________________________________________\n");
	printf("ID\t  Nombre\t   Apellido\t    Salario\t    Sector\n");
	printf("\n____________________________________________________________________\n");
	for (int i = 0; i < len; i++) {
		if (lista[i].isEmpty == 0) {
			print1Employee(lista[i]);
			retorno = 0;
		}
	}
	return retorno;
}

float totalSalarios(Employee lista[], int len) {
	int i;
	float acumulador;
	acumulador = 0;
	for (i = 0; i < len; i++) {
		if (lista[i].isEmpty == 0) {
			acumulador = acumulador + lista[i].salaryEmployee;
		}
	}
	return acumulador;
}

float promedioSalarios(Employee lista[], int len){
	float total;
	int i;
	float promedio;
	int contadorOcupados;
	contadorOcupados = 0;
	total = totalSalarios(lista, len);
	for (i = 0; i < len; i++) {
		if(lista[i].isEmpty == 0){
			contadorOcupados++;
		}
	}
	promedio = total / (float)contadorOcupados;
	return promedio;
}

int superanSalarioPromedio(Employee lista[], int len){
	int i;
	float promedio;
	int contadorEmpleadoSalarioSuperior;
	contadorEmpleadoSalarioSuperior = 0;
	promedio = promedioSalarios(lista, len);
	for(i=0; i<len; i++){
		if(lista[i].isEmpty == 0 && lista[i].salaryEmployee > promedio){
			contadorEmpleadoSalarioSuperior++;
			printf("\n%f\n", promedio);
			printf("\n%f\n", lista[i].salaryEmployee);
		}
	}
	return contadorEmpleadoSalarioSuperior;
}
