//C3:P2 3.1.1
#include <bits/stdc++.h>
using namespace std;

// Función recursiva O(n)
void f(int n, int& calls) {
    calls++;
    if (n == 1) return;
    f(n - 1, calls);
}

// Función recursiva O(2ⁿ)
void g(int n, int& calls) {
    calls++;
    if (n == 1) return;
    g(n - 1, calls);
    g(n - 1, calls);
}

int main() {
    // Prueba de función recursiva O(n)
    int n;
    cout << "Introduce n para f(n): ";
    cin >> n;
    int llamadas_f = 0;
    f(n, llamadas_f);
    cout << "Llamadas recursivas de f(n): " << llamadas_f << "\n";

    // Prueba de función recursiva O(2ⁿ)
    int m;
    cout << "Introduce n para g(n): ";
    cin >> m;
    int llamadas_g = 0;
    g(m, llamadas_g);
    cout << "Llamadas recursivas de g(n): " << llamadas_g << "\n";

    return 0;
}



