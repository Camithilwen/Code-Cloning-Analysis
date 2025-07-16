#include <bits/stdc++.h>
using namespace std;

#define REP(i, m, n) for (int i = (m); i < (int)(n); i++)
#define REPS(i, m, n) for (int i = (m); i <= (int)(n); i++)
#define rep(i, n) REP(i, 0, n)
#define reps(i, n) for (int i = 0; i <= (int)(n); i++)
#define rrep(i, x) for (int i = ((int)(x)-1); i >= 0; i--)
#define rreps(i, x) for (int i = (int)(x); i >= 0; i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef pair<int, int> P;
const int inf = INT_MAX;
const ll INF = 1LL << 60;
const ll mod = 1e9 + 7;
const double EPS = 1e-10;
const double PI = acos(-1.0);
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename A, size_t N, typename T> void Fill(A (&array)[N], const T &val) { fill( (T*)array, (T*)(array+N), val ); }
template <class T1, class T2, class Pred = std::less<T2> >
struct sort_pair_second {
    bool operator()(const std::pair<T1,T2>&left, const std::pair<T1,T2>&right) {
        Pred p;
        return p(left.second, right.second);
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N; cin >> N;
    vector<ll> a(N);
    rep(i, N) cin >> a[i];
    ll s = 0;
    rep(i, N) s ^= a[i];
    ll ans = s;
    rep(i, N) {
      // s で１が立っていたビットを強制的にa[i]を0にビットを変換（考慮しない）
      a[i] &= ~s;
    }
    int r = 0;
    vector<int> top(N);
    for (int i = 60; i >= 0; i--) {
      int j = r;
      for (; j < N; j++) {
        if (a[j] >> i & 1) {
          swap(a[r], a[j]);
          break;
        }
      }
      if (j == N) continue;
      top[r] = i;
      rep(k, N) {
        if (r == k) continue;
        if (a[k] >> i & 1) a[k] ^= a[r];
      }
      r++;
    }
      
    ll x = 0;
    for (int i = 60; i >= 0; i--) {
      ll nx = x | (1ll << i);
      ll b = nx;
      rep(j, r) {
        if (b >> top[j] & 1) b ^= a[j];
      }
      if ((b & nx) == 0) {
        x = nx;
      }
    }
    ans += x * 2;
    cout << ans << endl;
    return 0;

}