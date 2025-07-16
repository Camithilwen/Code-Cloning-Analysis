  #include<bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include<debug.h>
#else
#define db(...) 21
#endif

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

const int maxn = 2e6 + 10;
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
    fat[i] = (fat[i-1] * i) % mod;
    inv[i] = exp(fat[i], mod - 2);
  }
}

ll dp[maxn][2];
string s;

ll solve(int pos, int carry)
{
  if(pos == s.size())
    return carry;
  ll &ans = dp[pos][carry];
  if(ans != -1)
    return ans; 
  int val = s[pos] - '0' + carry;
  ans = 1LL << 60;
  ans = min(ans, solve(pos + 1, 1) + 10 - val);
  ans = min(ans, solve(pos + 1, 0) + val);
  return ans;
}

int main()
{
  ios::sync_with_stdio(false);
  MSET(dp, -1);
  cin >> s;
  reverse(s.begin(), s.end());
  cout << solve(0,0) << endl;
  return 0;
}