//C2:P3 2.3.2
#include <bits/stdc++.h>
using namespace std;

int main() {
    // x = {1, 3, 4, 8}
    int x = (1 << 1) | (1 << 3) | (1 << 4) | (1 << 8);
    // y = {3, 6, 8, 9}
    int y = (1 << 3) | (1 << 6) | (1 << 8) | (1 << 9);

    // Unión: z = x ∪ y = {1, 3, 4, 6, 8, 9}
    int z = x | y;
    cout << __builtin_popcount(z) << "\n"; // 6

    // Intersección: x ∩ y
    int inter = x & y;
    cout << "Interseccion: ";
    for (int i = 0; i < 32; i++) {
        if (inter & (1 << i)) cout << i << " ";
    }
    cout << "\n";

    // Diferencia: x \ y
    int diff = x & (~y);
    cout << "Diferencia (x \\ y): ";
    for (int i = 0; i < 32; i++) {
        if (diff & (1 << i)) cout << i << " ";
    }
    cout << "\n";

    // Complemento de x (los elementos que NO están en x)
    int comp = ~x;
    cout << "Complemento de x (primeros 10 bits): ";
    for (int i = 0; i < 10; i++) {
        if (comp & (1 << i)) cout << i << " ";
    }
    cout << "\n";

    return 0;
}