#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool esBalanceado(const string &s) {
    stack<char> pila;
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            pila.push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (pila.empty()) return false;
            char top = pila.top();
            if ((c == ')' && top != '(') ||
                (c == ']' && top != '[') ||
                (c == '}' && top != '{')) return false;
            pila.pop();
        }
    }
    return pila.empty();
}

int main() {
    string s;
    getline(cin, s);
    cout << (esBalanceado(s) ? "YES" : "NO") << endl;
    return 0;
}