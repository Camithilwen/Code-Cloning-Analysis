#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double pi=3.141592653589793;
typedef unsigned long long ull;
typedef long double ldouble;
const ll INF=1e18;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

// 最大公約数(ユークリッドの互除法)
// O(log max(a, b))
ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

int main(){
    int n, k, g;
    bool ans = false;
    cin >> n >> k;
    vector<int> a(n), b(n-1);
    rep(i, n){
        cin >> a.at(i);
    }
    sort(a.begin(), a.end());
    g = a.at(0);
    rep2(i, 1, n){
        if(a.at(i) != a.at(i-1)) g = gcd(g, a.at(i) - a.at(i-1));
    }
    rep(i, n){
        if(a.at(i) == k) {
            ans = true;
            break;
        }
        if((a.at(i) - k) > 0 && (a.at(i) - k) % g == 0) {
            ans = true;
            break;
        }
    }
    if(ans) cout << "POSSIBLE" << endl;
    else cout << "IMPOSSIBLE" << endl;

}