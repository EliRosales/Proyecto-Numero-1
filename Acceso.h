#ifndef ACCESO_H // Si no se ha definido ACCESO_H
#define ACCESO_H // Define ACCESO_H para evitar inclusiones múltiples

#include "registro.h" // Incluye el archivo de encabezado "registro.h", que presumiblemente contiene la definición de la estructura o clase "Registro"
#include <fstream> // Incluye la librería para el manejo de archivos (ifstream)

// Declaración de la función leerArchivo
// Esta función no toma ningún argumento y no devuelve ningún valor (void)
void leerArchivo();

// Declaración de la función buscarPorID
// Esta función toma un entero idBuscado como argumento
// y no devuelve ningún valor (void)
void buscarPorID(int idBuscado);

#endif // Fin del bloque #ifndef
#pragma once // Directiva de preprocesador que indica que el archivo actual solo debe incluirse una vez durante la compilación. 
// Aunque #ifndef ya cumple esta función, #pragma once es una forma más moderna y eficiente de hacerlo.