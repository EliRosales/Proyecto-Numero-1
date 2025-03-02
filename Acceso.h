#ifndef ACCESO_H // Si no se ha definido ACCESO_H
#define ACCESO_H // Define ACCESO_H para evitar inclusiones m�ltiples

#include "registro.h" // Incluye el archivo de encabezado "registro.h", que presumiblemente contiene la definici�n de la estructura o clase "Registro"
#include <fstream> // Incluye la librer�a para el manejo de archivos (ifstream)

// Declaraci�n de la funci�n leerArchivo
// Esta funci�n no toma ning�n argumento y no devuelve ning�n valor (void)
void leerArchivo();

// Declaraci�n de la funci�n buscarPorID
// Esta funci�n toma un entero idBuscado como argumento
// y no devuelve ning�n valor (void)
void buscarPorID(int idBuscado);

#endif // Fin del bloque #ifndef
#pragma once // Directiva de preprocesador que indica que el archivo actual solo debe incluirse una vez durante la compilaci�n. 
// Aunque #ifndef ya cumple esta funci�n, #pragma once es una forma m�s moderna y eficiente de hacerlo.