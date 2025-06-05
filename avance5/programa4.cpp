//C3:P3 3.1.2 y 3.1.3 y 3.1.4
#include <bits/stdc++.h>
using namespace std;

// O(log n): Búsqueda binaria
int binary_search_example(const vector<int>& arr, int x) {
    int l = 0, r = arr.size() - 1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (arr[m] == x) return m;
        if (arr[m] < x) l = m + 1;
        else r = m - 1;
    }
    return -1;
}

int main() {
    // O(1): Tiempo constante
    cout << "O(1): Tiempo constante\n";
    int a = 5, b = 7, c;
    c = a + b;
    cout << c << endl;

    // O(log n): Búsqueda binaria
    cout << "\nO(log n): Busqueda binaria\n";
    vector<int> arr1 = {1, 3, 5, 7, 9, 11, 13};
    int x1 = 7;
    cout << binary_search_example(arr1, x1) << endl; // Output: 3

    // O(√n): Prueba de divisibilidad
    cout << "\nO(raiz cuadrada de n): Prueba de divisibilidad\n";
    int n_sqrt = 100;
    for (int i = 1; i * i <= n_sqrt; i++) {
        if (n_sqrt % i == 0) cout << i << " ";
    }
    cout << endl;

    // O(n): Recorrido lineal
    cout << "\nO(n): Recorrido lineal\n";
    vector<int> arr2 = {2, 4, 6, 8, 10};
    int sum = 0;
    for (int x : arr2) sum += x;
    cout << sum << endl;

    // O(n log n): Ordenamiento
    cout << "\nO(n log n): Ordenamiento\n";
    vector<int> arr3 = {5, 2, 8, 1, 3};
    sort(arr3.begin(), arr3.end());
    for (int x : arr3) cout << x << " ";
    cout << endl;

    // O(n²): Doble bucle anidado
    cout << "\nO(n elevado al 2): Doble bucle anidado\n";
    int n2 = 5, count2 = 0;
    for (int i = 0; i < n2; i++)
        for (int j = 0; j < n2; j++)
            count2++;
    cout << count2 << endl;

    // O(n³): Triple bucle anidado
    cout << "\nO(n elevado al 3): Triple bucle anidado\n";
    int n3 = 3, count3 = 0;
    for (int i = 0; i < n3; i++)
        for (int j = 0; j < n3; j++)
            for (int k = 0; k < n3; k++)
                count3++;
    cout << count3 << endl;

    // O(2ⁿ): Subconjuntos
    cout << "\nO(2 elevado a la n): Subconjuntos\n";
    int n_sub = 3;
    for (int mask = 0; mask < (1 << n_sub); mask++) {
        for (int i = 0; i < n_sub; i++)
            if (mask & (1 << i)) cout << (i + 1) << " ";
        cout << endl;
    }

    // O(n!): Permutaciones
    cout << "\nO(n!): Permutaciones\n";
    vector<int> arr4 = {1, 2, 3};
    do {
        for (int x : arr4) cout << x << " ";
        cout << endl;
    } while (next_permutation(arr4.begin(), arr4.end()));

    return 0;
}
