#include "../Modificacion.h" // Incluye el archivo de encabezado "Modificacion.h", que contiene la declaraci�n de la funci�n modificarRegistro
#include "../busqueda.h" // Incluye el archivo de encabezado "busqueda.h", que contiene la declaraci�n de la funci�n buscarPosicion
#include <fstream> // Incluye la librer�a para el manejo de archivos (fstream)
#include "../Registro.h" // Incluye el archivo de encabezado "Registro.h", que define la estructura o clase "Registro"

using namespace std; // Usa el espacio de nombres est�ndar para evitar prefijos std::

void modificarRegistro(Registro modificado) { // Define la funci�n modificarRegistro, que toma un objeto de tipo Registro llamado "modificado" como argumento

    fstream archivo("datos.dat", ios::binary | ios::in | ios::out); // Abre el archivo "datos.dat" en modo binario para lectura y escritura

    if (!archivo.is_open()) { // Verifica si el archivo se abri� correctamente
        cerr << "�Error al abrir archivo!"; // Imprime un mensaje de error en el flujo de error est�ndar (cerr)
        return; // Sale de la funci�n si no se pudo abrir el archivo
    }

    int pos = buscarPosicion(modificado.id); // Llama a la funci�n buscarPosicion para obtener la posici�n del registro a modificar

    if (pos == -1) { // Si la funci�n buscarPosicion retorna -1, significa que no se encontr� el registro
        cout << "Registro no encontrado!" << endl; // Imprime un mensaje indicando que no se encontr� el registro
        return; // Sale de la funci�n
    }

    archivo.seekp(pos * sizeof(Registro)); // Se mueve al inicio del registro que se va a modificar usando seekp
    archivo.write(reinterpret_cast<char*>(&modificado), sizeof(Registro)); // Escribe el registro modificado en el archivo
    archivo.close(); // Cierra el archivo
    cout << "Registro modificado!" << endl; // Imprime un mensaje indicando que el registro fue modificado
}