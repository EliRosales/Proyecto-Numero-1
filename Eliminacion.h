#ifndef ELIMINACION_H // Si no se ha definido ELIMINACION_H
#define ELIMINACION_H // Define ELIMINACION_H para evitar inclusiones múltiples

// Declaración de la función eliminarRegistro
// Esta función toma un entero idEliminar como argumento
// y no devuelve ningún valor (void)
void eliminarRegistro(int idEliminar);

#endif // Fin del bloque #ifndef
#pragma once // Directiva de preprocesador que indica que el archivo actual 
// solo debe incluirse una vez durante la compilación.
// Aunque #ifndef ya cumple esta función, #pragma once es una 
// forma más moderna y eficiente de hacerlo.