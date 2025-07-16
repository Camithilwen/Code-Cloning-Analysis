#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
using ll = long long;
using ld = long double;
const int MOD = 1e9+7;


int main() {
    int a, b; cin >> a >> b;
    cout << max({a+b, a*b, a-b}) << endl;

    return 0;
}
