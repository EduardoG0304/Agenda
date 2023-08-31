#include <iostream>
using namespace std;

class Nodo {
public:
    string nombre;
    string telefono;
    Nodo* siguiente;
    Nodo* anterior;

    Nodo(string nombre, string telefono);
};