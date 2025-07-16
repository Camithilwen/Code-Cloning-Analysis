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
const int M=3005;
int n,t;
int dp[M][M];
int a[M],b[M];
vector<pi>vec;
int solve(int pos,int tym)
{
    if(pos>n)return 0;
    if(tym>=t)return 0;
    int &ret=dp[pos][tym];
    if(ret!=(-1))return ret;
    ret=solve(pos+1,tym);
    ret=max(ret,solve(pos+1,tym+a[pos])+b[pos]);
    return ret;
}
 main()

{
    fast
    memset(dp,-1,sizeof dp);
    cin>>n>>t;
    f(i,1,n)
    {
        cin>>a[i]>>b[i];
        vec.pb(mp(a[i],-b[i]));
    }
    sort(vec.begin(),vec.end());
    f(i,0,n-1)
    {
        a[i+1]=vec[i].fi;
        b[i+1]=-vec[i].si;
    }
    int ses=solve(1,0);
    cout<<ses<<endl;
    return 0;

}



































