#include "../insercion.h" // Incluye el archivo de encabezado "insercion.h", que contiene la declaración de la función insertarRegistro
#include <fstream> // Incluye la librería para el manejo de archivos (ofstream)

using namespace std; // Usa el espacio de nombres estándar para evitar prefijos std::

void insertarRegistro(Registro nuevo) { // Define la función insertarRegistro, que toma un objeto de tipo Registro llamado "nuevo" como argumento
    ofstream archivo("datos.dat", ios::binary | ios::app); // Abre el archivo "datos.dat" en modo binario para escritura y "append" (añadir al final)

    if (!archivo.is_open()) { // Verifica si el archivo se abrió correctamente
        cerr << "Error abriendo archivo!" << endl; // Imprime un mensaje de error en el flujo de error estándar (cerr) y añade un salto de línea (endl)
        return; // Sale de la función si no se pudo abrir el archivo
    }

    archivo.write(reinterpret_cast<char*>(&nuevo), sizeof(Registro)); // Escribe el registro "nuevo" en el archivo.  Es *esencial* usar reinterpret_cast al escribir datos binarios.
    archivo.close(); // Cierra el archivo después de escribir el registro
    cout << "Registro insertado correctamente!" << endl; // Imprime un mensaje indicando que el registro fue insertado correctamente
}