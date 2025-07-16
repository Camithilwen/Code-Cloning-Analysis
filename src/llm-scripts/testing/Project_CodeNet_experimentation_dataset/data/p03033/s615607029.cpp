#include <iostream>
#include <iomanip>
#include <cstdio>
#include <queue>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <bitset>
#include <set>
#include <stack>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define RREP(i,n) for(int i=n-1;i>=0;i--)
#define FOR(i,k,n) for(int i=(k);i<(int)(n);i++)
#define all(i,n) (i),(i+n)

int dx4[4]={1,0,-1,0};
int dy4[4]={0,-1,0,1};
int dx8[8]={1,0,-1,1,-1,1,0,-1};
int dy8[8]={1,1,1,0,0,-1,-1,-1};
int dx9[9]={0,1,0,-1,1,-1,1,0,-1};
int dy9[9]={0,1,1,1,0,0,-1,-1,-1};

typedef pair<int, int> P;
typedef pair<string, int> SP;
typedef long long ll;
typedef pair<ll, ll> PLL;

const int INF = 1e9;
const ll LLINF = 1e18;
const int MAX_V = 1e6+1;
const ll mod = 1000000007;
// << fixed << setprecision
// --------------------------------------
int n, q;
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> n >> q;
  set<P> vp;
  vector<tuple<int, int, int>> ve;

  REP(i, n) {
    int l, r, x;
    cin >> l >> r >> x;
    l -= x; r -= x;
    ve.push_back(tie(x, l, r));
  }

  sort(ve.begin(), ve.end());

  REP(i, q) {
    int d;
    cin >> d;
    vp.insert(P(d, i));
  }

  vector<int> ans(q, -1);
  REP(i, n) {
    int x, l, r;
    tie(x, l, r) = ve[i];

    auto it = vp.lower_bound(P(l, -1));
    while(it != vp.end()) {
      if(it->first >= r) break;
      ans[it->second] = x;
      vp.erase(it++);
    }
  }

  REP(i, q) cout << ans[i] << endl;
}
