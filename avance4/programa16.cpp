//C2:P3 final 2.3.2
#include <bits/stdc++.h>
using namespace std;

int main() {
    bitset<10> s;
    s[1] = 1;
    s[3] = 1;
    s[4] = 1;
    s[7] = 1;
    cout << s[4] << "\n"; // 1
    cout << s[5] << "\n"; // 0
    cout << s.count() << "\n"; // 4

    // Operaciones con bitsets
    bitset<10> a, b;
    a[1] = 1; a[2] = 1; a[5] = 1;
    b[2] = 1; b[3] = 1; b[5] = 1;

    bitset<10> c = a & b; // Intersección
    bitset<10> d = a | b; // Unión
    bitset<10> e = a ^ b; // Diferencia simétrica

    cout << "a: " << a << "\n";
    cout << "b: " << b << "\n";
    cout << "a & b: " << c << "\n";
    cout << "a | b: " << d << "\n";
    cout << "a ^ b: " << e << "\n";

    return 0;
}