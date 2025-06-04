//C2:P3 2.3.1
#include <bits/stdc++.h>
using namespace std;

int main() {
    int x = 5328; // 00000000000000000001010011010000

    cout << __builtin_clz(x) << "\n";      // 19: ceros a la izquierda
    cout << __builtin_ctz(x) << "\n";      // 4: ceros a la derecha
    cout << __builtin_popcount(x) << "\n"; // 5: número de bits en 1
    cout << __builtin_parity(x) << "\n";   // 1: paridad (1 si impar número de bits en 1)

    return 0;
}