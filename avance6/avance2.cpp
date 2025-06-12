//C4:P4 4.1.2
#include <bits/stdc++.h>
#include <vector>
using namespace std;

void merge_sort(vector<int>& arreglo) {
    if (arreglo.size() == 1) return;
    int n = arreglo.size();
    vector<int> izq(arreglo.begin(), arreglo.begin() + n / 2);
    vector<int> der(arreglo.begin() + n / 2, arreglo.end());
    merge_sort(izq);
    merge_sort(der);
    int i = 0, j = 0, k = 0;
    while (i < izq.size() && j < der.size()) {
        if (izq[i] < der[j]) {
            arreglo[k++] = izq[i++];
        } else {
            arreglo[k++] = der[j++];
        }
    }
    while (i < izq.size()) arreglo[k++] = izq[i++];
    while (j < der.size()) arreglo[k++] = der[j++];
}

int main() {
    int n;
    cout << "Ingrese la cantidad de elementos: ";
    cin >> n;
    vector<int> arreglo(n);
    cout << "Ingrese los elementos:\n";
    for (int i = 0; i < n; i++) cin >> arreglo[i];
    merge_sort(arreglo);
    cout << "Arreglo ordenado: ";
    for (int i = 0; i < n; i++) cout << arreglo[i] << " ";
    cout << "\n";
}
