#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo* siguiente;
};

Nodo* cabeza = NULL; // Variable global

void agregarNodo(int dato) {
    Nodo* nuevo = new Nodo();
    nuevo->dato = dato;
    nuevo->siguiente = NULL;

    if (cabeza == NULL) {
        cabeza = nuevo;
    }
    else {
        Nodo* temp = cabeza;
        while (temp->siguiente != NULL) {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevo;
    }
}

void mostrarLista() {
    cout << "\nContenido de la lista:" << endl;
    Nodo* temp = cabeza;
    while (temp != NULL) {
        if (temp->siguiente != NULL) {
            cout << "[" << temp->dato << " | * ] -> ";
        }
        else {
            cout << "[" << temp->dato << " | NULL]";
        }
        temp = temp->siguiente;
    }
    cout << endl;
}

void liberarMemoria() {
    Nodo* temp;
    while (cabeza != NULL) {
        temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
    }
}

int main() {
    char respuesta;
    int dato;

    do {
        cout << "\nDesea ingresar un nuevo valor? (S/N): ";
        cin >> respuesta;

        if (respuesta == 'S' || respuesta == 's') {
            cout << "Ingrese el dato: ";
            cin >> dato;
            agregarNodo(dato);
        }
        else if (respuesta == 'N' || respuesta == 'n') {
            cout << "Finalizando ingreso de datos..." << endl;
        }
        else {
            cout << "Opcion no valida. Intente de nuevo." << endl;
        }

    } while (respuesta != 'N' && respuesta != 'n');

    if (cabeza != NULL) {
        mostrarLista();
    }
    else {
        cout << "\nLa lista esta vacia." << endl;
    }

    liberarMemoria();
    cout << "Memoria liberada correctamente." << endl;

    return 0;
}