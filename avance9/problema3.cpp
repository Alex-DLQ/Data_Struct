#include <iostream>
#include <stack>
#include <sstream> // Para stringstream (procesar strings)
#include <string>

using namespace std;

int main() {
    string linea;
    getline(cin, linea);
    stringstream ss(linea);
    stack<int> pila;
    string token;
    while (ss >> token) {
        if (isdigit(token[0]) || (token[0] == '-' && token.size() > 1)) {
            pila.push(stoi(token));
        } else {
            int b = pila.top(); pila.pop();
            int a = pila.top(); pila.pop();
            if (token == "+") pila.push(a + b);
            else if (token == "-") pila.push(a - b);
            else if (token == "*") pila.push(a * b);
            else if (token == "/") pila.push(a / b);
        }
    }
    cout << pila.top() << endl;
    return 0;
}