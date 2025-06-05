//C3:P3 3.2.1
// 2. Suma Máxima de Subarreglo (Maximum Subarray Sum)
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> array(n);
    for (int& x : array) cin >> x;

    // O(n³) solución
    {
        int best = 0;
        for (int a = 0; a < n; a++) {
            for (int b = a; b < n; b++) {
                int sum = 0;
                for (int k = a; k <= b; k++) {
                    sum += array[k];
                }
                best = max(best, sum);
            }
        }
        cout << "O(n^3) best sum: " << best << "\n";
    }

    // O(n²) solución
    {
        int best = 0;
        for (int a = 0; a < n; a++) {
            int sum = 0;
            for (int b = a; b < n; b++) {
                sum += array[b];
                best = max(best, sum);
            }
        }
        cout << "O(n^2) best sum: " << best << "\n";
    }

    // O(n) solución (Algoritmo de Kadane)
    {
        int best = 0, sum = 0;
        for (int k = 0; k < n; k++) {
            sum = max(array[k], sum + array[k]);
            best = max(best, sum);
        }
        cout << "O(n) best sum (Kadane): " << best << "\n";
    }

    return 0;
}