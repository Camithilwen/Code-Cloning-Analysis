#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define inf (ll)1e9
#define mod (ll)(1e9+7)
#define d(x) cerr<<#x<<"="<<x<<endl;
#define p(x) cout<<x<<endl
#define pfix(d,x) cout << fixed << setprecision(d) << x << endl;
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define minel(v) *min_element(all(v))
#define minind(v) distance((v).begin(), min_element(all(v)))
#define maxel(v) *max_element(all(v))
#define maxind(v) distance((v).begin(), max_element(all(v)))
typedef vector<int> vi;

ll n,m,x[100001],y[100001];
ll xsum,ysum;
int main(void){
    cin>>n>>m;
    rep(i,n)cin>>x[i];
    rep(i,m)cin>>y[i];
    rep(i,n){xsum=(xsum+i*x[i]-(n-1-i)*x[i])%mod;d(xsum)}
    rep(i,m){ysum=(ysum+i*y[i]-(m-1-i)*y[i])%mod;d(ysum)}
    p((xsum*ysum)%mod);
    return 0;
}
