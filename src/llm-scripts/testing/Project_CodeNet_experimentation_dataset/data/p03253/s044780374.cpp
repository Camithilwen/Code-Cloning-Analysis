///Bismillahir Rahmanir Rahim
#include "bits/stdc++.h"

#define                           ll                          long long
#define                           int                         ll
#define                           fi                          first
#define                           si                          second
#define                           mp                          make_pair
#define                           pb                          push_back
#define                           pi                          pair<ll,ll>
#define                           clr(x)                      memset(x,0,sizeof(x));
#define                           f(i,l,r)                    for(int i=l;i<=r;i++)
#define                           rf(i,r,l)                   for(int i=r;i>=l;i--)
#define                           done(i)                     cout<<"done = "<<i<<endl;
#define                           show(x,y)                   cout<<x<<" : ";for(auto z:y)cout<<z<<" ";cout<<endl;
#define                           fast                        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

const ll inf=1e18;
const int mod=1e9+7;
const int M=1000005;
inline ll bigmod(ll B,ll P){ll R=1;while(P>0){if(P&1){R=(R*B)%mod;}P>>=1;B=(B*B)%mod;}return R;}
inline int gun(int x,int y)
{
    int ret=(x*y)%mod;
    if(ret<0){ret+=mod;ret=ret%mod;}
    return ret;
}
bitset<M>sv;
vector<int>prime;
int fact[M];
int infact[M];
void sieve()
{
    prime.pb(2);
    for(int i=4;i<M;i=i+2)sv[i]=1;
    for(int i=3;i*i<M;i=i+2)
    {
        if(sv[i]==0){

        for(int j=i*i;j<M;j=j+2*i)
        {
           sv[j]=1;
        }

        }
    }
    for(int i=3;i<M;i=i+2)
    {
        if(sv[i]==0)prime.pb(i);
    }
}
void init()
{
    fact[0]=1;
    infact[0]=1;
    f(i,1,M-1)
    {
        fact[i]=(fact[i-1]*i)%mod;
    }
    infact[M-1]=bigmod(fact[M-1],mod-2);
    rf(i,M-2,1)
    {
        infact[i]=(infact[i+1]*(i+1))%mod;
    }
}
vector<int>p,c;
void prime_factorization(int x)
{
    p.clear();c.clear();
    for(int i=0;prime[i]*prime[i]<=x;i++)
    {
        int cnt=0;
        if(x%prime[i]==0)
        {
            while(x%prime[i]==0)
            {
                x=x/prime[i];
                cnt++;
            }
            p.pb(prime[i]);
            c.pb(cnt);
        }
    }
    if(x>1)
    {
        p.pb(x);
        c.pb(1);
    }
}
int star_bar(int bol,int box)
{
   int ret=fact[bol+box-1];
   ret=gun(ret,infact[box-1]);
   ret=gun(ret,infact[bol]);
   return ret;
}
 main()

{
    fast
    init();
    sieve();
    int n,m;
    cin>>n>>m;
    prime_factorization(m);
    int sz=c.size();
    int ses=1;
    for(int i=0;i<sz;i++)
    {
        ses=gun(ses,star_bar(c[i],n));
    }
    cout<<ses<<endl;
    return 0;

}



































