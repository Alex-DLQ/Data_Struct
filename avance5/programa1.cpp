//C3:P2 3.1.1
#include <bits/stdc++.h>
using namespace std;
int main(){
    //1. Código de complejidad O(1)
    int a = 1, b = 2, c;
    a++;
    b++;
    c = a + b;
    cout << c << "\n";

    //2. Bucle de complejidad O(n)
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        // Operación O(1)
        cout << i << " ";
    }
    cout << "\n";

    //3. Bucle anidado de complejidad O(n²)
    int p;
    cin >> p;
    for (int i = 1; i <= p; i++) {
        for (int j = 1; j <= p; j++) {
            // Operación O(1)
            cout << "(" << i << "," << j << ") ";
        }
        cout << "\n";
    }

    //4. Bucle con constante multiplicativa (O(n))
    int q;
    cin >> q;
    for (int i = 1; i <= 3 * q; i++) {
        // Operación O(1)
        cout << i << " ";
    }
    cout << "\n";
    
    //5. Bucle con suma constante (O(n))
    int z;
    cin >> z;
    for (int i = 1; i <= z + 5; i++) {
        // Operación O(1)
        cout << i << " ";
    }
    cout << "\n";

    //6. Bucle con incremento mayor a 1 (O(n))
    int g;
    cin >> g;
    for (int i = 1; i <= g; i += 2) {
        // Operación O(1)
        cout << i << " ";
    }
    cout << "\n";
}