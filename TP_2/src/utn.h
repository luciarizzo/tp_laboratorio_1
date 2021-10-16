/*
 * utn.h
 *
 *  Created on: 2 sep. 2021
 *      Author: Lucía
 */

#ifndef UTN_H_
#define UTN_H_

/* Funcion usada para verificar el ingreso de caracteres.Chequea para que
 solo sean admitidas las letras S o N.
 Se ingresa void y devuelve un entero sin signo
 0 si se ingreso la N
 1 si se ingreso la S
 */
unsigned int verifica(void);

/*
 * brief FACTORIAL
 * param n*: numero entero del que se quiere calcular el factorial
 * return: retorna el factorial del número, o 1 si el param n* era 1
 * */
int factorial(int *n);

/**
 * \brief Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena
 * un máximo de 'longitud - 1' caracteres.
 * \param pResultado Puntero al espacio de memoria donde se copiara la cadena obtenida
 * \param longitud Define el tamaño de cadena
 * \return Retorna 0 (EXITO) si se obtiene una cadena y -1 (ERROR) si no
 *
 */
int myGets(char *cadena, int longitud);

/**
 * \brief Verifica si la cadena ingresada es numerica
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 *
 */
int getInt(int *pResultado);

/**
 * \brief Verifica si la cadena ingresada es numerica
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (vardadero) si la cadena es numerica y 0 (falso) si no lo es
 */
//int esNumerica(char *cadena);
int esNumerica(char* cadena);

/**
 * \brief Solicita un numero al usuario, leuego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param minimo Es el numero maximo a ser aceptado
 * \param maximo Es el minimo minimo a ser aceptado
 * \return Retorna 0 si se obtuvo el numero y -1 si no
 */
int utn_getNumero(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);


void getChar(char* mensaje, char* rta);

int getFloat(float* pResultado);

int getNombre(char* pResultado, int longitud);

int validarTemperaturaF(void);

int validarTemperaturaC(void);

int validarEscalaTemperatura(void);

int convertirTemperaturaFaC(int* temperaturaF);

int convertirTemperaturaCaF(int* temperaturaC);


/**
 * \brief Solicita un numero al usuario, leuego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param minimo Es el numero maximo a ser aceptado
 * \param maximo Es el minimo minimo a ser aceptado
 * \return Retorna 0 si se obtuvo el numero y -1 si no
 */

//void cargarArray(int array[], int tamanio);
/**
 * \brief Recorre el array buscando un número maximo
 * \param array[] array que se recorrerá en la fx
 * \param tamanio es el tamaño del array
 * \return Retorna el máximo encontrado.
 */
int buscarMaximo(int array[], int tamanio);

/**
 * \brief Permite la carga de los elementos del array
 * \param array[] array donde se cargarán los elementos
 * \param tamanio es el tamaño del array
 * \sin return, void (vacio).
 */
void cargarArray(int array[], int tamanio);
/**
 * \brief Imprime los elementos del array
 * \param array[] array a mostrar
 * \param tamanio es el tamaño del array
 * \sin return, void (vacio).
 */
void mostrarArray(int array[], int tamanio);

/**
 * \brief Muestra el índice del elemento de mayor valor del array
 * \param array[] array donde se cargarán los elementos
 * \param tamanio es el tamaño del array
 * \param maximo el máximo valor a encontrar en el array
 * \sin return, void (vacio).
 */
void mostrarIndiceMaximo(int array[], int tamanio, int maximo);

/*void contadorNumeros(int *contadorPositivos, int *contadorNegativos,
		int array[], int tamanio);*/

/**
 * \brief Cuenta numeros positivos y negativos del array
 * \param array[] array donde se contarán los positivos y negativos
 * \param tamanio es el tamaño del array
 * \sin return, void (vacio).
 */
void contadorNumerosPositivosNegativos(int array[], int tamanio);

/**
 * \brief Cuenta los numeros pares del array
 * \param *pPares Puntero donde se guardará la cantidad de numeros pares
 * \param array[] array donde se cargarán los elementos
 * \param tamanio es el tamaño del array
 * \sin return, void (vacio).
 */
void contadorPares(int *pPares, int array[], int tamanio);

/**
 * \brief Cuenta los numeros impares del array
 * \param *pImpares Puntero donde se guardará la cantidad de numeros impares
 * \param array[] array donde se cargarán los elementos
 * \param tamanio es el tamaño del array
 * \sin return, void (vacio).
 */
void contadorImpares(int *pImpares, int array[], int tamanio);

