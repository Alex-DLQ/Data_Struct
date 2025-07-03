#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

int main() {
    string s, limpio;
    getline(cin, s);
    for (char c : s) {
        if (isalpha(c)) limpio += tolower(c);
    }
    stack<char> pila;
    int n = limpio.size();
    for (int i = 0; i < n/2; ++i) pila.push(limpio[i]);
    int start = (n % 2 == 0) ? n/2 : n/2 + 1;
    bool esPal = true;
    for (int i = start; i < n; ++i) {
        if (pila.top() != limpio[i]) {
            esPal = false;
            break;
        }
        pila.pop();
    }
    cout << (esPal ? "YES" : "NO") << endl;
    return 0;
}