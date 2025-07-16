#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;
const ll mod = 1000000007;
const ll INF = 1e+14;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
#define _GLIBCXX_DEBUG

int main(){
    ll N;
    cin>>N;
    vector<ll> ex(N+10, 0);
    if(N!=1){
    for (ll i=2; i<N+1; i++){
        ll onway=i; //途中の数
        for(ll a=2; a*a<=onway; a++){
            if(onway%a!=0)continue;
            while(onway%a==0){
                ex[a]++;
                onway/=a;
            }
        }
        if(onway!=1) ex[onway]++;
    }
    }
    if(N==1) cout<<1<<endl;
    else {
        ll count=1;
        for(ll i=2; i<=N; i++){
            if(ex[i]==0)continue;
            count*=ex[i]+1;
            count%=mod;
        }
        cout<<count<<endl;
    }

}