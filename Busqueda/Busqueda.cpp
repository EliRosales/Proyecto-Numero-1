#include "../busqueda.h" // Incluye el archivo de encabezado "busqueda.h", que contiene la declaración de la función buscarPosicion
#include <fstream> // Incluye la librería para el manejo de archivos (ifstream)
#include "../Registro.h" // Incluye el archivo de encabezado "Registro.h", que define la estructura o clase "Registro"

using namespace std; // Utiliza el espacio de nombres estándar para evitar prefijos std::

int buscarPosicion(int idBuscado) { // Define la función buscarPosicion que toma un entero idBuscado como argumento
    ifstream archivo("datos.dat", ios::binary); // Abre el archivo "datos.dat" en modo binario para lectura

    // Si el archivo no se pudo abrir, retorna -1 indicando un error
    if (!archivo.is_open()) return -1; // Verifica si el archivo se abrió correctamente. Si no, retorna -1 para indicar un error.

    Registro reg;  // Variable donde se almacenará temporalmente cada registro leído
    int pos = 0;    // Contador de posición para identificar en qué índice está el registro buscado

    // Lee el archivo registro por registro hasta llegar al final
    while (archivo.read(reinterpret_cast<char*>(&reg), sizeof(Registro))) { // Lee registros del archivo "datos.dat" hasta el final del archivo. Se usa reinterpret_cast para convertir el puntero a char*.

        if (reg.id == idBuscado) { // Si el ID del registro leído coincide con el ID buscado
            archivo.close(); // Cierra el archivo antes de salir
            return pos;      // Retorna la posición donde se encontró el registro
        }
        pos++; // Si no es el registro buscado, aumenta la posición y sigue leyendo
    }

    archivo.close(); // Cierra el archivo al finalizar la busqueda
    return -1;      // Si no se encontro el ID retorna -1 
}