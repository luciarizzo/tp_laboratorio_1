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
			&& horasTrabajadasStr != NULL && sueldoStr != NULL) {
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

int employee_sortById(void *paramUno, void *paramDos) {
	int retorno;
	retorno = 0;
	int bufferIdUno;
	int bufferIdDos;
	if (paramUno != NULL && paramDos != NULL) {
		if (employee_getId((Employee*)paramUno, &bufferIdUno) == 0 && employee_getId((Employee*)paramDos, &bufferIdDos) == 0)
		{
			if (bufferIdUno > bufferIdDos) {
				retorno = 1;
			}
			if (bufferIdDos > bufferIdUno) {
				retorno = -1;
			}
		}
	}
	return retorno;
}

int employee_sortByNombre(void *paramUno, void *paramDos) {
	int retorno = 0;
	char bufferNombreUno[1000];
	char bufferNombreDos[1000];
	if (paramUno != NULL && paramDos != NULL) {
		if (employee_getNombre((Employee*) paramUno, bufferNombreUno) == 0
				&& employee_getNombre((Employee*) paramDos, bufferNombreDos)
						== 0) {
			if (stricmp(bufferNombreUno, bufferNombreDos) > 0) {
				retorno = 1;
			}
			if (stricmp(bufferNombreUno, bufferNombreDos) < 0) {
				retorno = -1;
			}
		}
	}
	return retorno;
}

int employee_sortByHorasTrabajadas(void *paramUno, void *paramDos) {
	int retorno;
	retorno = 0;
	int bufferHorasUno;
	int bufferHorasDos;

	if (paramUno != NULL && paramDos != NULL) {
		if (employee_getHorasTrabajadas((Employee*)paramUno, &bufferHorasUno)
				== 0
				&& employee_getHorasTrabajadas((Employee*)paramDos,
						&bufferHorasDos) == 0) {
			if (bufferHorasUno > bufferHorasDos) {
				retorno = 1;
			}
			if (bufferHorasDos > bufferHorasUno) {
				retorno = -1;
			}
		}
	}
	return retorno;
}

int employee_sortBySueldo(void *paramUno, void *paramDos) {
	int retorno;
	retorno = 0;
	int bufferSueldoUno;
	int bufferSueldoDos;
	if (paramUno != NULL && paramDos != NULL) {
		if (employee_getSueldo((Employee*)paramUno, &bufferSueldoUno) == 0 && employee_getSueldo((Employee*)paramDos, &bufferSueldoDos) == 0)
		{
			if (bufferSueldoUno > bufferSueldoDos) {
				retorno = 1;
			}
			if (bufferSueldoDos > bufferSueldoUno) {
				retorno = -1;
			}
		}
	}
	return retorno;
}
