#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<P,ll> PLL;
typedef pair<P,P> PP;
typedef vector<ll> VECLL;
typedef vector<P> VECP;
typedef priority_queue<P,VECP,greater<P> > PQP;
typedef priority_queue<ll, VECLL, greater<ll> > PQll;

#define rep(i,a,n) for(ll i = a;i < n;i++)
#define rrep(i,a,n) for(ll i = n; i >= a;i--)
#define index_check(i,n) if(i > n-1 || i < 0) continue;
#define LINF (ll)1e18
#define INF (int)1e9
#define fs first
#define sc second

template<typename T>
ll sz(vector<T> vec){ return (ll)vec.size(); }
ll sz(string s){ return (ll)s.size(); }

ll gcd(ll a,ll b){ return ((!b) ?a :gcd(b, a%b)); }

int main(){
    ll n,m,q;
    cin >> n >> m >> q;
    ll imos[n][n] = {};

    rep(i,0,m){
        ll l,r;
        cin >> l >> r;
        imos[0][r-1] += 1;
        if(l != n) imos[l][r-1] -= 1;
    }

    rep(i,0,n) rep(j,1,n) imos[i][j] += imos[i][j-1];
    rep(j,0,n) rep(i,1,n) imos[i][j] += imos[i-1][j]; 
    
    rep(i,0,q){
        ll l,r;
        cin >> l >> r;
        cout << imos[l-1][r-1] << endl;
    }
    return 0;
}


