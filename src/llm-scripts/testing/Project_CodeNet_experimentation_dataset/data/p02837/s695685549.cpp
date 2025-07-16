#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    ll n;
    cin >> n;
    ll g[15][15];
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++)g[i][j]=-1;
    }
    for(ll i=0;i<n;i++){
        ll m;
        cin >> m;
        for(ll j=0;j<m;j++){
            ll a,x;
            cin >> a >> x;
            a--;
            g[i][a]=x;
        }
    }
    ll ans=0;
    for(ll i=0;i<(1<<n);i++){
        vector<ll>d(n);
        ll cnt=0;
        for(ll j=0;j<n;j++){
            if((i>>j)&1){
                d[j]=1;
                cnt++;
            }
        }
        bool judge=true;
        for(ll j=0;j<n;j++){
            if(d[j]){
                for(ll k=0;k<n;k++){
                    if(g[j][k]==-1)continue;
                    if(g[j][k]!=d[k]) judge=false;
                }
            }
        }
        if(judge){
            ans=max(ans,cnt);
        }
    }
    cout << ans << endl;
}
