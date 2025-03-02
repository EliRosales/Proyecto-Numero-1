#include "../Acceso.h" // Incluye el archivo de encabezado "Acceso.h", que contiene las declaraciones de las funciones leerArchivo y buscarPorID
#include <iostream> // Incluye la librer�a para entrada y salida de datos (cout, cerr)

using namespace std; // Usa el espacio de nombres est�ndar para evitar escribir std:: antes de cout, cerr, etc.

void leerArchivo() { // Define la funci�n leerArchivo, que no toma argumentos ni devuelve ning�n valor (void)
    ifstream archivo("datos.dat", ios::binary); // Abre el archivo "datos.dat" en modo binario para lectura

    if (!archivo.is_open()) { // Verifica si el archivo se abri� correctamente
        cerr << "Error abriendo archivo!" << endl; // Imprime un mensaje de error en el flujo de error est�ndar (cerr) y a�ade un salto de l�nea (endl)
        return; // Sale de la funci�n si no se pudo abrir el archivo
    }

    Registro reg; // Declara una variable de tipo Registro para almacenar los registros le�dos del archivo

    while (archivo.read(reinterpret_cast<char*>(&reg), sizeof(Registro))) { // Lee registros del archivo hasta el final del archivo
        // Imprime los datos de cada registro le�do
        cout << "\nID: " << reg.id
            << "\nNombre: " << reg.nombre
            << "\nSalario: " << reg.salario << endl;
    }

    archivo.close(); // Cierra el archivo despu�s de leer todos los registros
}

void buscarPorID(int idBuscado) { // Define la funci�n buscarPorID, que toma un entero idBuscado como argumento y no devuelve ning�n valor (void)
    ifstream archivo("datos.dat", ios::binary); // Abre el archivo "datos.dat" en modo binario para lectura

    if (!archivo.is_open()) { // Verifica si el archivo se abri� correctamente
        cerr << "Error abriendo archivo!" << endl; // Imprime un mensaje de error en el flujo de error est�ndar (cerr) y a�ade un salto de l�nea (endl)
        return; // Sale de la funci�n si no se pudo abrir el archivo
    }

    Registro reg; // Declara una variable de tipo Registro para almacenar el registro le�do del archivo
    bool encontrado = false; // Declara una variable booleana para indicar si se encontr� el registro

    // Lee registros del archivo hasta el final del archivo o hasta que se encuentre el registro buscado
    while (archivo.read(reinterpret_cast<char*>(&reg), sizeof(Registro)) && !encontrado) {
        if (reg.id == idBuscado) { // Si el ID del registro le�do coincide con el ID buscado
            // Imprime los datos del registro encontrado
            cout << "\nRegistro encontrado:"
                << "\nNombre: " << reg.nombre
                << "\nSalario: " << reg.salario << endl;
            encontrado = true; // Marca la variable "encontrado" como verdadera para detener el bucle
        }
    }

    if (!encontrado) { // Si no se encontr� el registro despu�s de leer todo el archivo
        cout << "Registro no encontrado!" << endl; // Imprime un mensaje indicando que no se encontr� el registro
    }

    archivo.close(); // Cierra el archivo despu�s de la b�squeda
}