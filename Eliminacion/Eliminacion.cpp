#include "../Eliminacion.h" // Incluye el archivo de encabezado Eliminacion.h, que probablemente contiene la declaraci�n de la funci�n eliminarRegistro
#include <fstream> // Incluye la librer�a para el manejo de archivos (ifstream y ofstream)
#include <cstdio> // Incluye la librer�a para funciones de entrada/salida de C (remove y rename)
#include <iostream> // Incluye la librer�a para entrada/salida est�ndar (cerr y cout)
#include "../Registro.h" // Incluye el archivo de encabezado Registro.h, que define la estructura o clase Registro

using namespace std; // Usa el espacio de nombres est�ndar para evitar prefijos std::

void eliminarRegistro(int idEliminar) { // Define la funci�n eliminarRegistro que toma un entero idEliminar como argumento
    ifstream entrada("datos.dat", ios::binary); // Abre el archivo "datos.dat" en modo binario para lectura
    if (!entrada.is_open()) { // Verifica si el archivo se abri� correctamente
        cerr << "Error abriendo archivo!" << endl; // Imprime un mensaje de error en el flujo de error est�ndar y sale de la funci�n
        return; // Sale de la funci�n si no se pudo abrir el archivo
    }

    ofstream salida("temp.dat", ios::binary); // Abre un archivo temporal "temp.dat" en modo binario para escritura
    Registro reg; // Declara una variable de tipo Registro para almacenar los registros le�dos
    bool eliminado = false; // Declara una variable booleana para indicar si se ha eliminado el registro

    while (entrada.read(reinterpret_cast<char*>(&reg), sizeof(Registro))) { // Lee registros del archivo "datos.dat" hasta el final del archivo
        if (reg.id != idEliminar) { // Si el ID del registro le�do no coincide con el ID a eliminar
            salida.write(reinterpret_cast<char*>(&reg), sizeof(Registro)); // Escribe el registro en el archivo temporal "temp.dat"
        }
        else { // Si el ID del registro coincide con el ID a eliminar
            eliminado = true; // Marca la variable eliminado como verdadera
        }
    }

    entrada.close(); // Cierra el archivo "datos.dat"
    salida.close(); // Cierra el archivo "temp.dat"

    remove("datos.dat"); // Elimina el archivo original "datos.dat"
    rename("temp.dat", "datos.dat"); // Renombra el archivo temporal "temp.dat" a "datos.dat", reemplazando el archivo original

    if (eliminado) { // Si se elimin� el registro
        cout << "Registro eliminado!" << endl; // Imprime un mensaje indicando que el registro fue eliminado
    }
    else { // Si no se encontr� el registro con el ID especificado
        cout << "Registro no encontrado!" << endl; // Imprime un mensaje indicando que el registro no fue encontrado
    }
}
