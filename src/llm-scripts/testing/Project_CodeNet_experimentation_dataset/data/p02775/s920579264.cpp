#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define ve vector

int main(){
    string s;
    cin >> s;
    ll n = s.size();
    reverse(s.begin(), s.end());
    ve<int> b(n+1);
    rep(i,n) b[i] = s[i] - '0';
    b[n] = 0;
    rep(i,n){
        if(b[i] >= 6 || (b[i] == 5 && b[i+1] >= 5)){
            b[i] = 10 - b[i];
            b[i+1]++;
        }
    }
    ll ans = 0;
    rep(i,n+1) ans += b[i];
    cout << ans << endl;
    return 0;
}