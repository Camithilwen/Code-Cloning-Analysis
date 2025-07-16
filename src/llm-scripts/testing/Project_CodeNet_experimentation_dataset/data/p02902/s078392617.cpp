  #include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define debug(x) cout << #x << " = " << x << endl;
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define FOR(it, b, e) for (typeof(b) it = (b); it != (e); ++it)
#define MSET(c, v) memset(c, v, sizeof(c))

const int INF = 0x3F3F3F3F; 
const int NEGINF = 0xC0C0C0C0;
const int NULO = -1;
const double EPS = 1e-10;
const ll mod = 1e9 + 7;

inline int cmp(double x, double y = 0) 
{  
  if(fabs(x - y) < EPS)
    return 0;
  return x > y ? 1 : -1;
}

ll exp(ll a, ll b)
{
  ll ans = 1;
  while(b)
  {
    if(b & 1)
      ans = (ans * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return ans;
}

const int maxn = 1005;

vector<int>graph[maxn];

vector<int>ans;
int n,m;
int vis[maxn];
void dfs(int u, int target)
{
  vis[u] = 1;
  for(const auto &v: graph[u])
  {
    if(vis[v] == 1)
    {
      if(v == target)
      {
        vector<int>cycle;
        for(int i = 1; i <= n ; i++)
          if(vis[i] == 1)
            cycle.push_back(i);
        if(ans.size() == 0 || cycle.size() < ans.size())
          ans = cycle;
      }
    }
    else if(vis[v] == 0)
    {
      dfs(v, target);
    }
  }
  vis[u] = 2;
}


int main()
{
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for(int i = 0 ; i < m ; i++)
  {
    int u,v;
    cin >> u >> v;
    graph[u].push_back(v);
  }
  for(int i = 1 ; i <= n ; i++)
  {
    MSET(vis, 0);
    dfs(i, i);
  }

  if(ans.size() == 0)
    cout << "-1\n";
  else
  {
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++)
    {
      cout << ans[i] << endl; 
    }
  }
  return 0;
}