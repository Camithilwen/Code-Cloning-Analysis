#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
using ll = long long;
using ld = long double;
const int MOD = 1e9+7;


int main() {
    int n; cin >> n;
    string s, t; cin >> s >> t;

    if(s == t) {
        cout << n << endl;
        return 0;
    }
    int ans = n * 2;
    for(int i = 0; i < n; i++){
        string tmpt = t.substr(0, i);
        string tmps = s.substr(n - i, i);
        if(tmpt == tmps) ans -= tmpt.size();
    }
    cout << ans << endl;

    return 0;
}
