#include<bits/stdc++.h>
using namespace std;
#define num 1000000007
//#define num 998244353
#define REP(i,a,n) for(ll i=a;i<n;i++)
#define inarr(i,a,n,A) for(ll i=a;i<n;i++) { cin>>A[i]; }
#define vll vector<long long>
#define pii pair <int,int>
#define pll pair<long long, long long>
#define vpii vector< pair <int,int>>
#define vpll vector< pair<long long, long long>>
//#define max(a,b) ((a>b)?a:b)
//#define min(a,b) ((a>b)?b:a)
#define max3(a,b,c) ((a>b)?(a>c)?a:c:(b>c)?b:c)
#define min3(a,b,c) ((a<b)?(a<c)?a:c:(b<c)?b:c)
#define avg(a,b) ((a)+(b))/2
#define pb push_back
#define pob pop_back
#define sf int flag=0     //Remember semicolon
// #define assmin(a,b) if(b<=a) { a=b; }
// #define assmax(a,b) if(b>=a) { a=b; }
#define f first
#define s second
#define fix(f,n) std::fixed<<std::setprecision(n)<<f
#define all(x) x.begin(), x.end()
#define M_PI 3.14159265358979323846
#define epsilon (double)(0.00000000001)
#define side 1e9
#define watch(x) cout << (#x) << " is " << (x) << endl
typedef long long ll;
ll mod(ll a, ll b)
{
	if(a%b<0)
	{
		return a%b + b;
	}
	return a%b;
}
 
 
ll mod_exp(ll a, ll b, ll c)
{
	ll res=1;
	a=a%c;
	while(b>0)
	{
		if(b%2==1)
		{
			res=(res*a)%c;
		}
		b/=2;
		a=(a*a)%c;
	}
	return res;
}
ll mymod(ll a,ll b)
{
    return ((a%b)+b)%b;
}
bool prime[200001];
void SieveOfEratosthenes() 
{ 
    memset(prime, true, sizeof(prime)); 
    prime[1]=false;
    for (int p=2; p*p<=200000; p++) 
    { 
        if (prime[p] == true) 
        { 
            for (int i=p*p; i<=200000; i += p) 
                prime[i] = false; 
        } 
    } 
    return;
}
ll powe[200005];
void power()
{
    powe[0]=1;
    REP(i,1,200005)
    {
        powe[i]=mymod(2*powe[i-1],num);
    }
}
ll gcdExtended(ll,ll,ll *,ll *);
ll modInverse(ll a, ll m) 
{ 
    ll x, y; 
    ll g = gcdExtended(a, m, &x, &y); 
        ll res = (x%m + m) % m;
        return res;
} 
ll gcdExtended(ll a, ll b, ll *x, ll *y) 
{ 
    if (a == 0) 
    { 
        *x = 0, *y = 1; 
        return b; 
    } 
    ll x1, y1; 
    ll gcd = gcdExtended(b%a, a, &x1, &y1); 
    *x = y1 - (b/a) * x1; 
    *y = x1; 
    return gcd; 
}
struct node
{
	vll adj;
    ll indegree;
};

ll find(ll n, ll wt, ll nm)
{
    ll st = 1;
    ll en = nm;
    ll mid = (st) + (en - st)/2;
    while(st<=en)
    {
        if(wt+3*(nm+mid)>=n && wt+2*(nm+mid)<=n)
        {
            return mid;
        }
        else if(wt+3*(nm+mid)<n)
        {
            st = mid+1;
        }
        else
        {
            en = mid-1;
        }
        mid = (st) + (en - st)/2;
    }
    if(wt+3*(nm+mid)>=n && wt+2*(nm+mid)<=n)
    {
            return mid;
     }
    return 0;
}
bool my(pair<ll, char> p1, pair<ll, char> p2)
{
    return p1.first > p2.first;
}
struct segment
{
    ll l,r,v;
};
bool my(segment a, segment b)
{
    return a.l<b.l;
}
ll convert(string s)
{
    ll n = 0;
    REP(i,0,s.size())
    {
        if(!(n>>(s[i]-97)&1))
        {
            n+=(1<<(s[i]-97));
        }
    }
    return n;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    ll n = s.size();
    ll ans = (n*(n+1))/2;
    ll count[26]={0};
    for(ll i=n-1; i>=0; i--)
    {
        count[s[i]-97]++;
        ans-=count[s[i]-97];
    }
    cout<<ans+1<<"\n";
    return 0;
}