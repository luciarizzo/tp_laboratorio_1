/*
 ============================================================================
 Name        : TP_2.c
 Author      : Lucia
 Version     :
 Copyright   : Your copyright notice
 Description :

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "menu.h"


int main(void) {
	setbuf(stdout, NULL);

	mostrarMenu("\nIngrese un número para elegir una opción: \n1-Dar alta empleado \n2-Modificar \n3-Dar de baja empleado \n4-Informar \n5-Salir\n",
			5);

	EXIT_SUCCESS;
}
