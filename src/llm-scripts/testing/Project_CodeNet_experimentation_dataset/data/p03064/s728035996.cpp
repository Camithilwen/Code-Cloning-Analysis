#include <bits/stdc++.h>
typedef long long ll;
#define pb push_back

using namespace std;


ll n;
ll a[350];
ll dp[350][302*302 + 2];
ll dp1[350][302*302];
const ll mod = 998244353;
ll ME(ll x,ll nn,ll M)
{
    ll result=1;
    while(nn>0)
    {
        if(nn % 2 ==1)
            result=(result * x)%M;
        x=(x*x)%M;
        nn=nn/2;
    }
    return result;
}
ll solve(ll id, ll sum)
{
        if(sum < 0) return 0LL;
        if(id == n+1){
                if(sum == 0) return 1LL;
                return 0;
        }
        ll &ret = dp[id][sum];
        if(ret != -1) return ret;
        ret = solve(id+1, sum - a[id]);
        ret = (ret + 2*solve(id+1 , sum))%mod;
        return ret;
}
ll solve2(ll id ,ll sum)
{
        if(sum<0) return 0;
        if(id == n+1) {
                if(sum == 0) return 1LL;
                return 0;
        }
        ll &ret = dp1[id][sum];
        if(ret != -1) return ret;
        ret = solve2(id+1, sum);
        ret = (ret + solve2(id+1, sum-a[id]))%mod;
        return ret;
}
int main()
{
        cin >> n;
        ll sum=0;
        for(ll i=1;i<=n;i++) {
                cin >> a[i];
                sum += a[i];
        }
        ll ans = ME(3,n,mod);
        ans = (ans * ME(3LL , mod-2,mod))%mod;
        memset(dp,-1,sizeof dp);
        for(ll i=(sum+1)/2; i <= sum; i++) {
                ans = (ans - solve(1 , i) + mod)%mod;
        }
        //memset(dp,-1,sizeof dp);
        if(sum%2 == 0){
        memset(dp1,-1,sizeof dp1);
        ans = (ans + solve2(1 , (sum)/2))%mod;
        }
        ans = (ans*3LL)%mod;
        cout << ans << endl;
        return 0;
}
