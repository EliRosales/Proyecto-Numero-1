#include "../busqueda.h" // Incluye el archivo de encabezado "busqueda.h", que contiene la declaraci�n de la funci�n buscarPosicion
#include <fstream> // Incluye la librer�a para el manejo de archivos (ifstream)
#include "../Registro.h" // Incluye el archivo de encabezado "Registro.h", que define la estructura o clase "Registro"

using namespace std; // Utiliza el espacio de nombres est�ndar para evitar prefijos std::

int buscarPosicion(int idBuscado) { // Define la funci�n buscarPosicion que toma un entero idBuscado como argumento
    ifstream archivo("datos.dat", ios::binary); // Abre el archivo "datos.dat" en modo binario para lectura

    // Si el archivo no se pudo abrir, retorna -1 indicando un error
    if (!archivo.is_open()) return -1; // Verifica si el archivo se abri� correctamente. Si no, retorna -1 para indicar un error.

    Registro reg;  // Variable donde se almacenar� temporalmente cada registro le�do
    int pos = 0;    // Contador de posici�n para identificar en qu� �ndice est� el registro buscado

    // Lee el archivo registro por registro hasta llegar al final
    while (archivo.read(reinterpret_cast<char*>(&reg), sizeof(Registro))) { // Lee registros del archivo "datos.dat" hasta el final del archivo. Se usa reinterpret_cast para convertir el puntero a char*.

        if (reg.id == idBuscado) { // Si el ID del registro le�do coincide con el ID buscado
            archivo.close(); // Cierra el archivo antes de salir
            return pos;      // Retorna la posici�n donde se encontr� el registro
        }
        pos++; // Si no es el registro buscado, aumenta la posici�n y sigue leyendo
    }

    archivo.close(); // Cierra el archivo al finalizar la busqueda
    return -1;      // Si no se encontro el ID retorna -1 
}