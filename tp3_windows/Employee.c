#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"

void employee_delete(Employee *this) {
	free(this);
}

Employee* employee_new() {
	//asigno el espacio en memoria para el empleado y le inicializo valores
	Employee *empleado = (Employee*) malloc(sizeof(Employee));
	if (empleado != NULL) {
		empleado->id = 0;
		strcpy(empleado->nombre, "");
		empleado->horasTrabajadas = 0;
		empleado->sueldo = 0;
	}
	return empleado;
}


//SETTERS

int employee_setId(Employee *this, int id) {
	int retorno;
	retorno = -1;
	if (this != NULL) {
		this->id = id;
		retorno = 0;
	}
	return retorno;
}

int employee_setNombre(Employee *this, char *nombre) {
	int retorno;
	retorno = -1;
	if (this != NULL) {
		strcpy(this->nombre, nombre);
		retorno = 0;
	}
	return retorno;
}

int employee_setHorasTrabajadas(Employee *this, int horasTrabajadas) {
	int retorno;
	retorno = -1;
	if (this != NULL) {
		this->horasTrabajadas = horasTrabajadas;
		retorno = 0;
	}
	return retorno;

}

int employee_setSueldo(Employee *this, int sueldo) {
	int retorno;
	retorno = -1;
	if (this != NULL) {
		this->sueldo = sueldo;
		retorno = 0;
	}
	return retorno;
}


//solo para leer del archivo
Employee* employee_newParametros(char *idStr, char *nombreStr,
		char *horasTrabajadasStr, char *sueldoStr) {
	//acá paso por parametros los campos de la estructura
	Employee *pEmpleado = employee_new();

	if (pEmpleado != NULL && idStr != NULL && nombreStr != NULL
			&& horasTrabajadasStr != NULL && sueldoStr != NULL)
	{
		employee_setId(pEmpleado, atoi(idStr));
		employee_setNombre(pEmpleado, nombreStr);
		employee_setHorasTrabajadas(pEmpleado, atoi(horasTrabajadasStr));
		employee_setSueldo(pEmpleado, atoi(sueldoStr));
	}
	return pEmpleado;
}


//GETTERS

int employee_getId(Employee *this, int *id) {
	int retorno;
	retorno = -1;
	if (this != NULL) {
		*id = this->id;
		retorno = 0;
	}
	return retorno;
}

int employee_getNombre(Employee *this, char *nombre) {
	int retorno;
	retorno = -1;
	if (this != NULL) {
		strcpy(nombre, this->nombre);
		retorno = 0;
	}
	return retorno;
}

int employee_getHorasTrabajadas(Employee *this, int *horasTrabajadas) {
	int retorno;
	retorno = -1;
	if (this != NULL) {
		*horasTrabajadas = this->horasTrabajadas;
		retorno = 0;
	}
	return retorno;
}

int employee_getSueldo(Employee *this, int *sueldo) {
	int retorno;
	retorno = -1;
	if (this != NULL) {
		*sueldo = this->sueldo;
		retorno = 0;
	}
	return retorno;
}

int employee_sortByNombre(void){
	return 1;
}

int employee_sortByHorasTrabajadas(void){
	return 1;
}

int employee_sortBySueldo(void){
	return 1;
}

int employee_sortById(void){
	return 1;
}
