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


int initEmployees(Employee lista[], int len);
int altaEmpleado (Employee lista[], int len);
Employee addEmployee();
int findEmployeeById(Employee lista[], int len);
int removeEmployee(Employee lista[], int len);
int modifiedEmployeeName(Employee lista[], int len);
int modifiedEmployeeLastName(Employee lista[], int len);
int modifiedEmployeeSalary(Employee lista[], int len);
int modifiedEmployeeSectorId(Employee lista[], int len);
void sortEmployeesbySector(Employee lista[], int len);
void sortEmployeesbyLastName(Employee lista[], int len);
void print1Employee(Employee unEmpleado);
int printEmployees (Employee lista[], int len);
float totalSalarios(Employee lista[], int len);
float promedioSalarios(Employee lista[], int len);


#endif /* ARRAYEMPLOYEES_H_ */
