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
const int mod=998244353;
const int M=100005;
inline ll bigmod(ll B,ll P){ll R=1;while(P>0){if(P&1){R=(R*B)%mod;}P>>=1;B=(B*B)%mod;}return R;}
inline ll ad(ll x,ll y){ll ret=(x%mod+y%mod)%mod;if(ret<0){ret+=mod,ret=ret%mod;}return ret;}
inline ll sub(ll x,ll y){ll ret=((x%mod)-(y%mod)+mod)%mod;if(ret<0){ret+=mod,ret=ret%mod;}return ret;}
inline ll gun(ll x,ll y){ll ret=((x%mod)*(y%mod))%mod;if(ret<0){ret+=mod,ret=ret%mod;}return ret;}
int k,zero=0,one=0,cur=0;
string s;
vector< vector< vector<int> > >dp;
int cnt[306];
int solve(int pos,int has,int op)
{
    if(op>k)return 0;
    if(pos==cur)return 1;
    int &ret=dp[pos][has][op];
    if(ret!=(-1))return ret;
    ret=0;
    for(int i=0;i<=cnt[pos];i++)
    {
        ret=ad(ret,solve(pos+1,has+i,op+i));
    }
    for(int i=1;i<=has;i++)
    {
         ret=ad(ret,solve(pos+1,has-i,op));
    }
    return ret;
}
 main()

{
    fast
    cin>>s>>k;
    for(auto ch:s)
    {
        if(ch=='0')zero++;
        else one++;
    }
    dp.resize(zero+3);
    for(auto &x:dp)
    {
        x.resize(one+2);
        for(auto &y:x)
        {
            y.resize(one+2,-1);
        }
    }
    while(s.size())
    {
        if(s.back()=='0')cur++;
        else cnt[cur]++;
        s.pop_back();
    }
    cout<<solve(0,0,0)<<endl;
    return 0;

}


































