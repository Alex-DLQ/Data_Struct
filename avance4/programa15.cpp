//C2:P3 2.3.2
#include <bits/stdc++.h>
using namespace std;

int main() {
    // x = {1, 3, 4, 8}
    int x = (1 << 1) | (1 << 3) | (1 << 4) | (1 << 8);
    int b = 0;
    do {
        cout << "Subconjunto: ";
        for (int i = 0; i < 32; i++) {
            if (b & (1 << i)) cout << i << " ";
        }
        cout << "\n";
    } while (b = (b - x) & x);
    return 0;
}