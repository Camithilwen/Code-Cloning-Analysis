/*
  Creator :  bizarre
*/
#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define bizarre  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define file freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define ll long long
#define ld long double
#define pi acos(-1)
#define point complex<double>
const int N = 3e5 + 9, inf = 1e18, mod = 1e9 + 7;
vector<int> prime_Numbers;
bool primes[1000005];
double dot(point a, point b)
{
    return (conj(a) * b).real();
}
double cross(point a, point b)
{
    return (conj(a) * b).imag();
}
/*
void prime(int n)
{
    primes[1]=primes[0]=0;
    for(int i=2; i<=n; i++)
        primes[i]=true;
    for(int i=2; i<=n; i++)
    {
        if(primes[i]==true)
        {
            prime_Numbers.push_back(i);
            for(int j=i+i; j<=n; j+=i)
                primes[j]=false;
        }
    }
}
void move1step(long long& a, long long& b, long long q)
{
    long long c= a-q*b;
    a=b;
    b=c;
}
long long egcd(long long r0,long long r1,long long& x0,long long& y0)
{
    long long x1=0,y1=1;
    x0=1;
    y0=0;
    while(r1)
    {
        long long q=r0/r1;
        move1step(r0,r1,q);
        move1step(x0,x1,q);
        move1step(y0,y1,q);
    }
    return r0;
}
bool  solve (long long a, long long b, long long c,long long&x, long long& y)
{
    long long g=egcd(a,b,x,y);
    int m=c/g;
    x*=m;
    y*=m;
    return c%g==0;
}
int gcd(int a, int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
void PrimeFactorization(int n)
{
    for(int i=2; i*i<=n; i++)
    {
        int c=0;
        if(n%i==0)
        {
            while(n%i==0)
            {
                n/=i;
            }

        }
    }

}
long long ncrtane(long long n, long long r)
{
    long long ans=1,cntr=1;
    for(int i=n; i>n-r; i--)
    {
        ans*=i;
        ans/=cntr;
        cntr++;
    }
    return ans;
}
int ncr(long long n, long long r)
{
    return (((fact[n] * inv[n - r]) % mod) * inv[r]) % mod;
}

int npr(long long n, long long r)
{
    return (fact[n] * inv[n - r]) % mod;
}
long long fact[N], inv[N];
long long fp(long long base, long long exp)
{
    if (exp == 0)
        return 1;
    long long ans = fp(base, exp / 2);
    ans = (ans * ans) % mod;
    if (exp % 2 != 0)
        ans = (ans * (base % mod)) % mod;
    return ans;
}

void pre(long long n)
{
    fact[0] = 1;
    inv[0] = 1;
    for (long long i = 1; i <= n; i++)
    {
        fact[i] = (i * fact[i - 1]) % mod;
        inv[i] = fp(fact[i], mod - 2);
    }
}
*/
/*
ll lfts,lftw;
ll p,f,cnts,cntw,s,w;
ll ss(ll cnts, ll cntw, ll mxmp)
{
     for(int i = 0;i<=cnts;i++)
        {
            ll var = i*s,s = 0,e = cntw,mid,ans;
            if(var>p)break;
            while(s<=e)
            {
                mid = (s+e)/2;
                if((mid*w)+var<=p)ans = mid,s = mid+1;
                else e = mid-1;
            }
            if(mxmp<i+mid)mxmp = i+mid,lfts-=i,lftw-=mid;
        }
        return mxmp;
}
ll ww(ll cnts, ll cntw, ll mxmp)
{
    for(int i = 0;i<=cnts;i++)
        {
            ll var = i*s,s = 0,e = cntw,mid,ans;
            if(var>f)break;
            while(s<=e)
            {
                mid = (s+e)/2;
                if((mid*w)+var<=f)ans = mid,s = mid+1;
                else e = mid-1;
            }

            if(mxmp<i+mid)mxmp = i+mid;
        }
        return mxmp;
}
*/
int main()
{
    bizarre
    int t = 1;
    //cin >> t;
    while(t--)
    {
     int n;
     cin >> n;
     int mnm = 1e9;
     for(int i = 0;i<n;i++)
     {
        ll x;
        cin >> x;
        int cntr = 0;
        while(x%2==0)
        {
            x/=2;
            cntr++;
        }
        mnm = min(mnm,cntr);
     }
     cout << mnm;
    }
    return 0;
}
