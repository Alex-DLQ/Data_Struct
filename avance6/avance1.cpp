//C4:P4 4.1.1
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cout << "Ingrese la cantidad de elementos: ";
    cin >> n;
    int arreglo[n];
    cout << "Ingrese los elementos:\n";
    for (int i = 0; i < n; i++) {
        cin >> arreglo[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n - i; j++) {
            if (arreglo[j - 1] > arreglo[j]) {
                swap(arreglo[j - 1], arreglo[j]);
            }
        }
    }
    cout << "Arreglo ordenado: ";
    for (int i = 0; i < n; i++) {
        cout << arreglo[i] << " ";
    }
    cout << "\n";
}