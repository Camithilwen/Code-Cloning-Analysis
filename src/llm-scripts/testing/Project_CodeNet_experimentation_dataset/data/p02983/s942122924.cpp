#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000007
const int INF = 1LL<<30;
 
int main(){
    ll l,r;
    cin>>l>>r;
    
    ll ans=3000;
    for(int i=l;i<=min(r,l+3000);i++){
        for(int j=i+1;j<=min(r,l+3000);j++){
            ll tmp=((i%2019)*(j%2019))%2019;
            ans=min(ans,tmp);
        }
    }

    cout<<ans<<endl;
}