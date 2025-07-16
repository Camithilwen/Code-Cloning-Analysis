#pragma target("avx")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> P;
typedef vector<ll> V;
typedef unordered_map<ll, ll> U_MAP;
typedef priority_queue<ll> pq;
typedef priority_queue<ll, vector<ll>, greater<ll>> rpq;
const int INF = 1e9, MOD = 1e9 + 7, ohara = 1e6 + 10;
const ll LINF = 1e18;

#define rep(i, n) for (ll(i) = 0; (i) < (int)(n); (i)++)
#define rrep(i, a, b) for (ll i = (a); i < (b); i++)
#define rrrep(i, a, b) for (ll i = (a); i >= (b); i--)
#define all(v) (v).begin(), (v).end()
#define Size(n) (n).size()
#define Cout(x) cout << (x) << endl
#define doublecout(a) cout << fixed << setprecision(15) << a << endl;
#define fi first
#define se second
#define m_p make_pair
#define p_b push_back
string to_string(string s) { return '"' + s + '"'; }
string to_string(const char* s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto& x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

//------ Believe yourself as a genius!!!!!! ------

int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};
// int dy[]={-1,0,1,-1,1,-1,0,1};int dx[]={-1,-1,-1,0,0,1,1,1};
string alph("abcdefghijklmnopqrstuvwxyz"), s;
ll n, cnt, ans, a[ohara], b, c, d, tmp, m, h, w, x, y, sum[ohara], k, q;

int main(void) {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(false);

  cin >> n;
  rep(i, n) cin >> a[i], sum[i] = a[i];
  rrep(i, 1, n) sum[i] += sum[i - 1];

  ans = LINF;
  rrep(i, 1, n - 2) {
    ll peace1, peace2, peace3, peace4, dis;

    ll le = 0, ri = i - 1, mid;
    while (ri - le > 1) {
      mid = (le + ri) / 2;
      if (sum[mid] >= sum[i] - sum[mid])
        ri = mid;
      else
        le = mid;
    }

    dis = LINF;
    rrep(j, le, ri + 1) {
      if (dis >= abs(sum[j] - (sum[i] - sum[j]))) {
        dis = abs(sum[j] - (sum[i] - sum[j]));
        peace1 = sum[j];
        peace2 = sum[i] - sum[j];
      }
    }

    le = i + 1, ri = n - 2, mid;
    while (ri - le > 1) {
      mid = (le + ri) / 2;
      if (sum[mid] - sum[i] >= sum[n - 1] - sum[mid])
        ri = mid;
      else
        le = mid;
    }

    dis = LINF;
    rrep(j, le, ri + 1) {
      if (dis >= abs((sum[j] - sum[i]) - (sum[n - 1] - sum[j]))) {
        dis = abs((sum[j] - sum[i]) - (sum[n - 1] - sum[j]));
        peace3 = sum[j] - sum[i];
        peace4 = sum[n - 1] - sum[j];
      }
    }

    ans = min(ans, max({peace1, peace2, peace3, peace4}) -
                       min({peace1, peace2, peace3, peace4}));
  }
  Cout(ans);
  return 0;
}