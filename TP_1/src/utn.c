/*
 * utn.c
 *
 *  Created on: 2 sep. 2021
 *      Author: Lucía
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"

/* Funcion usada para verificar el ingreso de caracteres. Chequea para que
 solo sean admitidas las letras S o N.
 Se ingresa void y devuelve un entero sin signo
 0 si se ingreso la N
 1 si se ingreso la S
 */
unsigned int verifica(void) {
	char letra;
	printf("\nIngrese opcion...S/N?");
	letra = toupper(getchar());
	while (!((letra == 'S') || (letra == 'N'))) {
		printf(
				"\nHa ingresado opci¢n no valida...Reintente el ingreso(S/N)... ");
		letra = toupper(getchar());
	}
	return (letra == 'S');
}
/*
 *
 * */
void getChar(char* mensaje, char* rta)
{
	printf("%s", mensaje);
	fflush(stdin);
	scanf("%c", rta);
}



/*
 * brief FACTORIAL
 * param n*: numero entero del que se quiere calcular el factorial
 * return: retorna el factorial del número, o 1 si el param n* era 1
 * */
int factorial(int* n) {
	int resp;
	if (*n == 1)
		return 1;
	resp = *n * factorial(n - 1);
	return (resp);
}

/**
 * \brief MYGETS: Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena
 * un máximo de 'longitud - 1' caracteres.
 * \param pResultado Puntero al espacio de memoria donde se copiara la cadena obtenida
 * \param longitud Define el tamaño de cadena
 * \return Retorna 0 (EXITO) si se obtiene una cadena y -1 (ERROR) si no
 *
 */
int myGets(char *cadena, int longitud) {
	if (cadena != NULL && longitud > 0
			&& fgets(cadena, longitud, stdin) == cadena) {
		fflush(stdin); // LINUX-> __fpurge o WIN-> fflush o MAC-> fpurge
		if (cadena[strlen(cadena) - 1] == '\n') {
			cadena[strlen(cadena) - 1] = '\0';
		}
		return 0;
	}
	return -1;
}
/**
 * \brief ESNUMERICA: Verifica si la cadena ingresada es numerica
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (vardadero) si la cadena es numerica y 0 (falso) si no lo es
 */
int esNumerica(char *cadena) {
	int i = 0;
	int retorno = 1;
	if (cadena != NULL && strlen(cadena) > 0) {
		while (cadena[i] != '\0') {
			if (cadena[i] < '0' || cadena[i] > '9') {
				retorno = 0;
				break;
			}
			i++;
		}
	}
	return retorno;
}
/**
 * \brief GETINT: Verifica si la cadena ingresada es numerica
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 *
 */
int getInt(int *pResultado) {
	int retorno = -1;
	char buffer[64];
	if (pResultado != NULL) {
		if (myGets(buffer, sizeof(buffer)) == 0 && esNumerica(buffer)) {
			*pResultado = atoi(buffer);
			retorno = 0;
		}
	}
	return retorno;
}
/**
 * \brief UTN_GETNUMERO: Solicita un numero al usuario, leuego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param minimo Es el numero maximo a ser aceptado
 * \param maximo Es el minimo minimo a ser aceptado
 * \return Retorna 0 si se obtuvo el numero y -1 si no
 */
int utn_getNumero(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos)
{
	int retorno = -1;
	int bufferInterno;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos>0)
	{

		do
		{
			printf("%s", mensaje);
			if(getInt(&bufferInterno)==0 && bufferInterno>=minimo && bufferInterno<=maximo)
			{
				*pResultado=bufferInterno;
				retorno=0;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}
		}while(reintentos>=0);
	}
	return retorno;
}


/*############################################################################################
 * ###############################TEMPERATURAS#######################################*/
/*############################################################################################

*
 * valido fahrenheit
 * */
int validarTemperaturaF(void)
{
	int temperaturaF;
	int retorno = -1;
	if(utn_getNumero(&temperaturaF, "Ingrese una temperatura Fahrenheit entre 32F y 212F\n", "Error, temperatura fuera de rango. Reintente.\n",
			32, 212, 2) == 0)
	{
		/*conversion a celsius*/
		printf("Se puede convertir a celsius");
		convertirTemperaturaFaC(&temperaturaF);
		retorno = 0;
	}
	return retorno;

}
/*
 * valido celsius
 * */
int validarTemperaturaC(void)
{
	int temperaturaC;
	int retorno = -1;
	if(utn_getNumero(&temperaturaC, "Ingrese una temperatura Celsius entre 0C y 100C\n", "Error, temperatura fuera de rango. Reintente.\n",
			0, 100, 2) == 0)
	{
		/*conversion a celsius*/
		printf("Se puede convertir a Fahrenheit");
		convertirTemperaturaCaF(&temperaturaC);
		retorno = 0;
	}
	return retorno;

}
/*
 * fn chequear si es celsius o fahrenheit
 *
 */
int validarEscalaTemperatura(void){
	int retorno = -1;
	char respuesta;
	getChar("Ingrese la escala de temperatura 'f' (fahrenheit) o 'c' (celsius)", &respuesta);
	fflush(stdin);
	if(respuesta == 'f' || respuesta == 'c'){
		retorno = 0;
		if(respuesta == 'f'){
			printf("La temperatura elegida es Fahrenheit.");
			validarTemperaturaF();
		}
		else {
			printf("La temperatura elegida es Celsius.");
			validarTemperaturaC();
		}
	}
	return retorno;
}

/*
 * conversion a celsius
 *
 */
int convertirTemperaturaFaC(int* temperaturaF){
	int resta;
	int multiplicacion;
	resta = *temperaturaF - 32;
	multiplicacion = resta * 5/9;
	printf("La temperatura fue convertida a Celsius: %d C", multiplicacion);
	return 0;
}
/*
 * conversion a fahrenheit
 *
 */
int convertirTemperaturaCaF(int* temperaturaC){
	int suma;
	int multiplicacion;
	multiplicacion = *temperaturaC * 9/5;
	suma =  multiplicacion + 32;
	printf("La temperatura fue convertida a Fahrenheit: %d F", suma);
	return 0;
}

/*
 * fn MENU
 *
 * */

/*
utn_getNumero
utn_getNumeroConSigno
utn_getNumeroConDecimales
utn_getTelefono
utn_getDNI
utn_getCUIT
utn_getEmail
utn_getTexto
*/
