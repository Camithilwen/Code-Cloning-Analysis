#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
const ll mod = 1e9+7;
int n, d;
vector<int> a;
ll mult(ll a,ll b){return ((a%mod)*(b%mod))%mod;}
ll add(ll a,ll b){return ((a%mod)+(b%mod))%mod;}
ll sub(ll a,ll b){return ((a%mod)-(b%mod)+mod)%mod;}
ll dp[10009][2][101];
ll fun(int ci, int used, int sum){
    if(ci==n){
        if(sum==0)
            return 1;
        return 0;
    }
    if(dp[ci][used][sum]!=-1){
        return dp[ci][used][sum];
    }
    ll ans = 0;
    for(int i=0;i<=9;++i){
        if(used==1){
            ans = add(ans, fun(ci+1, 1, (sum+i)%d));
        }
        else{
            if(i < a[ci]){
                ans = add(ans, fun(ci+1, 1, (sum+i)%d));
            }
            if(i==a[ci]){
                ans = add(ans, fun(ci + 1, 0, (sum + i) % d));
            }
        }
    }
    return dp[ci][used][sum] = ans;
}
int solve(){
    string s;
    cin>>s;
    n = s.size();
    a.resize(n);
    
    memset(dp, -1, sizeof(dp));

    for(int i=0;i<n;++i){
        a[i] = s[i]-'0';
    }

    cin>>d;
    ll ans = sub(fun(0, 0, 0), 1);
    cout<<ans; 
    // current index, used, total sum till cur_indx-1
    return 0;
}
int main(){
    fast;
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }

    return 0;
}