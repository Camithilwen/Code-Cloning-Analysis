#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
const double eps = 1e-10;
const int MOD = 1000000007;
const int INF = 1000000000;
const ll LINF = 1ll<<50;
template<typename T>
void printv(const vector<T>& s) {
  for(int i=0;i<(int)(s.size());++i) {
    cout << s[i];
    if(i == (int)(s.size())-1) cout << endl;
    else cout << " ";
  }
}
struct SegmentTree {
  int sz;
  vector<int> d, m, dm;
  SegmentTree(string s) {
    int n = (int)(s.size());
    sz = 1;
    while(sz < n) sz *= 2;
    d.clear();
    m.clear();
    dm.clear();
    d.resize(2*sz+1, 0);
    m.resize(2*sz+1, 0);
    dm.resize(2*sz+1, 0);
    for(int i=0;i<n;++i) {
      if(s[i] == 'D') {
        d[i+sz-1] = 1;
      } else if(s[i] == 'M') {
        m[i+sz-1] = 1;
      }
    }
    for(int i=sz-2;i>=0;--i) {
      d[i] = d[2*i+1] + d[2*i+2];
      m[i] = m[2*i+1] + m[2*i+2];
      dm[i] = dm[2*i+1] + dm[2*i+2] + d[2*i+1] * m[2*i+2];
    }
  }
  tuple<int, int, int> query(int a, int b, int l, int r, int k) {
    if(b <= l || r <= a) return make_tuple(0, 0, 0);
    if(a <= l && r <= b) return make_tuple(d[k], m[k], dm[k]);
    tuple<int, int, int> v1 = query(a, b, l, (l+r)/2, 2*k+1);
    tuple<int, int, int> v2 = query(a, b, (l+r)/2, r, 2*k+2);
    int resd = get<0>(v1) + get<0>(v2);
    int resm = get<1>(v1) + get<1>(v2);
    int resdm = get<2>(v1) + get<2>(v2) + get<0>(v1) * get<1>(v2);
    return make_tuple(resd, resm, resdm);
  }
  tuple<int, int, int> query(int a, int b) {
    return query(a, b, 0, sz, 0);
  }
};
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  int n; cin >> n;
  string s; cin >> s;
  vector<int> su(n);
  su[0] == s[0] == 'M';
  for(int i=1;i<n;++i) {
    su[i] = su[i-1] + (s[i] == 'M');
  }
  int q; cin >> q;
  for(int i=0;i<q;++i) {
    int k; cin >> k;
    ll cntd = 0, cntm = 0, now = 0, ans = 0;
    for(int j=0;j<k;++j) {
      if(s[j] == 'D') {
        cntd++;
      } else if(s[j] == 'M') {
        now += cntd;
      } else if(s[j] == 'C') {
        ans += now;
      }
    }
    for(int j=k;j<n;++j) {
      if(s[j-k] == 'D') {
        cntd--;
        now -= su[j-1] - su[j-k];
      }
      if(s[j] == 'D') {
        cntd++;
      } else if(s[j] == 'M') {
        now += cntd;
      } else if(s[j] == 'C') {
        ans += now;
      }
    }
    cout << ans << endl;
  }
}
