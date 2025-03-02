#ifndef BUSQUEDA_H // Si no se ha definido BUSQUEDA_H
#define BUSQUEDA_H // Define BUSQUEDA_H para evitar inclusiones múltiples

#include "registro.h" // Incluye el archivo de encabezado "registro.h", que probablemente contiene la definición de la estructura o clase "Registro"

// Declaración de la función buscarPosicion
// Esta función toma un entero idBuscado como argumento
// y devuelve un entero, que presumiblemente representa la posición del registro con el ID buscado
int buscarPosicion(int idBuscado);

#endif // Fin del bloque #ifndef
#pragma once // Directiva de preprocesador que indica que el archivo actual solo debe incluirse una vez durante la compilación. 
// Aunque #ifndef ya cumple esta función, #pragma once es una forma más moderna y eficiente de hacerlo.
