#ifndef REGISTRO_H // Si no se ha definido REGISTRO_H
#define REGISTRO_H // Define REGISTRO_H para evitar inclusiones múltiples

#include <iostream> // Incluye la librería iostream para entrada/salida estándar (no es estrictamente necesaria aquí, pero es común incluirla)

// Definición de la estructura Registro
struct Registro {
    int id;         // Miembro id de tipo entero
    char nombre[30]; // Miembro nombre de tipo array de caracteres (string) de tamaño 30
    float salario;    // Miembro salario de tipo float
};

#endif // Fin del bloque #ifndef
#pragma once // Directiva de preprocesador que indica que el archivo actual solo debe incluirse una vez durante la compilación. 
// Aunque #ifndef ya cumple esta función, #pragma once es una forma más moderna y eficiente de hacerlo.