#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    ll n = s.size();
    ll S = 0, P = 0;
    rep(i,n){
        if(s[i] == 'S') ++S;
        else{
            if(S > 0){
                ++P;
                --S;
            }
        }
        chmax(S, 0LL);
    }
    ll ans = n - P*2;
    cout << ans << endl;
    return 0;
}
