#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for (ll i = (a); i < (b); i++)
#define REP(i,n) rep(i,0,n)

void solve() 
{
    int n;cin>>n;
    int a[n],b[n];
    REP(i,n)cin>>a[i];
    REP(i,n)cin>>b[i];
    int j=0,now=-1;
    REP(i,n){
        if(now!=a[i])j=0;
        if(a[i]==b[i]){
            for(;j<n;j++){
                if(a[i]!=a[j]&&a[i]!=b[j]){
                    swap(b[i],b[j]);
                    break;
                }
            }
            if(j==n){cout<<"No"<<endl;return;}
        }
        now=a[i];
    }
    cout<<"Yes"<<endl;
    REP(i,n)cout<<(i?" ":"")<<b[i];cout<<endl;
}

int main()
{
    cin.tie(0);
	ios::sync_with_stdio(false);
    solve();
    return 0;
}