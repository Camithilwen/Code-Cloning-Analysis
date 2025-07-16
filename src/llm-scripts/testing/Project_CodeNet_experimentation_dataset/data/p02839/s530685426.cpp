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

const int maxn = 85;
ll fat[maxn], inv[maxn];

ll C(int n, int k)
{
  if(n < k) 
    return 0;
  if(n < 0 || k < 0) 
    return 0;
  return (((fat[n] * inv[k]) % mod) * inv[n - k]) % mod;
}

void initFactorials()
{
  fat[0] = 1;
  inv[0] = 1;
  for(int i = 1; i < maxn; i++)
  {
    fat[i] = (i * fat[i-1]) % mod;
    inv[i] = exp(fat[i], mod - 2);
  }
}

int dp[maxn][maxn][2 * maxn * maxn];

ll a[maxn][maxn];

ll b[maxn][maxn];

int n,m;

int main()
{
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for(int i = 0 ; i < n; i++)
    for(int j = 0; j < m; j++)
      cin >> a[i][j];
  
  for(int i = 0 ; i < n; i++)
    for(int j = 0; j < m; j++)
      cin >> b[i][j];
  
  dp[0][0][abs(a[0][0] - b[0][0])] = true;
  for(int i = 0; i < n; i++)
  {
    for(int j = 0 ; j < m; j++)
    {
      for(int k = 0; k < (n + m) * maxn; k++)
      {
        if(i > 0)
        {
          dp[i][j][k] = dp[i - 1][j][k + abs(a[i][j] - b[i][j])] |
                        dp[i - 1][j][abs(k - abs(a[i][j] - b[i][j]))];
        }
        if(j > 0)
        {
          dp[i][j][k] = dp[i][j][k] |
                        dp[i][j - 1][k + abs(a[i][j] - b[i][j])] |
                        dp[i][j - 1][abs(k - abs(a[i][j] - b[i][j]))];
        }
      }
    }
  }

  for(int i = 0; i < (n + m) * maxn; i++)
  {
    if(dp[n - 1][m - 1][i] == 1)
    {
      cout << i << endl;
      return 0;
    }
  }
  return 0;
}