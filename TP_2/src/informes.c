/*
 * informes.c
 *
 *  Created on: 9 oct. 2021
 *      Author: Lucía
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "informes.h"
#include "arrayEmployees.h"

void printEmployeesbyLastNameOrSector(Employee lista[], int len){
	sortEmployeesbyLastNameOrSector(lista, len);
	printEmployees(lista, len);
}

//total y promedio de salarios
void printTotal(Employee lista[], int len){
	float total;
	total = totalSalarios(lista, len);
	printf("\nEl total de los salarios es: %f\n", total);
}


void printPromedio(Employee lista[], int len){
	float promedio;
	promedio = promedioSalarios(lista, len);
	printf("\nEl promedio del salario de los empleados existentes es: %f\n", promedio);
}

// cuantos superan el salario promedio
void printEmployeesSuperiorSalary(Employee lista[], int len){
	int empleadosSalarioSuperior;
	empleadosSalarioSuperior = superanSalarioPromedio(lista, len);
	printf("\n La cantidad de empleados que superan el salario promedio es: %d\n", empleadosSalarioSuperior);
}