/**
 * \brief Muestra el contenido de las posiciones impares
 * \param array[] array donde se cargarán los elementos
 * \param tamanio es el tamaño del array
 * \sin return, void (vacio).
 */
void mostrarContenidoPosicionesImpares(int array[], int tamanio);

/**
 * \brief Suma los numeros pares
 * \param *pSumaPares Puntero donde se guardará la suma de numeros pares
 * \param array[] array donde se cargarán los elementos
 * \param tamanio es el tamaño del array
 * \sin return, void (vacio).
 */
void sumarNumerosPares(int *pSumaPares, int array[], int tamanio);

/**
 * \brief Ordena de manera descendente los elementos de un array
 * \param array[] array donde se cargarán los elementos
 * \param tamanio es el tamaño del array
 * \sin return, void (vacio).
 */
void ordenarDescendente(int array[], int tamanio);

/**
 * \brief Ordena de manera ascendente los elementos de un array
 * \param array[] array donde se cargarán los elementos
 * \param tamanio es el tamaño del array
 * \sin return, void (vacio).
 */
void ordenarAscendente(int array[], int tamanio);

/**
 * \brief Carga de manera paralela tres array
 * \param arrayUno[] primer array a ser cargado
 * \ param arrayDos[] segundo array a ser cargado
 * \ param arrayTres[] tercer array a ser cargado
 * \param tamanio es el tamaño del array
 * \sin return, void (vacio).
 */
void cargarArrayParalelo(int arrayUno[], int arrayDos[], int arrayTres[], int tamanio);

/**
 * \brief Ordena diferentes vectores
 * \param arrayUno[] primer array a ser ordenado
 * \ param arrayDos[] segundo array a ser ordenado
 * \ param arrayTres[] tercer array a ser ordenado
 * \param tamanio es el tamaño del array
 * \sin return, void (vacio).
 */
void ordenarVectores(int arrayUno[],int arrayDos[],int arrayTres[],int tamanio);
/**
 * \brief Muestra los vectores ordenados
 * \param arrayUno[] primer array ordenado
 * \ param arrayDos[] segundo array  ordenado
 * \ param arrayTres[] tercer array ordenado
 * \param tamanio es el tamaño del array
 * \sin return, void (vacio).
 */
void mostrarVectores(int arrayUno[],int arrayDos[],int arrayTres[],int tamanio);
/**
 * \brief Valida que sea un numero de telefono correcto
 * \param *cadena cadena de caracteres a ser validada
 * \return  devuelve 1 si es valida o 0 si no es válida
 */
int esTelefonoValido(char* cadena);
/**
 * \brief Valida que sea un numero flotante
 * \param *cadena cadena de caracteres a ser validada
 * \param longitud : es el tamaño del char cadena a ser validado
 * \return  devuelve 1 si es valida o 0 si no es válida
 */
int esFlotante(char* cadena, int longitud);
/**
 * \brief Valida que sea un nombre
 * \param *cadena cadena de caracteres a ser validada
 * \param longitud : es el tamaño del char cadena a ser validado
 * \return  devuelve 1 si es valida o 0 si no es válida
 */
int esNombre(char* cadena,int longitud);
/**
 * \brief Valida que sea solo una letra
 * \param *pResultado letra a ser validada
 * \return  devuelve 1 si es valida o 0 si no es válida
 */
int esSoloLetra(char *pResultado);
/**
 * \brief Valida que sea solo una letra con espacio
 * \param *pResultado letra a ser validada
 * \return  devuelve 1 si es valida o 0 si no es válida
 */
int esLetraConEspacio(char *pResultado);
/**
 * \brief Ingresa un cuit valido
 * \param *pResultado puntero donde se guardará el cuit
 * \param *mensaje cadena de caracteres con mensaje a ser mostrado
 * \param *mensajeError cadena de caracteres con mensaje de error a ser mostrado
 * \param reintentos numero de reintentos que se permitiran
 * \return  devuelve 1 si es valida o 0 si no es válida
 */
int utn_getCUIT(char *pResultado, char *mensaje, char *mensajeError,
		int reintentos);
/**
 * \brief Valida que sea un cuit
 * \param *cadena cadena de caracteres con el cuit a ser validado
 * \return  devuelve 1 si es valida o 0 si no es válida
 */
int esCUIT(char *cadena);
/**
 * \brief ingresa un numero de telefono
 * \param *pResultado puntero donde se guardará el telefono
 * \param *mensaje cadena de caracteres con mensaje a ser mostrado
 * \param *mensajeError cadena de caracteres con mensaje de error a ser mostrado
 * \param minSize numero minimo para validar el numero
 * \param maxSize numero maximo para validar el numero
 * \param min numero minimo para validar el numero
 * \para max numero maximo para validar el numero
 * \param reintentos numero de reintentos que se permitiran
 * \return  devuelve 1 si es valida o 0 si no es válida
 */
