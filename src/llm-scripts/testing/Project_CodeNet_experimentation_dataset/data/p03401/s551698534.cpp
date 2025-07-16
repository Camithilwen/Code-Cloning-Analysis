#include <bits/stdc++.h>
#define REP(i, n) for(long long i=0; i<n; i++)
#define REPR(i, n) for(long long i=n-1; i>=0; i--)
#define FOR(i, m, n) for(long long i=m; i<=n; i++)
#define FORR(i, m, n) for(long long i=m; i>=n; i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define VSORTR(v) sort(v.rbegin(), v.rend());
#define ALL(v) (v).begin(),(v).end()
#define FIN ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;
using ll = long long;
using ull = unsigned long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll, ll>;
const ll mod = 1e9+7;
const ll inf = 1e15;
ll power(ll a,ll b){return b?power(a*a%mod,b/2)*(b%2?a:1)%mod:1;}


char a[55][55];

int main(){FIN

    ll n;cin>>n;
    vll a(n);
    REP(i,n) cin>>a[i];
    ll dis=0;
    REP(i,n){
        if(i==0) dis += abs(a[0]);
        else dis += abs(a[i]-a[i-1]);
    }
    dis += abs(a[n-1]);

    REP(i,n){
        ll dis2=dis;
        if (i==0) {
            dis2 -= abs(a[0]);
            dis2 -= abs(a[1]-a[0]);
            dis2 += abs(a[1]);
        }
        else if (i==n-1){
            dis2 -= abs(a[n-1]);
            dis2 -= abs(a[n-2]-a[n-1]);
            dis2 += abs(a[n-2]);
        }
        else {
            dis2 -= abs(a[i-1]-a[i]);
            dis2 -= abs(a[i]-a[i+1]);
            dis2 += abs(a[i-1]-a[i+1]);
        }
        cout<<dis2<<endl;
    }
    return 0;
}