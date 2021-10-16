/*
 * informes.h
 *
 *  Created on: 9 oct. 2021
 *      Author: Lucía
 */

#ifndef INFORMES_H_
#define INFORMES_H_
#include "arrayEmployees.h"
/**
 * \brief Imprime los empleados ordenados por apellido, y si este coincide, los ordena por sector
 * \param lista[] array de empleados
 * \parm len longitud del array
 * \return void (vacio)
 *  */
void printEmployeesbyLastNameOrSector(Employee lista[], int len);
/**
 * \brief Imprime el total de los salarios de los empleados
 * \param lista[] array de empleados
 * \parm len longitud del array
 * \return void (vacio)
 *  */
void printTotal(Employee lista[], int len);
/**
 * \brief Imprime el promedio de salarios de los empleados
 * \param lista[] array de empleados
 * \parm len longitud del array
 * \return void (vacio)
 *  */
void printPromedio(Employee lista[], int len);
/**
 * \brief Imprime la cantidad de empleados que superan el salario promedio
 * \param lista[] array de empleados
 * \parm len longitud del array
 * \return void (vacio)
 *  */
void printEmployeesSuperiorSalary(Employee lista[], int len);

#endif /* INFORMES_H_ */
