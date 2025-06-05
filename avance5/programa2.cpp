//C3:P2 3.1.1
#include <bits/stdc++.h>
using namespace std;
int main(){
    //1. Bucle anidado O(n²) (Suma triangular)
    int n;
    cin >> n;
    int count = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            count++; // Operación O(1)
        }
    }

    cout << "Operaciones: " << count << "\n"; // n(n+1)/2

    //2. Fases consecutivas (Complejidad dominante O(n²))
    int y;
    cin >> y;
    int counta = 0;

    // Fase 1: O(n)
    for (int i = 1; i <= y; i++) {
        counta++; 
    }

    // Fase 2: O(n²)
    for (int i = 1; i <= y; i++) {
        for (int j = 1; j <= y; j++) {
            counta++;
        }
    }

    // Fase 3: O(n)
    for (int i = 1; i <= y; i++) {
        counta++;
    }

    cout << "Operaciones totales: " << counta << "\n"; // n + n² + n

    //3. Complejidad O(nm) (Dos variables)
    int v, b;
    cin >> v >> b;
    int counte = 0;

    for (int i = 1; i <= v; i++) {
        for (int j = 1; j <= b; j++) {
            counte++; 
        }
    }

    cout << "Operaciones: " << counte << "\n"; // n*m

}