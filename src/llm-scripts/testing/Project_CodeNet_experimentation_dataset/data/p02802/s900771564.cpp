#include<bits/stdc++.h>
#include<math.h>
using namespace std;

/*------------------------------------------------------------------*/

#define ll long long int
#define mp make_pair
#define pb push_back
#define MOD 1000000007

bool isvowel(char c)
{
    if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
        return true;
        return false;
}
ll isprime(ll n)
{
    ll ans=1;
    for(ll i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
            ans = i;
    }
    return ans;
}
ll power(ll a,ll b,ll m)
{
    if(b==0)
        return 1;
    if(b==1)
        return a%m;
    ll temp=power(a,b/2,m);
    if(b%2==0)
        return ((temp%m)*(temp%m))%m;
    else
        return ((((temp%m)*(temp%m))%m)*a%m)%m;
}

/*-----------------------------------------------------------------------------*/

ll c(ll n, ll k)
{
    ll C[n + 1][k + 1];
    ll i, j;

    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= min(i, k); j++)
        {

            if (j == 0 || j == i)
                C[i][j] = 1;

            else
                C[i][j] = (C[i - 1][j - 1]%MOD +
                          C[i - 1][j])%MOD;
        }
    }
    return C[n][k]%MOD;
}
ll modInverse(ll a, ll m)
{
    ll m0 = m;
    ll y = 0, x = 1;

    if (m == 1)
      return 0;

    while (a > 1)
    {

        ll q = a / m;
        ll t = m;
        m = a % m, a = t;
        t = y;


        y = x - q * y;
        x = t;
    }
    if (x < 0)
       x += m0;

    return x;
}
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    //freopen("1.txt","rt",stdin);
    //freopen("output.txt","wwt",stdout);

    ll t;
    t=1;
    //cin>>t;
    //ll t1=0;
    while(t--)
    {
       ll n,m;
       cin>>n>>m;
       ll p[m];
       string s[m];
       map<ll,ll>m1;
       ll ans1=0,ans2=0;
       for(ll i=0;i<m;i++)
       {
           cin>>p[i]>>s[i];
           if(s[i]=="AC")
           {
              if(m1[p[i]]!=-1)
              {
                  ans2+=m1[p[i]];
                  m1[p[i]]=-1;
                  ans1++;
              }
           }
           else
           {
               if(m1[p[i]]!=-1)
                 m1[p[i]]++;
           }
       }
       cout<<ans1<<" "<<ans2<<endl;
    }
}
