//C3:P3 3.2.2 Two Queens Problem
#include <bits/stdc++.h>
using namespace std;

// Función para verificar si dos reinas se atacan
bool attack(int x1, int y1, int x2, int y2) {
    return x1 == x2 || y1 == y2 || abs(x1 - x2) == abs(y1 - y2);
}

int main() {
    int n;
    cin >> n;

    // O(n⁴): Fuerza bruta
    {
        int count = 0;
        for (int x1 = 0; x1 < n; x1++) {
            for (int y1 = 0; y1 < n; y1++) {
                for (int x2 = 0; x2 < n; x2++) {
                    for (int y2 = 0; y2 < n; y2++) {
                        if (x1 == x2 && y1 == y2) continue;
                        if (!attack(x1, y1, x2, y2)) count++;
                    }
                }
            }
        }
        cout << "O(n^4): " << count / 2 << "\n"; // Cada combinación se cuenta dos veces
    }

    // O(n²): Usando observaciones matemáticas
    {
        int total = 0;
        for (int x1 = 0; x1 < n; x1++) {
            for (int y1 = 0; y1 < n; y1++) {
                int attack = 0;
                attack += (n - 1); // misma fila
                attack += (n - 1); // misma columna
                attack += min(x1, y1); // diagonal arriba-izquierda
                attack += min(n - 1 - x1, n - 1 - y1); // diagonal abajo-derecha
                attack += min(x1, n - 1 - y1); // diagonal arriba-derecha
                attack += min(n - 1 - x1, y1); // diagonal abajo-izquierda
                total += n * n - 1 - attack;
            }
        }
        cout << "O(n^2): " << total / 2 << "\n";
    }

    // O(1): Fórmula cerrada
    {
        long long q = (3LL * n * n * n * n - 10LL * n * n * n + 9LL * n * n - 2LL * n) / 6;
        cout << "O(1): " << q << "\n";
    }

    return 0;
}