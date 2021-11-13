#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

/*
 * \brief Elimina un empleado
 * \param Employee* this puntero a empleado
 */
void employee_delete(Employee* this);
/*
 * \brief Asigna el espacio en memoria para el empleado y le inicializa valores
 * \return retorna un puntero a Employee
 */
Employee* employee_new();
/*
 * \brief Asigna los parametros correspondientes al empleado
 * \return retorna un puntero a Employee
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);
/*
 * \brief Asigna el ID al empleado
 * \param Employee * this puntero a empleado
 * \param int id id del empleado a setear
 * \return retorna un 0 si pudo asignar, -1 si no.
 */
int employee_setId(Employee* this,int id);
/*
 * \brief Obtiene el ID del empleado
 * \param Employee* this puntero a empleado
 * \param int id id del empleado a obtener
 * \return retorna un 0 si pudo obtener, -1 si no
 */
int employee_getId(Employee* this,int* id);
/*
 * \brief Asigna el nombre al empleado
 * \param Employee * this puntero a empleado
 * \param char* nombre del empleado a setear
 * \return retorna un 0 si pudo asignar, -1 si no.
 */
int employee_setNombre(Employee* this,char* nombre);
/*
 * \brief Obtiene el nombre del empleado
 * \param Employee* this puntero a empleado
 * \param char* nombre nombre del empleado a obtener
 * \return retorna un 0 si pudo obtener, -1 si no
 */
int employee_getNombre(Employee* this,char* nombre);
/*
 * \brief Asigna las horas trabajadas al empleado
 * \param Employee * this puntero a empleado
 * \param int horasTrabajadas del empleado a setear
 * \return retorna un 0 si pudo asignar, -1 si no.
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
/*
 * \brief Obtiene las horas trabajadas del empleado
 * \param Employee* this puntero a empleado
 * \param int* horasTrabajadas horas trabajadas del empleado a obtener
 * \return retorna un 0 si pudo obtener, -1 si no
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);
/*
 * \brief Asigna el sueldo al empleado
 * \param Employee * this puntero a empleado
 * \param int sueldo sueldo del empleado a setear
 * \return retorna un 0 si pudo asignar, -1 si no.
 */
int employee_setSueldo(Employee* this,int sueldo);
/*
 * \brief Obtiene el sueldo del empleado
 * \param Employee* this puntero a empleado
 * \param int* sueldo sueldo del empleado a obtener
 * \return retorna un 0 si pudo obtener, -1 si no
 */
int employee_getSueldo(Employee* this,int* sueldo);
/*
 * \brief Compara los ID de los empleados
 * \param void* paramUno primer parametro a comparar
 * \param void* paramDos segundo parametro a comparar
 * \return retorna un -1 (descendente), 1 (ascendente) si pudo obtener, 0 si no
 */
int employee_sortById(void *paramUno, void *paramDos);
/*
 * \brief Compara los nombre de los empleados
 * \param void* paramUno primer parametro a comparar
 * \param void* paramDos segundo parametro a comparar
 * \return retorna un -1 (descendente), 1 (ascendente) si pudo obtener, 0 si no
 */
int employee_sortByNombre(void* paramUno, void* paramDos);
/*
 * \brief Compara las horas trabajadas de los empleados
 * \param void* paramUno primer parametro a comparar
 * \param void* paramDos segundo parametro a comparar
 * \return retorna un -1 (descendente), 1 (ascendente) si pudo obtener, 0 si no
 */
int employee_sortByHorasTrabajadas(void* paramUno, void *paramDos);
/*
 * \brief Compara los sueldos de los empleados
 * \param void* paramUno primer parametro a comparar
 * \param void* paramDos segundo parametro a comparar
 * \return retorna un -1 (descendente), 1 (ascendente) si pudo obtener, 0 si no
 */
int employee_sortBySueldo(void* paramUno, void *paramDos);

#endif // employee_H_INCLUDED
