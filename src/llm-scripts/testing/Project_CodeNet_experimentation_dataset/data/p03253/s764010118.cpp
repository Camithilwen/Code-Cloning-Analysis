#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<cstdio>
#include<queue>
#include<deque>
#include<map>
#include<stack>
#include<set>
#include<utility>
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
typedef pair<ll,ll> P;
typedef unsigned long long int ull;
const ll MOD=1e9+7;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
const int MAXN=100000;
const int MAXE=100000;
const int MAXV=10000;
const ll INF=2e9;

vector<ll> fac(10000000),inv(10000000),finv(10000000);
void initCOM(){
    fac[0]=fac[1]=1;
    inv[1]=1;
    finv[0]=finv[1]=1;
    for(int i=2;i<10000000;i++){
        fac[i]=fac[i-1]*i%MOD;
        inv[i]=MOD-inv[MOD%i]*(MOD/i)%MOD;
        finv[i]=finv[i-1]*inv[i]%MOD;
    }
}
ll COM(int n,int k){
    if(n<0||k<0) return 0;
    if(n-k<0) return 0;
    return fac[n]*(finv[k]*finv[n-k]%MOD)%MOD;
}
vector<ll> prime_factor(ll m){
    vector<ll> res;
    for(int i=2;i*i<=m;i++)if(m%i==0){
        ll cnt=0;
        while(m%i==0){
            m/=i;
            cnt++;
        }
        res.push_back(cnt);
    }
    if(m>1) res.push_back(1);
    return res;
}
int main(){
    initCOM();
    ll n,m;cin>>n>>m;
    auto p=prime_factor(m);
    ll ans=1;
    for(auto b:p){
        ans=ans*COM(b+n-1,n-1)%MOD;
    }
    cout<<ans<<endl;
    return 0;
}