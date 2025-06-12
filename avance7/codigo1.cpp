//C5:P5 5.1.1
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Ingrese la cantidad de elementos: ";
    cin >> n;
    vector<int> vector_dinamico;
    cout << "Ingrese los elementos:\n";
    for (int i = 0; i < n; i++) {
        int valor;
        cin >> valor;
        vector_dinamico.push_back(valor);
    }
    cout << "Elementos en el vector: ";
    for (int i = 0; i < (int)vector_dinamico.size(); i++) {
        cout << vector_dinamico[i] << " ";
    }
    cout << "\n";
}