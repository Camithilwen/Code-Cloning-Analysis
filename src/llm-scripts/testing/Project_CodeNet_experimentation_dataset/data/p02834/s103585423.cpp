#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define mp make_pair
#define pb(x) push_back(x)
#define vll vector<long long>
#define pll pair<long long, long long>
#define mll map<long long, long long>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define gcd __gcd
#define clr(x) memset(x, 0, sizeof(x))
#define mod 1000000007LL
#define mod2 998244353LL
#define INF 1e18
 

typedef long long ll;
typedef long double ld;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> o_tree;

const int N=1e5+5;
vll v[N];
ll vis[N];
vll path;
ll maxh[N];
ll f=0;

void dfs(ll x,ll s,ll dest)
{
  if(f)return;
  if(x==dest)
  {
    f=1;
    path.pb(x);
    return;
  }
  path.pb(x);
  for(auto it:v[x])
  {
    if(it==s)continue;
    dfs(it,x,dest);
  }
  if(f)return;
  path.pop_back();
}

void dfs2(ll x,ll s)
{
  ll f=0;
  // cout<<x+1<<"\n";
  for(auto it:v[x])
  {
    if(it==s)continue;
    f=1;
    dfs2(it,x);
    maxh[x]=max(maxh[x],maxh[it]+1ll);
  }
  if(!f)
  {
    maxh[x]=1;
  }
}



void solve()
{
  ll n;
  cin>>n;
  ll aa,bb;
  cin>>aa>>bb;
  aa--,bb--;
  ll i,j;
  for(i=1;i<n;i++)
  {
    ll x,y;
    cin>>x>>y;
    x--,y--;
    v[x].pb(y);
    v[y].pb(x);
  };
  dfs(aa,-1,bb);
  // for(auto it:path)
  // {
  //   cout<<it+1<<" ";
  // }
  // all i need is max height of subtree 
  dfs2(bb,-1);
  ll maxi=0;
  for(i=1;i<sz(path);i++)
  {
    // distance travelled to reach node path[i] = i; 
    ll dist_1 = i;
    ll dist_from_bb = sz(path)-1-i;
    if(dist_1>dist_from_bb)continue;
    ll maxheight = maxh[path[i]]-1;
    ll dif = dist_from_bb-dist_1;
    ll tans = dist_1;
    tans+=(dif+(maxheight-1));
    // ll tans = (maxheight)+dist_from_bb;
    // cout<<dif<<" "<<maxheight<<" "<<dist_from_bb<<" ";
    // cout<<path[i]+1<<"<-- "<<tans<<"\n";
    maxi=max(maxi,tans);
  }
  cout<<maxi<<"\n";
  
}


int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);


if (fopen("input.txt","r" ))
  {
     freopen("input.txt", "r", stdin);
     freopen("output.txt", "w", stdout);
  }
cout<<setprecision(20);


ll t=1;


// cin>>t;


while(t--)
{
solve();
} 


return 0;
}