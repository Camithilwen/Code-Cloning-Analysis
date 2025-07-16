#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)
#define pb emplace_back
typedef long long ll;
typedef pair<int,int> pint;

const int mod=1000000007;
int n,m;
int ca,cb;
ll a[1001],b[1001];
set<ll> sa,sb;
int main(){
    cin>>n>>m;
    bool flag=false;
    rep(i,n){
        cin>>a[i];
        if(sa.count(a[i])==0) sa.insert(a[i]);
        else flag=true;
    }
    rep(i,m){
        cin>>b[i];
        if(sb.count(b[i])==0) sb.insert(b[i]);
        else flag=true;
    }
    if(flag){
        cout<<0<<endl;
        return 0;
    }
    ll ans=1;
    for(int i=n*m;i>=1;--i){
        int ac=sa.count(i),bc=sb.count(i);
        if(ac==0&&bc==0){
            ans*=(1ll*ca*cb-n*m+i);
        }
        else if(ac==0){
            ++cb;
            ans*=1ll*ca;
        }
        else if(bc==0){
            ++ca;
            ans*=1ll*cb;
        }
        else ++ca,++cb;
        ans%=mod;
    }
    cout<<ans<<endl;
    return 0;
}
