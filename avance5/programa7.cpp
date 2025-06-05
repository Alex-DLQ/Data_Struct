//C2:P2 // 3.3
// 4. Optimización de Búsqueda en un Array
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Leer entrada una vez
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int& y : a) cin >> y;

    // Búsqueda normal O(n)
    {
        bool ok = false;
        for (int i = 0; i < n; i++) {
            if (a[i] == x) ok = true;
        }
        cout << "Busqueda normal: " << (ok ? "YES" : "NO") << "\n";
    }

    // Búsqueda con break (más eficiente en la práctica)
    {
        bool ok = false;
        for (int i = 0; i < n; i++) {
            if (a[i] == x) { ok = true; break; }
        }
        cout << "Busqueda con break: " << (ok ? "YES" : "NO") << "\n";
    }

    // Búsqueda con centinela
    {
        vector<int> b = a;
        b.push_back(x); // centinela
        int i = 0;
        while (b[i] != x) i++;
        bool ok = (i < n);
        cout << "Busqueda con centinela: " << (ok ? "YES" : "NO") << "\n";
    }

    return 0;
}
