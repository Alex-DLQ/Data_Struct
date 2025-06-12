//C5:P5 5.2.1
#include <bits/stdc++.h>
#include <set>
using namespace std;

int main() {
    set<int> conjunto;
    conjunto.insert(5);
    conjunto.insert(3);
    conjunto.insert(5); // No se duplica en set

    cout << "Elementos en el conjunto: ";
    for (int x : conjunto) cout << x << " ";
    cout << "\n";

    multiset<int> multiconjunto;
    multiconjunto.insert(5);
    multiconjunto.insert(3);
    multiconjunto.insert(5); // Se permite duplicado

    cout << "Elementos en el multiconjunto: ";
    for (int x : multiconjunto) cout << x << " ";
    cout << "\n";
}