#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;
const int MOD2 = 998244353;


// ref : https://atcoder.jp/contests/jsc2019-qual/submissions/16521703

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    string t;
    char c = 'W';
    rep(i, 2 * n){
        if (s[i] != c){
            t += 'L';
            if (c == 'W') c = 'B';
            else c = 'W';
        }
        else {
            t += 'R';
            if (c == 'W') c = 'B';
            else c = 'W';
        }
    }
    
   int cnt = 0;
    rep(i, 2 * n) cnt += (t[i] == 'L');
    if (cnt != n) {
        cout << 0 << endl;
        return 0;
    }
    
    ll ans = 1;
    ll l = 0;
    rep(i, 2 * n){
        if (t[i] == 'L'){
            l++;
        }
        else {
            ans *= l;
            ans %= MOD;
            l--;
        }
    }

    for(ll i = 1; i <= n; i++){
        ans *= i;
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}
