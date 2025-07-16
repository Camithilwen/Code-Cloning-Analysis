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
    int a, b; cin >> a >> b;
    if(a == b || a - 1 == b || a == b - 1) cout << "Yay!" << endl;
    else cout << ":(" << endl;

    return 0;
}
