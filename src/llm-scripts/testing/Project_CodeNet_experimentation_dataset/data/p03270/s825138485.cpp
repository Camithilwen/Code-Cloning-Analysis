#include <bits/stdc++.h>
using namespace std;

#define VIC ios::sync_with_stdio(0);cin.tie(0);ios_base::sync_with_stdio(0);
#define wtf(s) freopen((s), "w", stdout)
#define rff(s) freopen((s), "r", stdin)
#define pi (2 * acos(0))
typedef long double ld;
typedef long long ll;
#define endl '\n'
#define matrix vector<vector<ll>>
ll fact[4009] , inv[4009]  , mod=998244353 , n,  k;
ll fp(ll x , ll exp)
{
    if(exp == 0)
        return 1;
    if(exp % 2 == 0)
        return fp((x * x) % mod, exp / 2) % mod;
    return ((fp((x * x) % mod, exp / 2) % mod) * x) % mod;
}
void calcFacAndInv(ll n)
{
    fact[0] = inv[0] = 1;
    for (ll i = 1; i <= n; i++)
    {
        fact[i] = (i * fact[i - 1]) % mod;
        inv[i] = fp(fact[i], mod - 2);
    }
}
ll ncr(ll n, ll r)
{
    return ((fact[n] * inv[r]) % mod * inv[n - r]) % mod;
}

ll npr(ll n, ll r)
{
    return (fact[n] * inv[n - r]) % mod;
}
int main()
{
    VIC
    cin>>k>>n;
    calcFacAndInv(4000);
    for(ll i=2;i<=2*k;i++)
    {
        ll p=0, ans = ncr(n+k-1,k-1);
        for(int j=1;j<=i/2;j++)
            if(j <= k && i-j<=k)
                p++;
            for(int j=1;j<=p;j++)
            {
              //  cout<<j<<" "<<p<<endl;
              if(2*j>n)break;
                ll cur=ncr(p,j) * ncr(n-2*j+k-1,k-1);
                if(j%2==0)
                    ans+=cur;
                else
                    ans-=cur;
                ans %= mod;
                ans=(ans+ mod)%mod;
            }
        cout<<ans<<"\n";
    }
    return 0;
}
