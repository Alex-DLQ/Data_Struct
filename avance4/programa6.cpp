//C2:P3 2.2.2
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> permutation;
    for (int i = 1; i <= n; i++) {
        permutation.push_back(i);
    }
    do {
        for (int x : permutation) cout << x << " ";
        cout << "\n";
    } while (next_permutation(permutation.begin(), permutation.end()));
    return 0;
}