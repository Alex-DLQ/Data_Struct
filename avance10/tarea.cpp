#include <iostream>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <chrono>
#include <fstream>
#include <algorithm>
#include <random>
#include <string>
using namespace std;
using namespace std::chrono;

struct Nodo {
    int valor;
    Nodo* izq;
    Nodo* der;
    Nodo(int v) : valor(v), izq(nullptr), der(nullptr) {}
};

class ArbolBinario {
public:
    Nodo* raiz = nullptr;

    void insertar(int valor) {
        raiz = insertarRec(raiz, valor);
    }

    bool buscar(int valor) {
        return buscarRec(raiz, valor);
    }

    void eliminar(int valor) {
        raiz = eliminarRec(raiz, valor);
    }

    void actualizar(int viejo, int nuevo) {
        eliminar(viejo);
        insertar(nuevo);
    }

private:
    Nodo* insertarRec(Nodo* nodo, int valor) {
        if (!nodo) return new Nodo(valor);
        if (valor < nodo->valor) nodo->izq = insertarRec(nodo->izq, valor);
        else nodo->der = insertarRec(nodo->der, valor);
        return nodo;
    }

    Nodo* eliminarRec(Nodo* nodo, int valor) {
        if (!nodo) return nullptr;
        if (valor < nodo->valor) nodo->izq = eliminarRec(nodo->izq, valor);
        else if (valor > nodo->valor) nodo->der = eliminarRec(nodo->der, valor);
        else {
            if (!nodo->izq) return nodo->der;
            if (!nodo->der) return nodo->izq;
            Nodo* temp = minValor(nodo->der);
            nodo->valor = temp->valor;
            nodo->der = eliminarRec(nodo->der, temp->valor);
        }
        return nodo;
    }

    Nodo* minValor(Nodo* nodo) {
        while (nodo && nodo->izq) nodo = nodo->izq;
        return nodo;
    }

    bool buscarRec(Nodo* nodo, int valor) {
        if (!nodo) return false;
        if (valor == nodo->valor) return true;
        if (valor < nodo->valor) return buscarRec(nodo->izq, valor);
        return buscarRec(nodo->der, valor);
    }
};

void medirYGuardar(const string& estructura, int N, ofstream& archivo) {
    vector<int> datos(N);
    iota(datos.begin(), datos.end(), 1);
    shuffle(datos.begin(), datos.end(), default_random_engine(random_device{}()));

    double t_insert = 0, t_busq = 0, t_elim = 0, t_actual = 0;

    if (estructura == "Pila") {
        stack<int> pila;
        auto ini = high_resolution_clock::now();
        for (int x : datos) pila.push(x);
        auto fin = high_resolution_clock::now();
        t_insert = duration<double, milli>(fin - ini).count();

        ini = high_resolution_clock::now();
        for (int x : datos) if (pila.top() == x) break;
        fin = high_resolution_clock::now();
        t_busq = duration<double, milli>(fin - ini).count();

        ini = high_resolution_clock::now();
        while (!pila.empty()) pila.pop();
        fin = high_resolution_clock::now();
        t_elim = duration<double, milli>(fin - ini).count();

        pila.push(999);
        ini = high_resolution_clock::now();
        pila.top() = 1000;
        fin = high_resolution_clock::now();
        t_actual = duration<double, milli>(fin - ini).count();
    }
    else if (estructura == "Cola") {
        queue<int> cola;
        auto ini = high_resolution_clock::now();
        for (int x : datos) cola.push(x);
        auto fin = high_resolution_clock::now();
        t_insert = duration<double, milli>(fin - ini).count();

        ini = high_resolution_clock::now();
        for (int x : datos) if (cola.front() == x) break;
        fin = high_resolution_clock::now();
        t_busq = duration<double, milli>(fin - ini).count();

        ini = high_resolution_clock::now();
        while (!cola.empty()) cola.pop();
        fin = high_resolution_clock::now();
        t_elim = duration<double, milli>(fin - ini).count();

        cola.push(999);
        ini = high_resolution_clock::now();
        int temp = cola.front(); cola.pop(); cola.push(1000);
        fin = high_resolution_clock::now();
        t_actual = duration<double, milli>(fin - ini).count();
    }
    else if (estructura == "Lista") {
        list<int> lista;
        auto ini = high_resolution_clock::now();
        for (int x : datos) lista.push_back(x);
        auto fin = high_resolution_clock::now();
        t_insert = duration<double, milli>(fin - ini).count();

        ini = high_resolution_clock::now();
        find(lista.begin(), lista.end(), datos[N / 2]);
        fin = high_resolution_clock::now();
        t_busq = duration<double, milli>(fin - ini).count();

        ini = high_resolution_clock::now();
        lista.clear();
        fin = high_resolution_clock::now();
        t_elim = duration<double, milli>(fin - ini).count();

        lista.push_back(999);
        ini = high_resolution_clock::now();
        lista.back() = 1000;
        fin = high_resolution_clock::now();
        t_actual = duration<double, milli>(fin - ini).count();
    }
    else if (estructura == "Arbol") {
        ArbolBinario arbol;
        auto ini = high_resolution_clock::now();
        for (int x : datos) arbol.insertar(x);
        auto fin = high_resolution_clock::now();
        t_insert = duration<double, milli>(fin - ini).count();

        ini = high_resolution_clock::now();
        arbol.buscar(datos[N / 2]);
        fin = high_resolution_clock::now();
        t_busq = duration<double, milli>(fin - ini).count();

        ini = high_resolution_clock::now();
        for (int x : datos) arbol.eliminar(x);
        fin = high_resolution_clock::now();
        t_elim = duration<double, milli>(fin - ini).count();

        arbol.insertar(999);
        ini = high_resolution_clock::now();
        arbol.actualizar(999, 1000);
        fin = high_resolution_clock::now();
        t_actual = duration<double, milli>(fin - ini).count();
    }

    archivo << estructura << "," << t_insert << "," << t_busq << "," << t_elim << "," << t_actual << "\n";
}

int main() {
    int N;
    int repeticiones = 5;
    cout << "Ingrese cantidad de datos por prueba: ";
    cin >> N;

    ofstream archivo("resultados_repetidos.csv");
    archivo << "Estructura,Insercion,Busqueda,Eliminacion,Actualizacion\n";

    for (int i = 0; i < repeticiones; ++i) {
        medirYGuardar("Pila", N, archivo);
        medirYGuardar("Cola", N, archivo);
        medirYGuardar("Lista", N, archivo);
        medirYGuardar("Arbol", N, archivo);
    }

    archivo.close();
    cout << "Pruebas completadas y guardadas en resultados_repetidos.csv ✅" << endl;
    return 0;
}