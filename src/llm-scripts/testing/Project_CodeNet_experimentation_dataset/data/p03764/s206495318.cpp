#include<bits/stdc++.h>
using namespace std;
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll inf=1e9+7;
const ll mod=1e9+7;
int main(){
    ll n,m;cin>>n>>m;
    vector<ll>x(n);
    vector<ll>y(m);
    rep(i,n)cin>>x[i];
    rep(i,m)cin>>y[i];
    ll cnt1=0;
    rep(i,m-1){
        cnt1=(cnt1+((i+1)*(m-i-1)*(y[i+1]-y[i]))%inf)%inf;
    }
    ll cnt2=0;
    rep(i,n-1){
        cnt2=(cnt2+((i+1)*(n-i-1)*(x[i+1]-x[i]))%inf)%inf;
    }
    cout<<cnt1*cnt2%inf<<endl;
}