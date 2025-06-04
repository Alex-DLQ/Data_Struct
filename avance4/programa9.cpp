//C2:P3 2.3
#include <bits/stdc++.h>
using namespace std;

int main() {
    int x = 2147483647;
    cout << x << "\n"; // 2147483647
    x++;
    cout << x << "\n"; // -2147483648 (overflow)
    return 0;
}