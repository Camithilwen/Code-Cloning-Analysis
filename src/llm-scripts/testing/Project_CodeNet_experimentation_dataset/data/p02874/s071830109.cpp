#include <bits/stdc++.h>
using namespace std;

#define rep(i,s,n) for (int i = (int)s; i < (int)n; i++)
#define ll long long
#define pb push_back
#define eb emplace_back
#define All(x) x.begin(), x.end()
#define Range(x, i, j) x.begin() + i, x.begin() + j
#define lbidx(x, y) lower_bound(x.begin(), x.end(), y) - x.begin()
#define ubidx(x, y) upper_bound(x.begin(), x.end(), y) - x.begin()
#define llbidx(x, y, z) lower_bound(x.begin(), x.end(), z) - lower_bound(x.begin(), x.end(), y) // 二要素間の距離
#define deg2rad(deg) ((((double)deg)/((double)360)*2*M_PI))
#define rad2deg(rad) ((((double)rad)/(double)2/M_PI)*(double)360)
#define Find(set, element) set.find(element) != set.end()
#define Decimal(x) printf("%.10f\n", x) // 小数点を10桁まで表示
// debug用
#define PrintVec(x) for (auto elementPrintVec: x) { cout << elementPrintVec << " "; } cout << endl;

typedef pair<int, int> PI;
typedef pair<ll, ll> PLL;

int POWINT(int x, int n) {
  int ret = 1;
  rep(i, 0, n) ret *= x;
  return ret;
};

ll POWLL(int x, int n) {
  ll ret = 1;
  rep(i, 0, n) ret *= x;
  return ret;
};

template<class T>
inline bool chmax(T &a, T b) {
  if(a < b) {
    a = b;
    return true;
  }
  return false;
};

template<class T>
inline bool chmin(T &a, T b) {
  if(a > b) {
    a = b;
    return true;
  }
  return false;
};

struct Q {
  int l, r, id;
};

bool lessL(const Q &q1, const Q &q2) {
  return q1.l < q2.l;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N;
  cin >> N;
  vector<Q> q(N);

  int max_l = 0;
  int min_r = 1e9+7;
  int max_len = 0;
  rep(i, 0, N) {
    cin >> q[i].l >> q[i].r;
    q[i].r++;
    q[i].id = i;

    if (q[i].l > max_l) {
      max_l = q[i].l;
    }

    if (q[i].r < min_r) {
      min_r = q[i].r;
    }

    max_len = max(q[i].r - q[i].l, max_len);
  }

  int ans = max_len + max(0, min_r - max_l);

  int ans_min_r = 2e9+7;
  int ans_max_l = 2e9+7;

  vector<PI> a(N);
  rep(i, 0, N) {
    a[i].first = max(q[i].r - max_l, 0);
    a[i].second = max(min_r - q[i].l, 0);
  }

  sort(All(a));

  int mn = a[0].second;
  rep(i, 1, N) {
    ans = max(ans, mn + a[i].first);
    mn = min(mn, a[i].second);
  }

  cout << ans << endl;

  return 0;
};
