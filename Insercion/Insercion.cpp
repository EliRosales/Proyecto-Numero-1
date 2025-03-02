#include "../insercion.h" // Incluye el archivo de encabezado "insercion.h", que contiene la declaraci�n de la funci�n insertarRegistro
#include <fstream> // Incluye la librer�a para el manejo de archivos (ofstream)

using namespace std; // Usa el espacio de nombres est�ndar para evitar prefijos std::

void insertarRegistro(Registro nuevo) { // Define la funci�n insertarRegistro, que toma un objeto de tipo Registro llamado "nuevo" como argumento
    ofstream archivo("datos.dat", ios::binary | ios::app); // Abre el archivo "datos.dat" en modo binario para escritura y "append" (a�adir al final)

    if (!archivo.is_open()) { // Verifica si el archivo se abri� correctamente
        cerr << "Error abriendo archivo!" << endl; // Imprime un mensaje de error en el flujo de error est�ndar (cerr) y a�ade un salto de l�nea (endl)
        return; // Sale de la funci�n si no se pudo abrir el archivo
    }

    archivo.write(reinterpret_cast<char*>(&nuevo), sizeof(Registro)); // Escribe el registro "nuevo" en el archivo.  Es *esencial* usar reinterpret_cast al escribir datos binarios.
    archivo.close(); // Cierra el archivo despu�s de escribir el registro
    cout << "Registro insertado correctamente!" << endl; // Imprime un mensaje indicando que el registro fue insertado correctamente
}