//C4:P4 4.3.2
#include <bits/stdc++.h>
using namespace std;

// Ejemplo: Encontrar el menor k tal que k*k >= x
int main() {
    int x;
    cout << "Ingrese el valor de x: ";
    cin >> x;
    int izquierda = 0, derecha = x;
    while (izquierda < derecha) {
        int medio = (izquierda + derecha) / 2;
        if (medio * medio >= x) derecha = medio;
        else izquierda = medio + 1;
    }
    cout << "El menor k tal que k*k >= x es: " << izquierda << "\n";
}
