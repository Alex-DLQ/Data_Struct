#include <iostream>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

int main() {
    int N;
    cin >> N;
    cin.ignore();
    stack<string> atras, adelante;
    string actual = "NONE";
    for (int i = 0; i < N; ++i) {
        string linea;
        getline(cin, linea);
        stringstream ss(linea);
        string cmd, url;
        ss >> cmd;
        if (cmd == "VISIT") {
            ss >> url;
            if (actual != "NONE") atras.push(actual);
            actual = url;
            while (!adelante.empty()) adelante.pop();
        } else if (cmd == "BACK") {
            if (!atras.empty()) {
                adelante.push(actual);
                actual = atras.top();
                atras.pop();
            }
        } else if (cmd == "FORWARD") {
            if (!adelante.empty()) {
                atras.push(actual);
                actual = adelante.top();
                adelante.pop();
            }
        }
        cout << (actual != "NONE" ? actual : "NONE") << endl;
    }
    return 0;
}