#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
using ll = long long;
using ld = long double;
const int MOD = 1e9+7;
const ll INF = 1LL << 60;


int main() {
    int x, y; cin >> x >> y;
    if(x + y == 2) cout << 1000000 << endl;
    else if(x + y == 3) cout << 500000 << endl;
    else if(x + y == 4) cout << 400000 << endl;
    else if(x + y == 5) cout << 300000 << endl;
    else if(x + y == 6) cout << 200000 << endl;
    else if(x == 3 || y == 3) cout << 100000 << endl;
    else cout << 0 << endl;

    return 0;
}
