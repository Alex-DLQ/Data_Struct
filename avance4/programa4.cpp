//2.2.1
#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> subset;

void search(int k) {
    if (k == n + 1) {
        // Procesar el subconjunto
        cout << "{";
        for (size_t i = 0; i < subset.size(); i++) {
            cout << subset[i] << (i + 1 < subset.size() ? ", " : "");
        }
        cout << "}\n";
    } else {
        subset.push_back(k);
        search(k + 1);
        subset.pop_back();
        search(k + 1);
    }
}

int main() {
    cin >> n;
    search(1);
    return 0;
}