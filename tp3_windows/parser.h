/*
 * parser.h
 *
 *  Created on: 9 nov. 2021
 *      Author: Lucía
 */

#ifndef PARSER_H_
#define PARSER_H_

/** \brief Parsea los datos de los empleados desde el archivo data.csv (modo texto).
 * \param path char* puntero al path del archivo a parsear
 * \param pArrayListEmployee LinkedList* puntero a LinkedList
 * \return int retorna -1 si no pudo parsear, 0 si pudo parsear
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 * \param path char* puntero al path del archivo a parsear
 * \param pArrayListEmployee LinkedList* puntero a LinkedList
 * \return int retorna -1 si no pudo parsear o 0 si pudo parsear
 */
int parser_EmployeeFromBinary(FILE *pFile, LinkedList *pArrayListEmployee);

#endif /* PARSER_H_ */
