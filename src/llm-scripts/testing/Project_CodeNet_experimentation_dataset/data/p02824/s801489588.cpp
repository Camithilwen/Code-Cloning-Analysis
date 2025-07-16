///Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>

#define                           int                         long long
#define                           fi                          first
#define                           si                          second
#define                           mp                          make_pair
#define                           pb                          push_back
#define                           pi                          pair<int,int>
#define                           clr(x)                      memset(x,0,sizeof(x));
#define                           f(i,l,r)                    for(int i=l;i<=r;i++)
#define                           rf(i,r,l)                   for(int i=r;i>=l;i--)
#define                           done(i)                     cout<<"done = "<<i<<endl;
#define                           fast                        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);




using namespace std;

const int inf=1e18;
const int mod=1e9+7;
const int M=100009;

inline int bigmod(int B,int P){int R=1;while(P>0){if(P&1){R=(R*B)%mod;}P>>=1;B=(B*B)%mod;}return R;}
inline int ad(int x,int y){int ret=(x%mod+y%mod)%mod;if(ret<0){ret+=mod,ret=ret%mod;}return ret;}
inline int sub(int x,int y){int ret=((x%mod)-(y%mod)+mod)%mod;if(ret<0){ret+=mod,ret=ret%mod;}return ret;}
inline int gun(int x,int y){int ret=((x%mod)*(y%mod))%mod;if(ret<0){ret+=mod,ret=ret%mod;}return ret;}

int n,m,v,p;
vector<pi>vec;
int a[M+3];
bool vis[M+3];
bool chk(int idx)
{
   int big=p-1;
   int use=v-1;
   int mn=min(big,use);
   big-=mn;
   use-=mn;
   vector<pi>yo;
   if(vis[idx])return true;
   int mx=vec[idx].fi+m;
   int sum=use*m;
   //cout<<sum<<" ### "<<endl;
   for(int i=p-1;i<n;i++)
   {
       if(i==idx)continue;
       int val=vec[i].fi;
       int gap=mx-val;
       if(gap<0)
       {
           //cout<<i<<" "<<mx<<" "<<val<<endl;
       }
       if(gap<0)return false;
       int can=min(gap,m);
       sum-=can;
   }
   if(sum<=0)return true;
   else return false;
}
 main()

{
    fast
    cin>>n>>m>>v>>p;
    f(i,1,n)
    {
        int x;
        cin>>x;
        a[i]=x;
        vec.pb(mp(x,i));
    }
    sort(vec.rbegin(),vec.rend());
    int last;
    for(int i=0;i<p;i++)
    {
        vis[i]=true;
        last=vec[i].fi;
    }
    for(int i=p;i<n;i++)
    {
        if(vec[i].fi==last)
        {
            vis[i]=true;
        }
        else break;
    }
   // cout<<chk(3)<<"#"<<endl;
    int lo=0,hi=n-1;
    while(hi-lo>=2)
    {
        int mid=(lo+hi)>>1;
        if(chk(mid))lo=mid;
        else hi=mid-1;
    }
    int ses=-1;
    for(int i=lo;i<=hi;i++)
    {
        if(chk(i))ses=i;
    }
    if(ses==-1)
    {
        cout<<"0"<<endl;
        return 0;
    }
    ses=ses+1;
    cout<<ses<<endl;
    return 0;

}



































