#include"Nodo.h"
#pragma once
class Agenda_
{
private:
    Nodo* cabeza;
    Nodo* cola;

public:
    Agenda_();
    void agregarContacto(string nombre, string telefono);
    Nodo* buscarContacto(string nombre);
    void eliminarContacto(string nombre);
    void listarContactos();
    void modificarTelefono(string nombre, string nuevoTelefono);
    void mostrarNodoAnterior(Nodo* nodo);
};
