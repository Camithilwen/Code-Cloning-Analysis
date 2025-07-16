#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,a,n) for(ll i = a;i < n;i++)
#define rrep(i,a,n) for(ll i = n; i >= a;i--)
#define index_check(i,n) if(i > n-1 || i < 0) continue; 
#define LINF 1e18
#define INF 1e9
using namespace std;

#define fs first
#define sc second

using P = pair<ll,ll>;
using Pll = pair<P,ll>;
using PQ = priority_queue<P,vector<P>,greater<P>>;

signed main(){
    ll n,m,d;
    cin >> n >> m >> d;
    if(d == 0) cout << setprecision(10) << 1.0/(double)n*(double)(m-1) << endl;
    else cout << setprecision(10) << (double)(2*n - 2*d)/(double)(n*n)*(m-1) << endl;
    return 0;
}
