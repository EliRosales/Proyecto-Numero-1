#include "../Acceso.h" // Incluye el archivo de encabezado "Acceso.h", que contiene las declaraciones de las funciones leerArchivo y buscarPorID
#include <iostream> // Incluye la librería para entrada y salida de datos (cout, cerr)

using namespace std; // Usa el espacio de nombres estándar para evitar escribir std:: antes de cout, cerr, etc.

void leerArchivo() { // Define la función leerArchivo, que no toma argumentos ni devuelve ningún valor (void)
    ifstream archivo("datos.dat", ios::binary); // Abre el archivo "datos.dat" en modo binario para lectura

    if (!archivo.is_open()) { // Verifica si el archivo se abrió correctamente
        cerr << "Error abriendo archivo!" << endl; // Imprime un mensaje de error en el flujo de error estándar (cerr) y añade un salto de línea (endl)
        return; // Sale de la función si no se pudo abrir el archivo
    }

    Registro reg; // Declara una variable de tipo Registro para almacenar los registros leídos del archivo

    while (archivo.read(reinterpret_cast<char*>(&reg), sizeof(Registro))) { // Lee registros del archivo hasta el final del archivo
        // Imprime los datos de cada registro leído
        cout << "\nID: " << reg.id
            << "\nNombre: " << reg.nombre
            << "\nSalario: " << reg.salario << endl;
    }

    archivo.close(); // Cierra el archivo después de leer todos los registros
}

void buscarPorID(int idBuscado) { // Define la función buscarPorID, que toma un entero idBuscado como argumento y no devuelve ningún valor (void)
    ifstream archivo("datos.dat", ios::binary); // Abre el archivo "datos.dat" en modo binario para lectura

    if (!archivo.is_open()) { // Verifica si el archivo se abrió correctamente
        cerr << "Error abriendo archivo!" << endl; // Imprime un mensaje de error en el flujo de error estándar (cerr) y añade un salto de línea (endl)
        return; // Sale de la función si no se pudo abrir el archivo
    }

    Registro reg; // Declara una variable de tipo Registro para almacenar el registro leído del archivo
    bool encontrado = false; // Declara una variable booleana para indicar si se encontró el registro

    // Lee registros del archivo hasta el final del archivo o hasta que se encuentre el registro buscado
    while (archivo.read(reinterpret_cast<char*>(&reg), sizeof(Registro)) && !encontrado) {
        if (reg.id == idBuscado) { // Si el ID del registro leído coincide con el ID buscado
            // Imprime los datos del registro encontrado
            cout << "\nRegistro encontrado:"
                << "\nNombre: " << reg.nombre
                << "\nSalario: " << reg.salario << endl;
            encontrado = true; // Marca la variable "encontrado" como verdadera para detener el bucle
        }
    }

    if (!encontrado) { // Si no se encontró el registro después de leer todo el archivo
        cout << "Registro no encontrado!" << endl; // Imprime un mensaje indicando que no se encontró el registro
    }

    archivo.close(); // Cierra el archivo después de la búsqueda
}