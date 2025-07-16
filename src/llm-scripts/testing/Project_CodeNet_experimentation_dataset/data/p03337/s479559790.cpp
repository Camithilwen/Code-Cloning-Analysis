#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
typedef vector<ll> vel;
typedef vector<str> ves;
#define REP(i, a, b) for (ll i = (ll)(a); i < (ll)(b); i++)
#define rep(i, b) REP(i, 0, b)
const ll mod = 1000000007;
const double pi = 3.14159265358979;

ll expo(ll a, ll b){
    ll ex = 1;
    rep(i, b){
        ex *= a;
    }
    return ex;
}

ll fact(ll a){
    ll fc = 1;
    REP(i, 1, a+1){
        fc *= i;
    }
    return fc;
}

int main() {
    ll a, b;
    cin >> a >> b;
    cout << max(a+b, max(a-b, a*b)) << endl;
}