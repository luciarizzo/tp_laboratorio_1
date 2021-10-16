/*
 * arrayEmployees.h
 *
 *  Created on: 8 oct. 2021
 *      Author: Lucía
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

typedef struct{
	int idEmployee;
	char nameEmployee[51];
	char lastNameEmployee[51];
	float salaryEmployee;
	int sectorIdEmployee;
	int isEmpty;//si es 1, la estructura esta libre par anueva carga, si es 0 esta ocupada
}Employee;

/**
 * \brief Iniciliza el array de empleados
 * \param lista[] array de empleados a ser inicialiado
 * \param len longitud del array
 * \return  devuelve -1 si no se pudo hacer o 0 si pudo
 */
int initEmployees(Employee lista[], int len);
/**
 * \brief Permite el alta de un empleado
 * \param lista[] array de empleados para dar de alta
 * \param len longitud del array
 * \return  devuelve el indice donde cargó el empleado
 *  */
int altaEmpleado (Employee lista[], int len);
/**
 * \brief Permite ingresar los datos del empleado
 * \return Employee devuelve el empleado ingresado
 *  */
Employee addEmployee();
/**
 * \brief Permite encontrar un empleado por su ID
 * \param lista[] array de empleados para buscar
 * \param len longitud del array
 * \return  devuelve -1 si no pudo encontrarlo o 0 si pudo encontrarlo
 *  */
int findEmployeeById(Employee lista[], int len);
/**
 * \brief Permite eliminar un empleado
 * \param lista[] array de empleados
 * \param len longitud del array
 * \return  devuelve -1 si no pudo eliminarlo o 0 si pudo eliminarlo
 *  */
int removeEmployee(Employee lista[], int len);
/**
 * \brief Permite modificar el nombre del empleado
 * \param lista[] array de empleados
 * \param len longitud del array
 * \return  devuelve 0 si no pudo modificarlo o 1 si pudo modificarlo
 *  */
int modifiedEmployeeName(Employee lista[], int len);
/**
 * \brief Permite modificar el apellido del empleado
 * \param lista[] array de empleados
 * \param len longitud del array
 * \return  devuelve 0 si no pudo modificarlo o 1 si pudo modificarlo
 *  */
int modifiedEmployeeLastName(Employee lista[], int len);
/**
 * \brief Permite modificar el salario del empleado
 * \param lista[] array de empleados
 * \param len longitud del array
 * \return  devuelve 0 si no pudo modificarlo o 1 si pudo modificarlo
 *  */
int modifiedEmployeeSalary(Employee lista[], int len);
/**
 * \brief Permite modificar el ID SECTOR del empleado
 * \param lista[] array de empleados
 * \param len longitud del array
 * \return  devuelve 0 si no pudo modificarlo o 1 si pudo modificarlo
 *  */
int modifiedEmployeeSectorId(Employee lista[], int len);

/**
 * \brief Permite ordenar los empleados por apellido (alfabeticamente) y si este coincide, lo ordena por sector
 * \param lista[] array de empleados
 * \param len longitud del array
 * \return void (vacio)
 *  */
void sortEmployeesbyLastNameOrSector(Employee lista[], int len);
/**
 * \brief Imprime los datos de un empleado
 * \param unEmpleado variable a ser impresa
 * \return void (vacio)
 *  */

void print1Employee(Employee unEmpleado);
/**
 * \brief Imprime los datos de varios empleados
 * \param lista[] array de empleados
 * \parm len longitud del array
 * \return void (vacio)
 *  */
int printEmployees (Employee lista[], int len);
/**
 * \brief Calcula el total de los salarios de los empleados
 * \param lista[] array de empleados
 * \parm len longitud del array
 * \return devuelve el total de salarios
 *  */
float totalSalarios(Employee lista[], int len);
/**
 * \brief Calcula el promedio de los salarios de los empleados
 * \param lista[] array de empleados
 * \parm len longitud del array
 * \return devuelve el promedio
 *  */
float promedioSalarios(Employee lista[], int len);
/**
 * \brief Compara y determina cuántos empleados superan el salario promedio
 * \param lista[] array de empleados
 * \parm len longitud del array
 * \return devuelve la cantidad que superan el salario promedio
 *  */
int superanSalarioPromedio(Employee lista[], int len);

#endif /* ARRAYEMPLOYEES_H_ */
