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
typedef long long ll;
typedef pair<ll,ll> pll;
typedef long double ld;
const ll inf=1e9+7;
const ll mod=1e9+7;
const double PI=acos(-1.0);
signed main(){
    ll n;cin>>n;
    vector<ll>x(n),y(n);
    rep(i,n){
        cin>>x[i]>>y[i];
    }
    rep(i,n){
        vector<double>a(0);
        rep(j,n){
            if(i==j)continue;
            a.pb(atan2(y[j]-y[i],x[j]-x[i]));
        }
        ll m=a.size();
        rep(i,m){
            a.pb(a[i]+2.0*PI);
        }
        sort(all(a));
        double ma=0.0;
        rep(i,m*2-1){
            ma=max(ma,a[i+1]-a[i]);
        }
        ma=max(0.0,ma-PI);
        cout<<fixed<<setprecision(10)<<ma/PI/2.0<<endl;
    }
}