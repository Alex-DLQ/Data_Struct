#include <iostream>
#include <cstdlib>
using namespace std;

// Estructura para pila
struct Nodo {
    int dato;
    Nodo *siguiente;
};

// Estructura para cola
struct nodo {
    int dato;
    nodo* siguiente;
};

// Variables globales para la cola
nodo* frente = nullptr;
nodo* fin = nullptr;

// Prototipos
void intercambiarPilaCola(Nodo *&, nodo *&, nodo *&);
void menuprincipal();
void menu_pilas(Nodo *&);
void menu_colas();
void insertar(Nodo *&, int);
void mostrar(Nodo*);
void quitar(Nodo *&, int &);
void insertarEnCola(int);
void eliminarDeCola();
void mostrarCola();
void pasarPilaACola(Nodo *&);
void pasarColaAPila(Nodo *&);

// Función principal
int main() {
    menuprincipal();
    return 0;
}

// Menú principal
void menuprincipal() {
    Nodo *pila = nullptr;
    int opcion;
    do {
        cout << "\n===== MENU PRINCIPAL =====\n";
        cout << "1. Llamar colas\n";
        cout << "2. Llamar pilas\n";
        cout << "3. Pasar de pila a cola\n";
        cout << "4. Pasar de cola a pila\n";
        cout << "5. Intercambiar pila y cola\n"; //  NUEVA OPCIÓN
        cout << "6. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                menu_colas();
                break;
            case 2:
                menu_pilas(pila);
                break;
            case 3:
                pasarPilaACola(pila);
                system("pause");
                break;
            case 4:
                pasarColaAPila(pila);
                system("pause");
                break;
            case 5:
                intercambiarPilaCola(pila, frente, fin);
                system("pause");
                break;
            case 6:
                cout << "Saliendo del programa...\n";
                break;
            default:
                cout << "Opcion no valida.\n";
        }
        system("cls");
    } while (opcion != 6);
}


// Menú de pila
void menu_pilas(Nodo *&pila) {
    int opcion, valor;
    do {
        cout << "\n----- MENU DE PILA -----\n";
        cout << "1. Insertar elemento\n";
        cout << "2. Quitar elemento\n";
        cout << "3. Mostrar pila\n";
        cout << "4. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        switch (opcion) {
            case 1:
                cout << "Ingrese un numero: ";
                cin >> valor;
                insertar(pila, valor);
                system("pause");
                break;
            case 2:
                quitar(pila, valor);
                system("pause");
                break;
            case 3:
                mostrar(pila);
                system("pause");
                break;
            case 4:
                cout << "Saliendo del menu de pila...\n";
                break;
            default:
                cout << "Opcion no valida, intente de nuevo.\n";
        }
        system("cls");
    } while (opcion != 4);
}

// Funciones de pila
void insertar(Nodo *&pila, int valor) {
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->dato = valor;
    nuevo_nodo->siguiente = pila;
    pila = nuevo_nodo;
    cout << "\tEl dato fue agregado.\n";
}

void quitar(Nodo *&pila, int &valor) {
    if (pila == nullptr) {
        cout << "No hay elementos para borrar.\n";
        return;
    }
    Nodo *aux = pila;
    valor = aux->dato;
    pila = aux->siguiente;
    delete aux;
    cout << "Elemento quitado de la pila: " << valor << endl;
}

void mostrar(Nodo *pila) {
    if (pila == nullptr) {
        cout << "La pila esta vacia.\n";
        return;
    }
    cout << "Elementos de la pila: ";
    while (pila != nullptr) {
        cout << pila->dato << " -> ";
        pila = pila->siguiente;
    }
    cout << "NULL\n";
}

