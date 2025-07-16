#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#include <deque>
#include <map>
#include <unordered_map>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define repr(e,x) for(auto& e:x)
using namespace std;
typedef long long ll;
typedef long double ld;
//typedef pair<int,int> P;
//ll const INF=1001001001;
//ll const INF=1001001001001001001;
ll const MOD=998244353;

ll mpow(ll x,ll n){
    if(n==0) return 1;
    else if(n%2) return x*mpow(x,n-1)%MOD;
    return mpow(x*x%MOD,n/2)%MOD;
}

ll N;
ll D[100000];
ll cnt[100000];

int main(){
    cin>>N;
    rep(i,N) cin>>D[i];

    if(D[0]!=0){
        cout<<0<<endl;
        return 0;
    }

    ll maxi=0;
    rep(i,N) maxi=max(maxi,D[i]);
    rep(i,N) cnt[D[i]]++;

    if(cnt[0]!=1){
        cout<<0<<endl;
        return 0;
    }

    ll ans=1;
    rep(i,maxi){
        ans*=mpow(cnt[i],cnt[i+1]);
        ans%=MOD;
    }

    cout<<ans<<endl;
}