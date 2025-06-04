//2.3
#include <bits/stdc++.h>
using namespace std;

int main() {
    int x = -43;
    unsigned int y = x;
    cout << x << "\n"; // -43
    cout << y << "\n"; // 4294967253 (en sistemas de 32 bits)
    return 0;
}