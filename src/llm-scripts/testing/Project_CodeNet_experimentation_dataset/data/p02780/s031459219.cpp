#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define repr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define invrepr(i,a,b) for(int i=b-1;i>=a;i--)
#define invrep(i,n) invrepr(i,0,n)
#define repitr(itr,a) for(auto itr=a.begin();itr!=a.end();++itr)
#define P pair<int,int>
const int MOD=1e9+7;
const int INF=2e9;
const double PI=acos(-1);


int main() {
    ios_base::sync_with_stdio(false);

    ll n,k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<ll> b(n-k+1);
    rep(i,k) b[0]+=a[i];
    rep(i,n-k) {
        b[i+1]=b[i]+a[k+i]-a[i];
    }
    sort(b.begin(),b.end(),greater<>());
    double ans=1.0*(b[0]+k)/2;
    cout << fixed << setprecision(20) << ans << endl;

    
    return 0;   
}