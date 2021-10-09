/*
 * menu.c
 *
 *  Created on: 8 oct. 2021
 *      Author: Luc�a
 */
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include <string.h>

void mostrarMenu(int* pMenu, char* mensaje, int cantidadOpciones){
	int flagPrimerEjecucion;
	flagPrimerEjecucion = 0;
	int opcion;
	opcion = *pMenu;
	if(pMenu != NULL && mensaje != NULL){
		do {
			if (flagPrimerEjecucion == 0) {
				printf("BIENVENIDO. POR FAVOR, ELIJA UNA OPCI�N:");
				flagPrimerEjecucion = 1;
			}
			if(utn_getNumero(&opcion, mensaje, "\n La opci�n ingresada no est� dentro del rango solicitado", 0, cantidadOpciones, 3) == 0)
			{
				*pMenu = opcion;
			} else {
				printf("\n Error, ingrese un n�mero v�lido para el men�.");
			}

		}while(opcion != cantidadOpciones);
	}
}
