#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<ll(n);i++)

int main() {
    int n, m;
    cin >> n >> m;
    int p;
    string s;
    vector<int>v(n, 0);
    int c = 0, w = 0;
    rep(i, m) {
        cin >> p >> s;
        p--;
        if (v[p] != -1) {
            if (s == "AC") {
                w += v[p];
                c++;
                v[p] = -1;
            }else{
                v[p]++;
            }
        }
    }

    cout << c << ' ';
    cout << w << endl;
    return 0;
}
