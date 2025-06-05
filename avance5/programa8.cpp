//C3:P3 3.3.2
#include <bits/stdc++.h>
using namespace std;

// Constante para módulo
const int M = 1e9 + 7;

int main() {
    int n;
    cin >> n;

    // Acceso cache-friendly
    {
        vector<vector<int>> x(n, vector<int>(n, 1));
        long long s = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                s += x[i][j];
        cout << "Cache-friendly: " << s << "\n";
    }

    // Acceso no cache-friendly
    {
        vector<vector<int>> x(n, vector<int>(n, 1));
        long long s = 0;
        for (int j = 0; j < n; j++)
            for (int i = 0; i < n; i++)
                s += x[i][j];
        cout << "No cache-friendly: " << s << "\n";
    }

    // Paralelismo simple en el cálculo de factorial
    {
        long long f1 = 1, f2 = 1;
        for (int i = 1; i <= n; i += 2) {
            f1 = (f1 * i) % M;
            if (i + 1 <= n)
                f2 = (f2 * (i + 1)) % M;
        }
        long long f = (f1 * f2) % M;
        cout << "Factorial paralelo (mod " << M << "): " << f << "\n";
    }

    return 0;
}
