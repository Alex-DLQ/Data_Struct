#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    queue<int> cola;
    for (int i = 0; i < N; ++i) {
        int x; cin >> x;
        cola.push(x);
    }
    stack<int> pila;
    for (int i = 0; i < K; ++i) {
        pila.push(cola.front());
        cola.pop();
    }
    while (!pila.empty()) {
        cola.push(pila.top());
        pila.pop();
    }
    for (int i = 0; i < N - K; ++i) {
        cola.push(cola.front());
        cola.pop();
    }
    for (int i = 0; i < N; ++i) {
        cout << cola.front() << (i == N-1 ? '\n' : ' ');
        cola.pop();
    }
    return 0;
}