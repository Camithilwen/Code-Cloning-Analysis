#include <bits/stdc++.h>
using namespace std;

template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string& s) {
  return '"' + s + '"';
}

string to_string(const char* s) {
  return to_string((string) s);
}

string to_string(bool b) {
  return (b ? "true" : "false");
}

string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}

template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}

template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

#define rep(i,n) for (int i = 0; i < n; ++i)
#define reps(i,s,n) for (int i = s; i < n; ++i)
#define rep1(i,n) for (int i = 1; i <= n; ++i)
#define per(i,n) for (int i = n - 1; i >= 0; --i)
#define per1(i,n) for (int i = n; i >= 1; --i)
#define all(c) begin(c),end(c)
template<typename T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<typename T> inline T intceil(T a, T b) { return (a + (b - 1)) / b; }
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;
const long long MOD = 1e9+7;
#define precout() cout << std::fixed << std::setprecision(20);
#define print(a) cout << a << endl;
template<typename T> void printv(vector<T>&v) {
    int n = v.size() - 1;
    rep(i, n) cout << v[i] << " ";
    cout << v.back() << endl;
}
const string alphabet = "abcdefghijklmnopqrstuvwxyz";
const int dy[4] = { 0, 1, 0, -1 };
const int dx[4] = { 1, 0, -1, 0 };
// if(nextH >= 0 && nextH < H && nextW >= 0 && nextW < W)
static const long double pi = acos(-1.0);
typedef complex<ld> cd;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int H, W, K; cin >> H >> W >> K;

    --K;
    vector<vector<long long> > dp(H+1, vector<long long>(W, 0));
    dp[0][0] = 1;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            for (int bit = 0; bit < 1<<(W-1); ++bit) {
                bool ok = true;
                for (int k = 0; k < W-2; ++k) {
                    if ((bit & (1<<k)) && (bit & (1<<(k+1)))) ok = false;
                }
                if (!ok) continue;
                int nj = j;
                if (bit & (1<<j)) nj = j+1;
                else if (j > 0 && (bit & (1<<(j-1)))) nj = j-1;
                dp[i+1][nj] += dp[i][j];
                dp[i+1][nj] %= MOD;
            }
        }
    }
    print(dp[H][K]);
}
