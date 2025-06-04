// C2:P3 2.1.3
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)

int main() {
    ll a = 123456789, b = 987654321;
    cout << a * b << "\n";

    vi v;
    v.PB(1);
    v.PB(2);
    cout << v[0] << " " << v[1] << "\n";

    return 0;
}