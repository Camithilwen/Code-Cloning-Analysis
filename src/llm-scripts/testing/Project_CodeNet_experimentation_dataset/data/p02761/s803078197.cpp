#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 100000000;
#define rep1(i, n) for (ll i=0; i<(n); i++) 
#define rep2(i, k, n) for (ll i=k; i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main() {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n, -1), s(n), c(n);
    rep1(i, m) cin >> s[i] >> c[i];
    rep1(i, m){
        if (a[s[i]-1]!=-1 && a[s[i]-1]!=c[i]){
            cout << -1 << endl;
            return 0;
        }
        a[s[i]-1] = c[i];
    }
    if (a[0]==0 && n>1){
        cout << -1 << endl;
        return 0;
    }
    rep1(i, n){
        if (i==0 && n>1){
            if (a[i]==-1) cout << 1;
            else cout << a[i];
        }else{
            if (a[i]==-1) cout << 0;
            else cout << a[i];
        }
    }
}