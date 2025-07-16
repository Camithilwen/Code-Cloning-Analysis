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
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> o_tree;

bool comp(array<ll,2> a,array<ll,2> b)
{
  if(a[0]==b[0])
  {
    return a[1]>b[1];
  }
  return a[0]<b[0];
}

void solve()
{
  ll n,t;
  cin>>n>>t;
  ll i,j;
  ll mx=5000+t;
  ll dp[n][mx];
  clr(dp);

  array<ll,2>a[n];
  for(i=0;i<n;i++)
  {
    cin>>a[i][0]>>a[i][1];  
  }
  sort(a,a+n,comp);
  // reverse(a,a+n);
  
  for(i=0;i<n;i++)
  {
    for(j=0;j<mx;j++)
    {
      dp[i][j]=max(dp[i][j],(i>0)?dp[i-1][j]:0ll);
    }
    for(j=0;j<t;j++)
    {
      if(j+a[i][0]<mx)
      {
        dp[i][a[i][0]+j]=max(dp[i][a[i][0]+j],(i>0?dp[i-1][j]:0ll)+a[i][1]);
      }
    }
  }
  ll res = *max_element(dp[n-1],dp[n-1]+mx);
  cout<<res<<"\n";
}


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  if (fopen("input.txt", "r"))
  {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  }
  cout << setprecision(20);

  ll t = 1;

  // cin>>t;

  while (t--)
  {
    solve();
  }

  return 0;
}