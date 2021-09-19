/*
 * operaciones.h
 *
 *  Created on: 2 sep. 2021
 *      Author: Lucía
 */

#ifndef OPERACIONES_H_
#define OPERACIONES_H_

/*
 * brief suma de dos números enteros
 * param1 recibe un entero
 * param2 recibe el entero a sumar
 * return devuelve el resultado de la suma
 */
int sumar(int primerNumero, int segundoNumero);
/* brief: resta de dos números enteros
 * param1: recibe un entero
 * param2: recibe un entero a restar
 * return: devuelve el resultado de la resta
 */
int restar(int primerNumero, int segundoNumero);
/*
 * brief: divide entre dos números enteros
 * param1: recibe un entero
 * param2: recibe un entero a dividir
 * return: devuelve el resultado de la division
 */
float dividir(int primerNumero, int segundoNumero);
/*
 * brief: multiplica dos números enteros
 * param1: recibe un entero
 * param2: recibe un entero a multiplicar
 * return: devuelve el resultado de la multiplicacion
 */
float multiplicar(int primerNumero, int segundoNumero);
/*
 * brief: realiza el factorial de un número entero
 * param1: recibe un entero
 * return: devuelve el resultado del factorial
 */
int realizarFactorial(int numero);


#endif /* OPERACIONES_H_ */
