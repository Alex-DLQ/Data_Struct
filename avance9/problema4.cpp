#include <iostream>
#include <queue>      // Para usar queue (cola)

using namespace std;

struct Tarea {
    int tiempo;      
};

int main() {
    int N;
    cin >> N;         // Leer número de tareas

    queue<Tarea> cola; 

    // Leer y almacenar tareas
    for (int i = 0; i < N; ++i) {
        int t;
        cin >> t;
        cola.push({t});  // Crear y añadir Tarea directamente
    }

    int tiempoAcum = 0, totalEspera = 0;

    // Procesar tareas
    while (!cola.empty()) {
        Tarea t = cola.front();  // Obtener la primera tarea (copia)
        cola.pop();              // Eliminarla de la cola
        totalEspera += tiempoAcum; // Acumular tiempo de espera
        tiempoAcum += t.tiempo;    // Sumar tiempo de ejecución
    }

    cout << totalEspera << endl;
    return 0;
}