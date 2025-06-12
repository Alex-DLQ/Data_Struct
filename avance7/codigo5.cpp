//C5:P5 5.2.2
#include <bits/stdc++.h>
#include <map>
using namespace std;

int main() {
    map<string, int> mapa;
    mapa["manzana"] = 5;
    mapa["naranja"] = 3;

    cout << "Cantidad de manzanas: " << mapa["manzana"] << "\n";
    cout << "Cantidad de naranjas: " << mapa["naranja"] << "\n";

    cout << "Elementos en el mapa:\n";
    for (auto par : mapa) {
        cout << par.first << ": " << par.second << "\n";
    }
}