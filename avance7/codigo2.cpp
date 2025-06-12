//C5:P5 5.1.2
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
    vector<int> numeros = {10, 20, 30, 40, 50};

    cout << "Elementos usando iteradores:\n";
    for (auto it = numeros.begin(); it != numeros.end(); ++it) {
        cout << *it << " ";
    }
    cout << "\n";

    cout << "Elementos usando rango for:\n";
    for (int num : numeros) {
        cout << num << " ";
    }
    cout << "\n";
}