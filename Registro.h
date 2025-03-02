#ifndef REGISTRO_H // Si no se ha definido REGISTRO_H
#define REGISTRO_H // Define REGISTRO_H para evitar inclusiones m�ltiples

#include <iostream> // Incluye la librer�a iostream para entrada/salida est�ndar (no es estrictamente necesaria aqu�, pero es com�n incluirla)

// Definici�n de la estructura Registro
struct Registro {
    int id;         // Miembro id de tipo entero
    char nombre[30]; // Miembro nombre de tipo array de caracteres (string) de tama�o 30
    float salario;    // Miembro salario de tipo float
};

#endif // Fin del bloque #ifndef
#pragma once // Directiva de preprocesador que indica que el archivo actual solo debe incluirse una vez durante la compilaci�n. 
// Aunque #ifndef ya cumple esta funci�n, #pragma once es una forma m�s moderna y eficiente de hacerlo.