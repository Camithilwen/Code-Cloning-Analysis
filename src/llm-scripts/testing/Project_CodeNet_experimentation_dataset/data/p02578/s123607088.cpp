#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i < (int)(n); i++)
#define Sort(a) sort(a.begin(), a.end())
typedef long long int ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
template <class T> inline bool chmax(T& a,T b){if(a<b){a=b;return true;} return false;}
template <class T> inline bool chmin(T& a,T b){if(a>b){a=b;return true;} return false;}

int main(){
    ll n;
    cin >> n;
    vi a(n);
    rep(i, n) {
        cin >> a.at(i);
    }
    ll ans = 0;
    rep(i, n-1) {
        if(a.at(i) >= a.at(i+1)) {
            ans += a.at(i) - a.at(i+1);
            a.at(i+1) = a.at(i);
        }
    }
    cout << ans << endl;
    return 0;
}