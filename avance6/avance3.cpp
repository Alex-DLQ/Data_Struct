//C4:P4 4.1.4
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Ingrese la cantidad de elementos: ";
    cin >> n;
    vector<int> arreglo(n);
    int maximo = 0;
    cout << "Ingrese los elementos:\n";
    for (int i = 0; i < n; i++) {
        cin >> arreglo[i];
        maximo = max(maximo, arreglo[i]);
    }
    vector<int> conteo(maximo + 1, 0);
    for (int x : arreglo) conteo[x]++;
    cout << "Arreglo ordenado: ";
    for (int i = 0; i <= maximo; i++) {
        for (int j = 0; j < conteo[i]; j++) {
            cout << i << " ";
        }
    }
    cout << "\n";
}
