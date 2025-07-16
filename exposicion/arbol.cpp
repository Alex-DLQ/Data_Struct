#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int ORDEN = 3;  // Grado del árbol B+ (será ingresado por el usuario)

struct Nodo {
    bool esHoja;
    vector<int> claves;
    vector<Nodo*> hijos;
    Nodo* siguiente;

    Nodo(bool hoja) {
        esHoja = hoja;
        siguiente = nullptr;
    }
};

bool buscar(Nodo* raiz, int clave) {
    if (!raiz) return false;
    int i = 0;
    while (i < raiz->claves.size() && clave >= raiz->claves[i]) i++;  // 🔧 corrección aquí
    if (raiz->esHoja)
        return (i > 0 && raiz->claves[i - 1] == clave);  // Asegura coincidencia exacta
    return buscar(raiz->hijos[i], clave);
}

void dividirHoja(Nodo* hoja, Nodo*& nuevaHoja, int& claveSube) {
    nuevaHoja = new Nodo(true);
    int mitad = (ORDEN + 1) / 2;
    nuevaHoja->claves.assign(hoja->claves.begin() + mitad, hoja->claves.end());
    hoja->claves.resize(mitad);
    nuevaHoja->siguiente = hoja->siguiente;
    hoja->siguiente = nuevaHoja;
    claveSube = nuevaHoja->claves[0];
}

void dividirInterno(Nodo* padre, Nodo*& nuevoNodo, int& claveSube) {
    nuevoNodo = new Nodo(false);
    int mitad = ORDEN / 2;
    claveSube = padre->claves[mitad];
    nuevoNodo->claves.assign(padre->claves.begin() + mitad + 1, padre->claves.end());
    nuevoNodo->hijos.assign(padre->hijos.begin() + mitad + 1, padre->hijos.end());
    padre->claves.resize(mitad);
    padre->hijos.resize(mitad + 1);
}

void insertarRecursivo(Nodo* actual, int clave, Nodo*& nuevoNodo, int& claveSube) {
    int i = 0;
    while (i < actual->claves.size() && clave > actual->claves[i]) i++;

    if (actual->esHoja) {
        actual->claves.insert(actual->claves.begin() + i, clave);
        if (actual->claves.size() > ORDEN) {
            dividirHoja(actual, nuevoNodo, claveSube);
        }
    } else {
        Nodo* nuevoHijo = nullptr;
        int claveHijo;
        insertarRecursivo(actual->hijos[i], clave, nuevoHijo, claveHijo);
        if (nuevoHijo) {
            actual->claves.insert(actual->claves.begin() + i, claveHijo);
            actual->hijos.insert(actual->hijos.begin() + i + 1, nuevoHijo);
            if (actual->claves.size() > ORDEN) {
                dividirInterno(actual, nuevoNodo, claveSube);
            }
        }
    }
}

Nodo* insertar(Nodo* raiz, int clave) {
    if (!raiz) {
        Nodo* hoja = new Nodo(true);
        hoja->claves.push_back(clave);
        return hoja;
    }
    Nodo* nuevoNodo = nullptr;
    int claveSube;
    insertarRecursivo(raiz, clave, nuevoNodo, claveSube);
    if (nuevoNodo) {
        Nodo* nuevaRaiz = new Nodo(false);
        nuevaRaiz->claves.push_back(claveSube);
        nuevaRaiz->hijos.push_back(raiz);
        nuevaRaiz->hijos.push_back(nuevoNodo);
        return nuevaRaiz;
    }
    return raiz;
}

Nodo* eliminar(Nodo* raiz, int clave) {
    if (!raiz || !buscar(raiz, clave)) {
        cout << "Clave no encontrada.\n";
        return raiz;
    }
    Nodo* actual = raiz;
    while (!actual->esHoja) {
        int i = 0;
        while (i < actual->claves.size() && clave >= actual->claves[i]) i++;
        actual = actual->hijos[i];
    }
    auto it = find(actual->claves.begin(), actual->claves.end(), clave);
    if (it != actual->claves.end()) {
        actual->claves.erase(it);
        cout << "Clave eliminada (sin reestructuración).\n";
    }
    return raiz;
}

void mostrarArbolFormato(Nodo* raiz) {
    if (!raiz) {
        cout << "Arbol vacio.\n";
        return;
    }

    queue<pair<Nodo*, int>> q;
    q.push({raiz, 0});
    int nivelActual = -1;
    cout << "\nSalida del arbol B+:\n";
    while (!q.empty()) {
        Nodo* nodo = q.front().first;
        int nivel = q.front().second;
        q.pop();

        if (nivel != nivelActual) {
            nivelActual = nivel;
            cout << "\nNivel " << nivel << " -- ";
        }

        cout << "[";
        for (size_t i = 0; i < nodo->claves.size(); ++i) {
            cout << nodo->claves[i];
            if (i + 1 != nodo->claves.size()) cout << ", ";
        }
        cout << "]-- ";

        if (!nodo->esHoja) {
            for (Nodo* h : nodo->hijos) {
                q.push({h, nivel + 1});
            }
        }
    }
    cout << "\n";
}

void mostrarHojas(Nodo* raiz) {
    if (!raiz) return;
    while (!raiz->esHoja)
        raiz = raiz->hijos[0];
    cout << "Recorrido por hojas: ";
    while (raiz) {
        cout << "[";
        for (size_t i = 0; i < raiz->claves.size(); ++i) {
            cout << raiz->claves[i];
            if (i + 1 != raiz->claves.size()) cout << ", ";
        }
        cout << "]--";
        raiz = raiz->siguiente;
    }
    cout << endl;
}

int main() {
    Nodo* arbol = nullptr;
    int opcion, valor;

    cout << "Ingrese el grado del arbol B+: ";
    cin >> ORDEN;

    while (true) {
        cout << "\n--- Menu Arbol B+ ---\n";
        cout << "1. Insertar clave\n";
        cout << "2. Buscar clave\n";
        cout << "3. Eliminar clave\n";
        cout << "4. Ver recorrido por hojas\n";
        cout << "5. Ver arbol por niveles\n";
        cout << "6. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese valor a insertar: ";
                cin >> valor;
                arbol = insertar(arbol, valor);
                cout << " Clave insertada.\n";
                break;
            case 2:
                cout << "Ingrese clave a buscar: ";
                cin >> valor;
                if (buscar(arbol, valor))
                    cout << " Clave " << valor << " encontrada.\n";
                else
                    cout << " Clave no encontrada.\n";
                cout << "\n";
                system("pause");
                break;
            case 3:
                cout << "Ingrese clave a eliminar: ";
                cin >> valor;
                arbol = eliminar(arbol, valor);
                break;
            case 4:
                mostrarHojas(arbol);
                cout << "\n";
                system("pause");
                break;
            case 5:
                mostrarArbolFormato(arbol);
                cout << "\n";
                system("pause");
                break;
            case 6:
                cout << "Saliendo...\n";
                return 0;
            default:
                cout << "Opcion no valida.\n";
        }
        system("cls");
    }
    return 0;
}
