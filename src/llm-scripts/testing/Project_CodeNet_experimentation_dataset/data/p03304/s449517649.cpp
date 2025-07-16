#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i=ll(a);i<ll(b);i++)
#define irep(i,a,b) for(ll i=ll(a);i>=ll(b);i--)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
#define pb push_back
#define mp make_pair
#define F .first
#define S .second 
using ll=long long;
using ld=long double;
const ll INF = 1LL<<60;
const ll mod=1e9+7;
using namespace std;
ll GCD(ll a, ll b) { return b ? GCD(b, a%b) : a; }


int main(){
    ld n,m,d,x=2;
    cin>>n>>m>>d;
    if(d==0)x=1; // n/n^2
    //ans=2*(n-2*d) d+1~n-d[i+d,i-d]   2通り
    //ans+=2*d      1~d[i+d] n-d~n[i-d] 1通り
    cout<<fixed<<setprecision(12)<<(m-1)*x*(n-d)/(n*n);;
}