#include <bits/stdc++.h>
using namespace std;  
#define rep(i, a, b) for(ll i = a; i < b; i++)
#define Rep(i, a, b) for(ll i = a; i <= b; i++)
#define repr(i, a, b) for(ll i = b-1; i >= a; i--)
#define _GLIBCXX_DEBUG
#define Vl vector<ll>
#define Vs vector<string>
#define Vp vector<pair<ll, ll>>
using ll = long long;
#define ALL(v) (v).begin(),(v).end()
#define endl "\n"
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
#define co(x) cout << x << endl
#define coel cout << endl
#define pb push_back
#define sz(v) ((ll)(v).size())
const double pi = acos(-1.0);
const ll MOD = 1e9 + 7;
// const ll INF = 1LL << 60;
const ll INF = 100000000000;
#define pp pair<ll, pair<ll, ll>> 
// #define fi first
// #define se second
 
/*--------------------------------------------------------------------------------

--------------------------------------------------------------------------------*/

bool IsPrime(int n){
    if (n<2) return false;
    else if (n==2) return true;
    else if (n%2==0) return false;
    double q=sqrt(n);
    for(int i=3;i<q+1;i+=2){
        if(n%i==0){
            return false;
        }
    }
    return true;
}

int main(){
    // 1~55555 で 5の倍数+1 の素数を列挙
    Vl sosu;
    for(ll i = 1; i <= 55555; i += 5){
        if(IsPrime(i)) sosu.push_back(i);
    }
    ll n; cin >> n;
    rep(i, 0, n) cout << sosu[i] << " \n"[i==n-1];

    return 0;
}
