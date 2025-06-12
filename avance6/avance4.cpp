//C4:P4 4.3.1
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
    int n, x;
    cout << "Ingrese la cantidad de elementos: ";
    cin >> n;
    cout << "Ingrese el elemento a buscar: ";
    cin >> x;
    vector<int> arreglo(n);
    cout << "Ingrese los elementos (ordenados):\n";
    for (int i = 0; i < n; i++) cin >> arreglo[i];
    int izquierda = 0, derecha = n - 1;
    while (izquierda <= derecha) {
        int medio = (izquierda + derecha) / 2;
        if (arreglo[medio] == x) {
            cout << "Elemento encontrado en la posicion " << medio << "\n";
            return 0;
        }
        if (arreglo[medio] < x) izquierda = medio + 1;
        else derecha = medio - 1;
    }
    cout << "Elemento no encontrado\n";
}
