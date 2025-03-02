#ifndef INSERCION_H // Si no se ha definido INSERCION_H
#define INSERCION_H // Define INSERCION_H para evitar inclusiones múltiples

#include "registro.h" // Incluye el archivo de encabezado "registro.h", que presumiblemente contiene la definición de la estructura o clase "Registro"

// Declaración de la función insertarRegistro
// Esta función toma un objeto de tipo Registro llamado "nuevo" como argumento
// y no devuelve ningún valor (void)
void insertarRegistro(Registro nuevo);

#endif // Fin del bloque #ifndef
#pragma once // Directiva de preprocesador que indica que el archivo actual solo debe incluirse una vez durante la compilación. 
// Aunque #ifndef ya cumple esta función, #pragma once es una forma más moderna y eficiente de hacerlo.