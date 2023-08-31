#include <iostream>
#include <string>
#include"Agenda_.h"
using namespace std;


int main() {
    Agenda_ agenda;

    while (true) {
        cout << "          AGENDA           " << endl;
        cout << "1. Agregar contacto" << endl;
        cout << "2. Borrar contacto" << endl;
        cout << "3. Mostrar lista de contactos" << endl;
        cout << "4. Modificar telefono de un contacto" << endl;
        cout << "5. Mostrar nodo anterior" << endl;
        cout << "6. Salir" << endl;
        cout << endl;
        cout << "Ingrese la opcion deseada: ";
        int opcion;
        cin >> opcion;

        if (opcion == 1) {
            string nombre, telefono;
            cout << "Ingrese el nombre del contacto: ";
            cin.ignore();
            getline(cin, nombre);
            cout << "Ingrese el telefono del contacto: ";
            getline(cin, telefono);
            agenda.agregarContacto(nombre, telefono);
        }
        else if (opcion == 2) {
            string nombre;
            cout << "Ingrese el nombre del contacto a eliminar: ";
            cin.ignore();
            getline(cin, nombre);
            agenda.eliminarContacto(nombre);
        }
        else if (opcion == 3) {
            agenda.listarContactos();
        }
        else if (opcion == 4) {
            string nombre, nuevoTelefono;
            cout << "Ingrese el nombre del contacto a modificar: ";
            cin.ignore();
            getline(cin, nombre);
            cout << "Ingrese el nuevo telefono: ";
            getline(cin, nuevoTelefono);
            agenda.modificarTelefono(nombre, nuevoTelefono);
        }
        else if (opcion == 5) {
            string nombre;
            cout << "Ingrese el nombre del contacto: ";
            cin.ignore();
            getline(cin, nombre);
            Nodo* contacto = agenda.buscarContacto(nombre);
            agenda.mostrarNodoAnterior(contacto);
        }
        else if (opcion == 6) {
            break;
        }
        else {
            cout << "ERROR Opcion invalida." << endl;
        }

        cout << endl;
    }

    return 0;
}
