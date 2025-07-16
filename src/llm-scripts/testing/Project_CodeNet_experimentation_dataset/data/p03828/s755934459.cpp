#include<bits/stdc++.h>
#define PI acos(-1.0)
#define eps 1e-67
#define pf printf
#define sf scanf
#define sd(n) scanf("%d",&n)
#define sd2(n1,n2) scanf("%d %d",&n1,&n2)
#define slf(n) scanf("%lf",&n)
#define slf2(n1,n2) scanf("%lf %lf",&n1,&n2)
#define sLf(n1) scanf("%Lf",&n1)
#define sLf2(n1,n2) scanf("%Lf %Lf",&n1,&n2)
#define sl(n) scanf("%lld",&n)
#define sl2(n1,n2) scanf("%lld %lld",&n1,&n2)
#define rep(i,a,b) for(long long int i=a;i<b;i++)
#define repb(i,a,b) for(long long int i=a;i>=b;i--)
#define repa(i,a,b,c) for(long long int i=a;i<b;i=i+c)
#define reps(i,a,b,c) for(long long int i=a;i>b;i=i-c)
#define asort(a) sort(a.begin(),a.end())
#define asortb(a,comp) sort(a.begin(),a.end(),comp)
#define arev(a) reverse(a.begin(),a.end())
#define all(v) (v).begin(),(v).end()
#define allc(v,comp) (v).begin(),(v).end(),comp
#define allrc(v,a,b,comp) (v).begin()+a,(v).end()-b,comp
#define F first
#define S second
#define pb push_back
#define eb emplace_back
#define pbb pop_back
#define mp make_pair
#define mt make_tuple
#define bs(v,x) binary_search(v.begin(),v.end(),x)
#define lb(v,x) lower_bound(v.begin(),v.end(),x)
#define ub(v,x) upper_bound(v.begin(),v.end(),x)
#define tl(c) towlower(c)
#define root(x) sqrt(x)
#define power(a,n) (int)floor(pow(a,n))
#define tu(c) towupper(c)
#define sq(a) ((a)*(a))
#define cube(a) ((a)*(a)*(a))
#define mx 1000
#define MX 100000
#define mod 1000000007
using namespace std;
typedef string str;
typedef long long int ll;
typedef double lf;
typedef long double llf;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;
typedef char ch;
typedef map<ll,ll> mp;
void Solve()
{
    ll n;
    cin>>n;
    vll v;
    bool prime[100000];
    memset(prime, true, sizeof(prime));
    prime[0]=prime[1]=false;
    for (ll p=2; p<=n; p++)
    {

        if (prime[p] == true)
        {

            for (ll i=p*p; i<=n; i += p)
                prime[i] = false;
        }
    }
    ll i,j,sum=0,ans=1;
    rep(i,0,n+1)
    {
        if(prime[i])
        {
            v.pb(i);

        }
    }

    rep(i,0,v.size())
    {
        rep(j,1,10){
            sum+=(n/power(v[i],j));
        }
        ans*=(sum+1);
        ans%=mod;
        sum=0;
    }
    cout<<ans<<endl;
}

int main()
{
    Solve();
    return 0;
}
