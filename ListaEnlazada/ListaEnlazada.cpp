#include <iostream>
#include <string>
using namespace std;


class Alumno {
public:
    string nombres;
    string apellidos;
    string carnet;
    string email;
    string telefono;
    double notas[5];

    Alumno() {
        for (int i = 0; i < 5; i++) notas[i] = 0.0;
    }

    double calcularPromedio() const {
        double suma = 0.0;
        for (int i = 0; i < 5; i++) suma += notas[i];
        return suma / 5.0;
    }
};


struct Nodo {
    Alumno dato;       
    Nodo* siguiente;
};

Nodo* cabeza = NULL;  

void agregarNodo(Alumno dato) {
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
    int contador = 1;
    while (temp != NULL) {
        cout << "\n-------------------------------" << endl;
        cout << "Alumno #" << contador++ << endl;
        cout << "  Nombres   : " << temp->dato.nombres << endl;
        cout << "  Apellidos : " << temp->dato.apellidos << endl;
        cout << "  Carnet    : " << temp->dato.carnet << endl;
        cout << "  Email     : " << temp->dato.email << endl;
        cout << "  Telefono  : " << temp->dato.telefono << endl;
        cout << "  Notas     : ";
        for (int i = 0; i < 5; i++) {
            cout << temp->dato.notas[i];
            if (i < 4) cout << ", ";
        }
        cout << endl;
        cout << "  Promedio  : " << temp->dato.calcularPromedio() << endl;
        cout << "-------------------------------" << endl;
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

double leerNota(int numero) {
    double nota;
    bool valida = false;
    while (!valida) {
        cout << "  Nota " << numero << " (0-10): ";
        cin >> nota;
        if (cin.fail() || nota < 0.0 || nota > 10.0) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "  Valor invalido. Ingrese un numero entre 0 y 10." << endl;
        }
        else {
            valida = true;
        }
    }
    cin.ignore(1000, '\n');
    return nota;
}

Alumno ingresarAlumno() {
    Alumno a;

    cout << "  Nombres   : ";
    getline(cin, a.nombres);

    cout << "  Apellidos : ";
    getline(cin, a.apellidos);

    cout << "  Carnet    : ";
    getline(cin, a.carnet);

    cout << "  Email     : ";
    getline(cin, a.email);

    cout << "  Telefono  : ";
    getline(cin, a.telefono);

    cout << "  Ingrese las 5 notas:" << endl;
    for (int i = 0; i < 5; i++) {
        a.notas[i] = leerNota(i + 1);
    }

    return a;
}
int main() {
    char respuesta;

    do {
        cout << "\n--- Ingreso de datos del alumno ---" << endl;
        cin.ignore(1000, '\n'); 
        Alumno nuevo = ingresarAlumno();
        agregarNodo(nuevo);
        cout << "\nAlumno agregado exitosamente." << endl;

        cout << "\nDesea ingresar un nuevo alumno? (S/N): ";
        cin >> respuesta;

    } while (respuesta == 'S' || respuesta == 's');

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