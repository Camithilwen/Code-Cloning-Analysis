#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
int main(){
    ios::sync_with_stdio(false);
    int n,k;
    cin >> n >> k;
    int g;
    cin >> g;
    int max=g;
    rep(i,n-1) {
        int a;
        cin >> a;
        chmax(max, a);
        g = __gcd(g,a);
    }
    if(k > max) cout << "IMPOSSIBLE" << endl;
    else if(k%g == 0) cout << "POSSIBLE" << endl;
    else cout << "IMPOSSIBLE" << endl;
}
