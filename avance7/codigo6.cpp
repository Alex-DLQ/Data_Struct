//C5:P5 5.2.3
#include <bits/stdc++.h>
#include <queue>
using namespace std;

int main() {
    priority_queue<int> cola_prioridad;
    cola_prioridad.push(10);
    cola_prioridad.push(5);
    cola_prioridad.push(20);

    cout << "Elementos extraidos de la cola de prioridad:\n";
    while (!cola_prioridad.empty()) {
        cout << cola_prioridad.top() << " ";
        cola_prioridad.pop();
    }
    cout << "\n";
}