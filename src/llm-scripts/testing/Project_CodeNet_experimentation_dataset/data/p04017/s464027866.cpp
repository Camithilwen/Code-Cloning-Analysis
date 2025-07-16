#include<bits/stdc++.h>
using namespace std;
#define int long long
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define all(a) a.begin(),a.end()
#define rall(c) (c).rbegin(),(c).rend()
#define mp make_pair
#define endl '\n'
#define vec vector<ll>
#define mat vector<vector<ll> >
#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> pll;
typedef long double ld;
const ll inf=1e9+7;
const ll mod=1e9+7;
signed main(){
    ll n;cin>>n;
    vector<ll>x(n);
    rep(i,n)cin>>x[i];
    ll l,q;cin>>l>>q;
    vector<ll>nxt(n);
    vector<pll>b(0);
    for(int i=n-1;i>=0;i--){
        if(i==n-1){
            b.pb(mp(-x[i],i));
            nxt[i]=i;
            continue;
        }
        pll k=*lower_bound(all(b),mp(-x[i]-l,-1LL));
        nxt[i]=k.second;
        b.pb(mp(-x[i],i));
    }
    vector<vector<ll> >dp(n,vector<ll>(32));
    rep(i,n)dp[i][0]=nxt[i];
    REP(i,1,32){
        rep(j,n){
            dp[j][i]=dp[dp[j][i-1]][i-1];
        }
    }
    rep(i,32){
        //cout<<dp[0][i]<<endl;
    }
    while(q){
        q--;
        ll a,b;cin>>a>>b;
        a--;b--;
        if(a>b){
            swap(a,b);
        }
        ll l=0,r=n;
        while(r-l>1){
            ll mid=(r+l)/2;
            ll x=a;
            rep(j,32){
                if(mid&(1LL<<j)){
                    x=dp[x][j];
                }
            }
            if(q==3){
                //cout<<mid<<' '<<a<<' '<<b<<endl;
            }
            if(x>=b)r=mid;
            else l=mid;
        }
        cout<<r<<endl;
    }
}