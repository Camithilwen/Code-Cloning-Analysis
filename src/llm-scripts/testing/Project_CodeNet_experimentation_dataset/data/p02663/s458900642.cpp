#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define ld long double
#define MOD 1000000007
#define mod9 1000000009
#define fast ios_base :: sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define mp make_pair
#define pb push_back
#define ct ll t;cin>>t;while(t--)
#define bi begin()
#define ei end()
#define fi first 
#define se second  
#define foe(i,a,b) for(ll i=a;i<b;i++)
#define sz(s) s.size() 
#define mem(a,s) memset(a,s,sizeof(a)) 
#define MAX             8000000000000000064LL
#define MIN            -8000000000000000064LL   
bool isPrime(ll n) 
{ 
    // Corner case 
    if (n <= 1) 
        return false; 
    
    // Check from 2 to n-1 
    for (ll i = 2; i*i <= n; i++) 
        if (n % i == 0) 
            return false; 
    
    return true; 
}
long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res) * (a);
        a = (a) * (a);
        b >>= 1;
    }
    return res;
}

bool compare(const pair<ll,ll>&a,const pair<ll,ll>&b)
{
    return (a.se>b.se);
}
ll lcm(ll a,ll b)
{
    return(a*b)/__gcd(a,b);
}
// vector<ll>s;
// // set<ll>s1;
// bool prime[1000009]={false};
//     // set<ll>s1;
//     void Sieve() 
//     {  
//         ll n=1000009;
//         prime[0]=prime[1]=true;
//         // s[0]=0;
//         // s[1]=1;
//         // s.pb(1);
//         // t.insert(1);
//         for (int p=2; p*p<=n; p++) 
//         { 
        
//            if(prime[p]==false)
//            {
//             //    s.pb(p);
//                for(ll j=p*p;j<=n;j+=p)
//                {
//                    prime[j]=true;
//                }    
//            }
//         } 
//         for(ll i=2;i<n;i++)
//         {
//             if(!prime[i])
//             {
//                 // s.pb(i);
//                 // s1.insert(i);
//             }
//         }
//     } 
//     ll eea(ll a, ll b, ll & x, ll & y) {
//     if (a == 0) {
//         x = 0;
//         y = 1;
//         return b;
//     }
//     ll x1, y1;
//     ll d=eea(b % a, a, x1, y1);
//     x = y1 - (b / a) * x1;
//     y = x1;
//     return d;
// }
// bool find_any_solution(ll a, ll b, ll c, ll &x0, ll &y0, ll &g) {
//     g = eea(abs(a), abs(b), x0, y0);
//     if (c % g) {
//         return false;
//     }
 
//     x0 *= c / g;
//     y0 *= c / g;
//     if (a < 0) x0 = -x0;
//     if (b < 0) y0 = -y0;
//     return true;
// }
// ll modinverse(ll a,ll m)
// {
//     ll x, y;
//     eea(a, m, x, y);
//     if (__gcd(a,m) != 1) {
//     return -1;
//     }
// else {
//     x = (x % m + m) % m;
//     cout << x << endl;
//     return x;
// }
// }
int add(int a, int b){return (a%MOD + b%MOD + ((MAX)/MOD)*MOD)%MOD;}
int sub(int a, int b){return (a%MOD - b%MOD + ((MAX)/MOD)*MOD)%MOD;}
int mul(int a, int b){return ((a%MOD)*(b%MOD) + ((MAX)/MOD)*MOD)%MOD;}
int fact[1000007]={0};
ll expo(ll x, ll y) {ll res=1;x=x%MOD;while(y>0){if(y&1)res=(1ll*res*x)%MOD;
y=y>>1;x=(1ll*x*x)%MOD;} return res;}
void facto() {fact[0]=1;fact[1]=1;for(ll i=2;i<1000007;i++)fact[i]=(fact[i-1]*i)%MOD;}
int ncr(int n,int r) {int res=1; res=fact[n]; res=(res*(expo(fact[r],MOD-2)))%MOD; res=(res*(expo(fact[n-r],MOD-2)))%MOD; return res;}
ll npr(ll n,ll r) {facto(); ll res=1; res=fact[n]; res=(res*(expo(fact[n-r],MOD-2)))%MOD; return res; }
int const N=1e7+9;
int const inf = 1e9+5;
void solve()
{
    ll h1,m1,h2,m2,k;
    cin>>h1>>m1>>h2>>m2>>k;
    ll t=0;
    if(m1==0)
    {
        t=h2-h1;
    }
    else
    {
        t=h2-h1-1;
    }
    ll ans=t*60-m1+m2;
    if(m1!=0)
    {
        ans+=60;
    }
    cout<<ans-k<<"\n";
    
}   
int main()
{
    fast
    // Sieve();
   
//    ct
    { 
       solve();     
    }
}
            