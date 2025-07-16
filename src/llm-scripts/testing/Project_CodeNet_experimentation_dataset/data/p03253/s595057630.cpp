#include <bits/stdc++.h>
using namespace std;

#define sz(x) int(x.size())
#define Task "abc"
#define For(i, a, b) for(int i = (a), _b = (b); i <= b; ++i)
#define All(x) (x).begin(), (x).end()
#define mp make_pair

typedef long long ll;

const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;
const ll mod = 1e9 + 7;

int n, m;
ll gt[maxn], igt[maxn];
ll f[31][31627 * 2];

ll Pow(ll a, ll b){
  if (b == 0) return 1;
  ll tmp = Pow(a, b / 2);
  tmp = (tmp * tmp) % mod;
  if (b % 2) return (tmp * a) % mod;
  return tmp;
}

void init(){
  const int maxp = 1e5;
  gt[0] = 1;
  for (int i = 1; i <= maxp; ++i)
    gt[i] = (gt[i-1] * i) % mod;

  igt[maxp] = Pow(gt[maxp], mod - 2);

  for (int i = maxp - 1; i >= 0; --i)
    igt[i] = (igt[i+1] * (i + 1)) % mod;
}

ll comb(int k, int n){
  return ( (gt[n] * igt[n - k]) % mod * igt[k]) % mod;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
//  freopen(Task".inp", "r", stdin);  freopen(Task".out", "w", stdout);
  cin >> n >> m;
  if (m == 1){
    cout << 1; return 0;
  }
  vector<int> div;

  for (int i = 1; i * i <= m; ++i){
    if (m % i == 0){
      div.push_back(i);
      if (i * i != m) div.push_back(m / i);
    }
  }

  int len = div.size();
  unordered_map<int, int> Pos;
  for (int i = 0; i < len; ++i)
    Pos[div[i]] = i;

  for (int i = 1; i < len; ++i)
    f[1][i] = 1;

  for (int k = 1; k < 30; ++k){
    for (int i = 1; i < len; ++i){
      for (int j = 1; j < len; ++j){
        if (div[j] % div[i] == 0 && div[j] / div[i] > 1)
          f[k+1][j] = (f[k+1][j] + f[k][i]) % mod;
      }
    }
  }


  init();
  ll ans = 0;
  for (int x = 1; x <= min(30, n); ++x){
    ans += f[x][Pos[m]] * comb(x, n);
    ans %= mod;
  }
  cout << ans;

}


