#ifndef BUSQUEDA_H // Si no se ha definido BUSQUEDA_H
#define BUSQUEDA_H // Define BUSQUEDA_H para evitar inclusiones m�ltiples

#include "registro.h" // Incluye el archivo de encabezado "registro.h", que probablemente contiene la definici�n de la estructura o clase "Registro"

// Declaraci�n de la funci�n buscarPosicion
// Esta funci�n toma un entero idBuscado como argumento
// y devuelve un entero, que presumiblemente representa la posici�n del registro con el ID buscado
int buscarPosicion(int idBuscado);

#endif // Fin del bloque #ifndef
#pragma once // Directiva de preprocesador que indica que el archivo actual solo debe incluirse una vez durante la compilaci�n. 
// Aunque #ifndef ya cumple esta funci�n, #pragma once es una forma m�s moderna y eficiente de hacerlo.
