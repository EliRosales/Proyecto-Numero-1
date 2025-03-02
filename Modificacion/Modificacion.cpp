#include "../Modificacion.h" // Incluye el archivo de encabezado "Modificacion.h", que contiene la declaración de la función modificarRegistro
#include "../busqueda.h" // Incluye el archivo de encabezado "busqueda.h", que contiene la declaración de la función buscarPosicion
#include <fstream> // Incluye la librería para el manejo de archivos (fstream)
#include "../Registro.h" // Incluye el archivo de encabezado "Registro.h", que define la estructura o clase "Registro"

using namespace std; // Usa el espacio de nombres estándar para evitar prefijos std::

void modificarRegistro(Registro modificado) { // Define la función modificarRegistro, que toma un objeto de tipo Registro llamado "modificado" como argumento

    fstream archivo("datos.dat", ios::binary | ios::in | ios::out); // Abre el archivo "datos.dat" en modo binario para lectura y escritura

    if (!archivo.is_open()) { // Verifica si el archivo se abrió correctamente
        cerr << "¡Error al abrir archivo!"; // Imprime un mensaje de error en el flujo de error estándar (cerr)
        return; // Sale de la función si no se pudo abrir el archivo
    }

    int pos = buscarPosicion(modificado.id); // Llama a la función buscarPosicion para obtener la posición del registro a modificar

    if (pos == -1) { // Si la función buscarPosicion retorna -1, significa que no se encontró el registro
        cout << "Registro no encontrado!" << endl; // Imprime un mensaje indicando que no se encontró el registro
        return; // Sale de la función
    }

    archivo.seekp(pos * sizeof(Registro)); // Se mueve al inicio del registro que se va a modificar usando seekp
    archivo.write(reinterpret_cast<char*>(&modificado), sizeof(Registro)); // Escribe el registro modificado en el archivo
    archivo.close(); // Cierra el archivo
    cout << "Registro modificado!" << endl; // Imprime un mensaje indicando que el registro fue modificado
}