int utn_getTelefono(char *pResultado, char *mensaje, char *mensajeError,
		int minSize, int maxSize, int min, int max, int reintentos);
/**
 * \brief Ingresa un nombre
 * \param *pResultado puntero donde se guardará el telefono
 * \param *mensaje cadena de caracteres con mensaje a ser mostrado
 * \param *mensajeError cadena de caracteres con mensaje de error a ser mostrado
 * \param reintentos numero de reintentos que se permitiran
 * \param longitud: longitud del nombre
 * \return  devuelve 1 si es valida o 0 si no es válida
 */
int utn_getNombre(char *pResultado, char *mensaje, char *mensajeError,
		int reintentos, int longitud);
/**
 * \brief Ingresa un string
 * \param aux[] variable donde se guardará la cadena de caracteres
 * \param *mensaje cadena de caracteres con mensaje a ser mostrado
 * \param *mensajeError cadena de caracteres con mensaje de error a ser mostrado
 * \param reintentos numero de reintentos que se permitiran
 * \return  devuelve 0 si es se pudo ingresar o -1 si no
 */
int utn_getString(char aux[], char *mensaje, char *mensajeError, int reintentos);
/**
 * \brief Ingresa un caracteres para elegir F o M
 * \param *pResultado donde se guardará el caracter elegido
 * \param *mensaje cadena de caracteres con mensaje a ser mostrado
 * \param *mensajeError cadena de caracteres con mensaje de error a ser mostrado
 * \param reintentos numero de reintentos que se permitiran
 * \return  devuelve 0 si es se pudo ingresar o -1 si no
 */
int utn_getCaracterSexo(char *pResultado, char *mensaje, char *mensajeError,
		char string[][20], int cantidadArray, int reintentos);
/**
 * \brief Ingresa un caracteres para elegir Si o No
 * \return  devuelve 0 si es se pudo ingresar o -1 si no
 */
int utn_getCaracterSiNo(void);
/**
 * \brief Ingresa un caracter
 * \param *pResultado puntero donde se guardará el caracter
 * \param *mensaje cadena de caracteres con mensaje a ser mostrado
 * \param *mensajeError cadena de caracteres con mensaje de error a ser mostrado
 * \param reintentos numero de reintentos que se permitiran
 * \return  devuelve 0 si es se pudo ingresar o -1 si no
 */
int utn_getCaracter(char *pResultado, char *mensaje, char *mensajeError,
		char string[][20], int cantidadArray, int reintentos);
/**
 * \brief Ingresa un numero flotante
 * \param *pResultado puntero donde se guardará el numero flotante
 * \param *mensaje cadena de caracteres con mensaje a ser mostrado
 * \param *mensajeError cadena de caracteres con mensaje de error a ser mostrado
 * \param minimo numero minimo permitido
 * \param maximo numero maximo permitido
 * \param reintentos numero de reintentos que se permitiran
 * \return  devuelve 0 si es se pudo ingresar o -1 si no
 */
int utn_getNumeroFlotante(float *pResultado, char *mensaje, char *mensajeError,
		float minimo, float maximo, int reintentos);
/**
 * \brief Ingresa un nombre
 * \param *pResultado puntero donde se guardará el telefono
 * \param *mensaje cadena de caracteres con mensaje a ser mostrado
 * \param *mensajeError cadena de caracteres con mensaje de error a ser mostrado
 * \param reintentos numero de reintentos que se permitiran
 * \param longitud: longitud del nombre
 * \return  devuelve 1 si es valida o 0 si no es válida
 */
int utn_getNombre(char *pResultado, char *mensaje, char *mensajeError,
		int reintentos, int longitud);
/**
 * \brief Valida que sea un DNI
 * \param *cadena cadena de caracteres con el DNI a validar
 * \return  devuelve 1 si es valida o 0 si no es válida
 */
int esDNI(char *cadena);
/**
 * \brief Ingresa un DNI
 * \param *pResultado puntero donde se guardará el DNI
 * \param *mensaje cadena de caracteres con mensaje a ser mostrado
 * \param *mensajeError cadena de caracteres con mensaje de error a ser mostrado
 * \param reintentos numero de reintentos que se permitiran
 * \return  devuelve 1 si es valida o 0 si no es válida
 */
int utn_getDNI(char *pResultado, char *mensaje, char *mensajeError,
		int reintentos);

#endif /* UTN_H_ */
