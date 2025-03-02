#ifndef MODIFICACION_H // Si no se ha definido MODIFICACION_H
#define MODIFICACION_H // Define MODIFICACION_H para evitar inclusiones m�ltiples

#include "registro.h" // Incluye el archivo de encabezado "registro.h", que presumiblemente contiene la definici�n de la estructura o clase "Registro"

// Declaraci�n de la funci�n modificarRegistro
// Esta funci�n toma un objeto de tipo Registro llamado "modificado" como argumento
// y no devuelve ning�n valor (void)
void modificarRegistro(Registro modificado);

#endif // Fin del bloque #ifndef
#pragma once // Directiva de preprocesador que indica que el archivo actual solo debe incluirse una vez durante la compilaci�n. 
// Aunque #ifndef ya cumple esta funci�n, #pragma once es una forma m�s moderna y eficiente de hacerlo.