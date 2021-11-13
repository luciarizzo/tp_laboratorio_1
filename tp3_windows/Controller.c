#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char *path, LinkedList *pArrayListEmployee) {
	int retorno;
	retorno = -1;
	if (path != NULL && pArrayListEmployee != NULL) {
		FILE *pFile = fopen(path, "r");
		//ll_isEmpty devuelve -1 si es null, 1 si esta vacio y 0 si tiene contenido, de esta forma me avisa 1 sola vez la lectura correcta del archivo
		if (pFile != NULL && ll_isEmpty(pArrayListEmployee) == 1) {
			if (parser_EmployeeFromText(pFile, pArrayListEmployee) == 0) {
				printf(
						"\nEl archivo de texto se cargo correctamente. Cerrado.");
				retorno = 0;
			} else {
				printf("\nEl archivo no se pudo cargar correctamente\n");
			}
		}
		fclose(pFile);
	}
	return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char *path, LinkedList *pArrayListEmployee) {
	int retorno;
	retorno = -1;
	if (path != NULL && pArrayListEmployee != NULL) {
		//ll_isEmpty devuelve -1 si es null, 1 si esta vacio y 0 si tiene contenido, de esta forma me avisa 1 sola vez la lectura correcta del archivo
		FILE *pFile = fopen(path, "rb");
		if (pFile != NULL && ll_isEmpty(pArrayListEmployee) == 1) {
			if (parser_EmployeeFromBinary(pFile, pArrayListEmployee) == 0) {
				printf("\nEl archivo se cargo binario correctamente. Cerrado.");
				retorno = 0;
			} else {
				printf("\nEl archivo no se pudo cargar correctamente\n");
			}
		}
		fclose(pFile);
	}
	return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_addEmployee(LinkedList *pArrayListEmployee, int id) {
	int retorno;
	retorno = -1;
	char auxNombre[100];
	int auxHorasTrabajadas;
	int auxSueldo;
	Employee *auxEmpleado;

	if (pArrayListEmployee != NULL) {
		printf(
				"\nRecuerde que una vez que finalice la carga del empleado, debe guardar la carga con la opcion 8 o 9 del menu\n");
		if (utn_getNombre(auxNombre, "\nIngrese el nombre del nuevo empleado\n",
				"\nError, nombre no válido\n", 2, 100) == 0
				&& utn_getNumero(&auxHorasTrabajadas,
						"\nIngrese las horas trabajadas del nuevo empleado\n",
						"\nError, numero no válido\n", 1, 1000, 2) == 0
				&& utn_getNumero(&auxSueldo,
						"\nIngrese el sueldo del nuevo empleado\n",
						"\nError, numero no válido\n", 1, 10000, 2) == 0) {
			//id++;
			auxEmpleado = employee_new();
			if (auxEmpleado != NULL && employee_setId(auxEmpleado, id) == 0
					&& employee_setNombre(auxEmpleado, auxNombre) == 0
					&& employee_setHorasTrabajadas(auxEmpleado,
							auxHorasTrabajadas) == 0
					&& employee_setSueldo(auxEmpleado, auxSueldo) == 0) {
				ll_add(pArrayListEmployee, auxEmpleado);
			}
		}
	}

	return retorno;
}

/** \brief Obtiene Id Maximo
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_getMaxId(LinkedList *pArrayListEmployee) {
	int idMaximo;
	idMaximo = -1;
	int largoLL;
	int id;

	Employee *auxEmpleado = NULL;
	if (pArrayListEmployee != NULL && ll_isEmpty(pArrayListEmployee) == 0) {
		largoLL = ll_len(pArrayListEmployee);
		for (int i = 0; i < largoLL; i++) {
			auxEmpleado = (Employee*) ll_get(pArrayListEmployee, i);
			employee_getId(auxEmpleado, &id);
			if (id > idMaximo) {
				idMaximo = id;
			}
		}
	}
	return idMaximo;
}

int controller_findEmployeebyIdReturnIndex(LinkedList *pArrayListEmployee,
		int id) {
	int i;
	Employee *auxEmpleado;
	int largoLL;
	int retorno;
	retorno = -1;
	if (pArrayListEmployee != NULL) {
		largoLL = ll_len(pArrayListEmployee);
		for (i = 0; i < largoLL; i++) {
			auxEmpleado = ll_get(pArrayListEmployee, i);
			employee_getId(auxEmpleado, &id);
			retorno = i;
		}
	}
	return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList *pArrayListEmployee) {
	int retorno;
	retorno = -1;
	int auxMaxId;
	int largoLL;
	int id;
	int i;
	int opcionesSubmenuModificar;
	char auxNombre[1000];
	int auxHorasTrabajadas;
	int auxSueldo;
	Employee *auxEmpleado;
	int auxId;
	largoLL = ll_len(pArrayListEmployee);
	for (int i = 0; i < largoLL; i++) {
		auxEmpleado = ll_get(pArrayListEmployee, i);
		employee_getId(auxEmpleado, &auxId);
		if (auxId > auxMaxId) {
			auxMaxId = auxId;
		}
	}
	utn_getNumero(&id, "Ingrese Id del empleado a modificar\n",
			"Error, ingrese valor numerico\n", 0, auxMaxId, 2);
	for (i = 0; i < largoLL; i++) {
		auxEmpleado = ll_get(pArrayListEmployee, i);
		employee_getId(auxEmpleado, &auxId);

		if (auxId == id) {
			utn_getNumero(&opcionesSubmenuModificar,
					"\nIngrese que desea modificar \n1.Nombre\n2.Horas trabajadas\n3.Sueldo\n",
					"\nError, numero no válido\n", 1, 3, 2);
			switch (opcionesSubmenuModificar) {
			case 1:
				if (utn_getNombre(auxNombre,
						"\nIngrese el nombre del nuevo empleado\n",
						"\nError, nombre no válido\n", 2, 100) == 0
						&& employee_setNombre(auxEmpleado, auxNombre) == 0) {
					printf("\nEl nombre fue cambiado correctamente\n");
					retorno = 0;
				}
				break;
			case 2:
				if (utn_getNumero(&auxHorasTrabajadas,
						"\nIngrese las horas trabajadas del nuevo empleado\n",
						"\nError, numero no válido\n", 1, 1000, 2) == 0
						&& employee_setHorasTrabajadas(auxEmpleado,
								auxHorasTrabajadas) == 0) {
					printf(
							"\nLas horas trabajadas fueron cambiadas correctamente\n");
					retorno = 0;
				}
				break;
			case 3:
				if (utn_getNumero(&auxSueldo,
						"\nIngrese el sueldo del nuevo empleado\n",
						"\nError, numero no válido\n", 1, 10000, 2) == 0
						&& employee_setSueldo(auxEmpleado, auxSueldo) == 0) {
					printf("\nEl sueldo fue cambiado correctamente\n");
					retorno = 0;
				}
				break;
			}
		}
	}
	return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList *pArrayListEmployee) {
	int retorno;
	retorno = -1;
	Employee *auxEmpleado;
	int auxId;
	int id;
	int auxMaxId;
	int largoLL;
	int i;
	auxMaxId = controller_getMaxId(pArrayListEmployee);
	largoLL = ll_len(pArrayListEmployee);
	utn_getNumero(&id, "Ingrese Id de la persona que desea borrar",
			"Error, ingrese valor numerico\n", 1, auxMaxId, 2);
	largoLL = ll_len(pArrayListEmployee);
	for (i = 0; i < largoLL; i++) {
		auxEmpleado = ll_get(pArrayListEmployee, i);
		employee_getId(auxEmpleado, &auxId);
		if (auxId == id) {
			ll_remove(pArrayListEmployee, i);
			printf("\nEl empleado ha sido eliminado\n");
			retorno = 0;
			break;
		}
	}
	if (retorno == -1){
		printf("\nEl empleado no se pudo eliminar\n");
	}
	return retorno;

}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList *pArrayListEmployee) {
	int retorno;
	retorno = -1;
	int largoLL;
	int i;
	char auxNombre[1000];
	int auxhorasTrabajadas;
	int auxSueldo;
	int auxId;
	Employee *auxEmpleado = NULL;
	if (pArrayListEmployee != NULL) {
		largoLL = ll_len(pArrayListEmployee);
		printf(
				"------------------------------------------------------------------------------\n");
		printf("ID		NOMBRE		  HORAS TRABAJADAS	        SUELDO\n");
		printf(
				"------------------------------------------------------------------------------\n");
		for (i = 0; i < largoLL; i++) {
			auxEmpleado = ll_get(pArrayListEmployee, i);
			employee_getId(auxEmpleado, &auxId);
			employee_getNombre(auxEmpleado, auxNombre);
			employee_getHorasTrabajadas(auxEmpleado, &auxhorasTrabajadas);
			employee_getSueldo(auxEmpleado, &auxSueldo);
			printf("%-5d		%-15s		%4d			%-10d\n", auxId, auxNombre,
					auxhorasTrabajadas, auxSueldo);
			retorno = 0;
		}
	}
	return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList *pArrayListEmployee) {





	return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char *path, LinkedList *pArrayListEmployee) {
	int retorno;
	retorno = -1;
	int largoLL;
	char auxNombre[1000];
	int auxhorasTrabajadas;
	int auxSueldo;
	int auxId;
	int i;
	retorno = -1;
	Employee *auxEmpleado;
	if (path != NULL && pArrayListEmployee != NULL) {
		//ll_isEmpty devuelve -1 si es null, 1 si esta vacio y 0 si tiene contenido, de esta forma me avisa 1 sola vez la lectura correcta del archivo
		FILE *pFile = fopen(path, "w");
		if (pFile != NULL) {
			largoLL = ll_len(pArrayListEmployee);
			fprintf(pFile, "ID		NOMBRE		  HORAS TRABAJADAS	        SUELDO\n");
			for (i = 0; i < largoLL; i++) {
				auxEmpleado = ll_get(pArrayListEmployee, i);
				if (employee_getId(auxEmpleado, &auxId) == 0
						&& employee_getNombre(auxEmpleado, auxNombre) == 0
						&& employee_getHorasTrabajadas(auxEmpleado,
								&auxhorasTrabajadas) == 0
						&& employee_getSueldo(auxEmpleado, &auxSueldo) == 0) {
					fprintf(pFile, "%-5d		%-15s		%4d			%-10d\n", auxId,
							auxNombre, auxhorasTrabajadas, auxSueldo);
					retorno = 0;
				}
			}
			if (retorno == 0) {
				printf(
						"\nSe guardaron los datos de los empleados en el archivo data_copia.csv\n");
			}
		}
		fclose(pFile);
	}

	return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char *path, LinkedList *pArrayListEmployee) {
	int retorno;
	retorno = -1;
	int largoLL;
	int valorRetornado;
	int i;
	retorno = -1;
	Employee *auxEmpleado;
	if (path != NULL && pArrayListEmployee != NULL) {
		//ll_isEmpty devuelve -1 si es null, 1 si esta vacio y 0 si tiene contenido, de esta forma me avisa 1 sola vez la lectura correcta del archivo
		FILE *pFile = fopen(path, "wb");
		if (pFile != NULL) {
			largoLL = ll_len(pArrayListEmployee);
			for (i = 0; i < largoLL; i++) {
				auxEmpleado = ll_get(pArrayListEmployee, i);
				valorRetornado = fwrite(auxEmpleado, sizeof(Employee), 1,
						pFile);
				if (valorRetornado != 1) {
					puts(
							"\nError, no se pudo escribir en el archivo data.bin\n");
					break;
				} else {
					retorno = 0;
				}
			}
		}
		fclose(pFile);
	}

	return retorno;
}

