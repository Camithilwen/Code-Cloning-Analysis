#include<bits/stdc++.h>
#define ll                  long long
#define dl                 long double
#define pb                push_back
#define F                  first
#define S                  second
//#define endl              "\n"
#define rep(i,a,b)       for(i=a;i<b;i++)
#define all(v)             v.begin(),v.end()
#define allr(v)            v.rbegin(),v.rend()
#define mod              1000000007LL
#define CIN(V,s,n)      for(int i=s;i<n;i++){cin >> V[i];}
#define COUT(V,s,n)   {for(int i=s;i<n;i++){cout <<  V[i] << " "  ;} cout << endl;}
#define fast               ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define CLEAR(V);      for(ll i=0;i<V.size();i++) V[i] = 0;
#define N                  101LL
#define tmod             998244353LL
using namespace std;

bool sBs(const pair<int,int> &a,const pair<int,int> &b)
{   return (a.second < b.second);   }

ll Powb(ll b,ll n,ll m);
ll BS(vector<pair< ll ,ll > > &PS,ll s,ll e,ll ser);
ll MI(ll a, ll m);
ll P[N+1];
void Sieve(int n=N);

int main()
{
fast;
ll q=1,t;
//cin >> q; t = q;
while(q--)
{
    ll i,j,n,m,k,l=0,r=0,a=0,b=0,c=0,d=0,e,g=1,p,u,v,w,x,y,flag=0;
    //n=m=k=i=j=l=r=a=b=c=d=u=v=w=p=x=y=0;
    string s;
    cin >> s;
    if(s=="SUN") cout << 7;
    else if(s=="MON") cout << 6;
    else if(s=="TUE") cout << 5;
    else if(s=="WED") cout << 4;
    else if(s=="THU") cout << 3;
    else if(s=="FRI") cout << 2;
    else if(s=="SAT") cout << 1;
    }
    return 0;
}

//*****************************************************************************************************************************************

ll Powb(ll b,ll n,ll m)
{
    if(n==0) return 1LL;
    if(n==1) return b;
    ll temp = Powb(b,n/2,m);
    if(n%2==0){return (temp*temp)%m;}
    else{return (b*((temp*temp)%m))%m;}
}

ll BS(vector<pair<ll,ll> > &PS,ll s,ll e,ll ser)
{
    if(s>e)
        return s;
    ll mid = (s+e)/2;
    if(PS[mid].F==ser)
    {
        return mid;
    }
    else if(PS[mid].F > ser)
    {
        return BS(PS,s,mid-1,ser);
    }
    else
        return BS(PS,mid+1,e,ser);
}
ll MI(ll a, ll m)
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

void Sieve(int n)
{
    //memset(P,true,sizeof(P));
    //P[0] = false;
    //P[1]= false;
    for(int i=1;i<=n;i++) P[i] = i;
    for(ll i=2;i*i<=n;i++)
    {
        if(P[i]==i)
        {
            for(ll j=i*i;j<=n;j+=i)
            {
                if(P[j]==j)
                    P[j]=i;
            }
        }
    }

}

