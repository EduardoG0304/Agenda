#include "Agenda_.h"

Agenda_::Agenda_() {
    cabeza = nullptr;
    cola = nullptr;
}

void Agenda_::agregarContacto(string nombre, string telefono) {
    Nodo* nuevoContacto = new Nodo(nombre, telefono);

    if (cabeza == nullptr) {
        cabeza = nuevoContacto;
        cola = nuevoContacto;
    }
    else {
        nuevoContacto->anterior = cola;
        cola->siguiente = nuevoContacto;
        cola = nuevoContacto;
    }

    cout << "Contacto agregado." << endl;
}

Nodo* Agenda_::buscarContacto(string nombre) {
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        if (actual->nombre == nombre) {
            return actual;
        }
        actual = actual->siguiente;
    }
    return nullptr;
}

void Agenda_::eliminarContacto(string nombre) {
    if (cabeza == nullptr) {
        cout << "Agenda vacia o no existe el contacto." << endl;
        return;
    }

    Nodo* actual = cabeza;
    while (actual != nullptr) {
        if (actual->nombre == nombre) {
            if (actual == cabeza) {
                cabeza = actual->siguiente;
                if (cabeza != nullptr) {
                    cabeza->anterior = nullptr;
                }
            }
            else if (actual == cola) {
                cola = actual->anterior;
                if (cola != nullptr) {
                    cola->siguiente = nullptr;
                }
            }
            else {
                actual->anterior->siguiente = actual->siguiente;
                actual->siguiente->anterior = actual->anterior;
            }

            delete actual;
            cout << "Contacto eliminado." << endl;
            return;
        }
        actual = actual->siguiente;
    }

    cout << "No se encontro el contacto en la agenda." << endl;
}

void Agenda_::listarContactos() {
    if (cabeza == nullptr) {
        cout << "Agenda vacia." << endl;
        return;
    }

    cout << "Contactos en la agenda:" << endl;
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        cout << "Nombre: " << actual->nombre << ", Telefono: " << actual->telefono << endl;
        actual = actual->siguiente;
    }
}

void Agenda_::modificarTelefono(string nombre, string nuevoTelefono) {
    Nodo* contacto = buscarContacto(nombre);
    if (contacto != nullptr) {
        contacto->telefono = nuevoTelefono;
        cout << "Telefono modificado correctamente." << endl;
    }
    else {
        cout << "No existe el contacto." << endl;
    }
}

void Agenda_::mostrarNodoAnterior(Nodo* nodo) {
    if (nodo == nullptr) {
        cout << "Nodo nulo." << endl;
        return;
    }

    if (nodo->anterior == nullptr) {
        cout << "No hay nodo anterior." << endl;
    }
    else {
        cout << "Contacto anterior es:" << endl;
        cout << "Nombre: " << nodo->anterior->nombre << ", Telefono: " << nodo->anterior->telefono << endl;
    }
}