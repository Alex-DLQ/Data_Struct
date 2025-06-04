//C2:P3 2.3.2
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int b = 0; b < (1 << n); b++) {
        cout << "Subconjunto: ";
        for (int i = 0; i < n; i++) {
            if (b & (1 << i)) cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}