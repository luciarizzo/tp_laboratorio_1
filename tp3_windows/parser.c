#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"


int parser_EmployeeFromText(FILE *pFile, LinkedList *pArrayListEmployee) {
	int retorno;
	retorno = -1;
	int variablesLeidas;
	char auxId[1000];
	char auxNombre[1000];
	char auxHoras[1000];
	char auxSueldo[1000];
	Employee *pEmpleado;

	if (pFile != NULL && pArrayListEmployee != NULL) {
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", auxId, auxNombre, auxHoras,
				auxSueldo);
		do {
			variablesLeidas = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", auxId,
					auxNombre, auxHoras, auxSueldo);
			if (variablesLeidas == 4) {
				pEmpleado = employee_newParametros(auxId, auxNombre, auxHoras,
						auxSueldo);
				if (pEmpleado != NULL) {
					ll_add(pArrayListEmployee, pEmpleado);
					retorno = 0;
				}
			} else {
				puts("\nError");
			}
		} while (!feof(pFile));
	}
	return retorno;
}


int parser_EmployeeFromBinary(FILE *pFile, LinkedList *pArrayListEmployee) {
	int retorno;
	retorno = -1;
	int valoresRetornados;

	Employee *pEmpleado = NULL;

	if (pFile != NULL && pArrayListEmployee != NULL) {
		do {
			pEmpleado = employee_new();
			if (pEmpleado != NULL) {
				valoresRetornados = fread(pEmpleado, sizeof(Employee), 1,
						pFile);
				if (valoresRetornados == 1) {
					ll_add(pArrayListEmployee, pEmpleado);
					retorno = 0;
				} else {
					employee_delete(pEmpleado);
					break;
				}
			}
		} while (!feof(pFile));
	}
	return retorno;
}