// Menú de colas
void menu_colas() {
    int opcion, valor;
    do {
        cout << "\n--- MENU DE COLA ---\n";
        cout << "1. Insertar\n";
        cout << "2. Eliminar\n";
        cout << "3. Mostrar\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese un valor: ";
                cin >> valor;
                insertarEnCola(valor);
                system("pause");
                break;
            case 2:
                eliminarDeCola();
                system("pause");
                break;
            case 3:
                mostrarCola();
                system("pause");
                break;
            case 0:
                cout << "Saliendo del menu de cola...\n";
                break;
            default:
                cout << "Opcion invalida.\n";
        }
        system("cls");
    } while (opcion != 0);
}

// Funciones de cola
void insertarEnCola(int valor) {
    nodo* nuevo = new nodo();
    nuevo->dato = valor;
    nuevo->siguiente = nullptr;

    if (frente == nullptr) {
        frente = nuevo;
        fin = nuevo;
    } else {
        fin->siguiente = nuevo;
        fin = nuevo;
    }

    cout << "Elemento insertado correctamente.\n";
}

void eliminarDeCola() {
    if (frente == nullptr) {
        cout << "La cola esta vacia.\n";
        return;
    }

    nodo* temp = frente;
    int eliminado = temp->dato;
    frente = frente->siguiente;
    delete temp;

    if (frente == nullptr) {
        fin = nullptr;
    }

    cout << "Elemento eliminado: " << eliminado << endl;
}

void mostrarCola() {
    if (frente == nullptr) {
        cout << "La cola esta vacia.\n";
        return;
    }

    cout << "Elementos de la cola: ";
    nodo* actual = frente;
    while (actual != nullptr) {
        cout << actual->dato << " -> ";
        actual = actual->siguiente;
    }
    cout << "NULL\n";
}

// Transferencia de pila a cola
void pasarPilaACola(Nodo *&pila) {
    Nodo* tempPila = nullptr;
    int valor;

    // Invertimos la pila para mantener orden
    Nodo* actual = pila;
    while (actual != nullptr) {
        insertar(tempPila, actual->dato);
        actual = actual->siguiente;
    }

    // Vaciamos pila original
    while (pila != nullptr) {
        quitar(pila, valor);
    }

    // Insertamos en cola
    while (tempPila != nullptr) {
        quitar(tempPila, valor);
        insertarEnCola(valor);
    }

    cout << "Pila transferida a la cola exitosamente y vaciada.\n";
}

// Transferencia de cola a pila
void pasarColaAPila(Nodo *&pila) {
    while (frente != nullptr) {
        int valor = frente->dato;
        eliminarDeCola(); // elimina nodo de la cola
        insertar(pila, valor); // agrega a pila
    }

    cout << "Cola transferida a la pila exitosamente y vaciada.\n";
}
void intercambiarPilaCola(Nodo *&pila, nodo *&frente, nodo *&fin) {
    // Copiar pila a cola temporal
    Nodo *tempPila = nullptr;
    Nodo *auxPila = pila;
    while (auxPila != nullptr) {
        insertar(tempPila, auxPila->dato);
        auxPila = auxPila->siguiente;
    }

    // Invertir pila temporal para respetar orden en cola
    Nodo *invertida = nullptr;
    int valor;
    while (tempPila != nullptr) {
        quitar(tempPila, valor);
        insertar(invertida, valor);
    }

    // Copiar cola a pila temporal
    nodo *auxCola = frente;
    Nodo *colaEnPila = nullptr;
    while (auxCola != nullptr) {
        insertar(colaEnPila, auxCola->dato);
        auxCola = auxCola->siguiente;
    }

    // Vaciar pila original
    while (pila != nullptr) {
        quitar(pila, valor);
    }

    // Vaciar cola original
    while (frente != nullptr) {
        eliminarDeCola();
    }

    // Insertar cola original en pila
    Nodo *temp = colaEnPila;
    while (temp != nullptr) {
        insertar(pila, temp->dato);
        temp = temp->siguiente;
    }

    // Insertar pila original (invertida) en cola
    Nodo *temp2 = invertida;
    while (temp2 != nullptr) {
        insertarEnCola(temp2->dato);
        temp2 = temp2->siguiente;
    }

    cout << "Pila y cola intercambiadas exitosamente.\n";
}
