#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for (ll i = (a); i < (b); i++)
#define REP(i,n) rep(i,0,n)
#define mod (1000000007)

void solve() 
{
    int n;cin>>n;
    int a[n],b[n],c[n+1],d[n+1];
    REP(i,n)cin>>a[i];REP(i,n)cin>>b[i];
    REP(i,n+1)c[i]=d[i]=0;
    REP(i,n)c[a[i]]++,d[b[i]]++;
    REP(i,n+1)if(c[i]+d[i]>n){cout<<"No"<<endl;return;}
    cout<<"Yes"<<endl;
    rep(i,1,n+1)c[i]+=c[i-1],d[i]+=d[i-1];
    int x=0;rep(i,1,n+1)x=max(x,c[i]-d[i-1]);
    REP(i,n)cout<<(i?" ":"")<<b[(i+n-x)%n];cout<<endl;
}

int main()
{
    cin.tie(0);
	ios::sync_with_stdio(false);
    solve();
    return 0;
}