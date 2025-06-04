//C2:P3 2.3.2
#include <bits/stdc++.h>
using namespace std;

int main() {
    int x = 0;
    x |= (1 << 1); // Agrega el elemento 1
    x |= (1 << 3); // Agrega el elemento 3
    x |= (1 << 4); // Agrega el elemento 4
    x |= (1 << 8); // Agrega el elemento 8

    cout << __builtin_popcount(x) << "\n"; // Imprime el tamaño del conjunto (4)

    // Imprime los elementos que están en el conjunto
    for (int i = 0; i < 32; i++) {
        if (x & (1 << i))
            cout << i << " ";
    }
    cout << "\n"; // Salida: 1 3 4 8

    return 0;
}