#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < (long long)(n); i++)
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
const int inf = 1001001001;
 
int main(){

    ll n, q;
    string s;
    cin >> n >> q >> s;
    vector<ll> dp(n, 0);
    for(ll i = 0; i < n-1; i++){
        if(s[i] == 'A' && s[i+1] == 'C'){
            dp[i+1] = (dp[i] + 1);
        }
        else{
            dp[i+1] = dp[i];
        }
    }

    while(q){
        ll l,r;
        cin >> l >> r;
        cout << dp[r-1] - dp[l-1] << endl;
        q--;
    }
    
 
}