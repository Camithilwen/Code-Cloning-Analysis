#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define REP(i,n) for(int _n=n, i=0;i<_n;++i)
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
using ull = uint64_t;
using ll = int64_t;
using PII = pair<int, int>;
using VI = vector<int>;

string to_string(string s) { return '"' + s + '"'; }
string to_string(const char* s) { return to_string((string) s); }
string to_string(bool b) { return (b ? "true" : "false"); }
template <typename A, typename B> string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
template <typename A> string to_string(A v) {
bool first = true; string res = "{";
for (const auto &x : v) { if (!first) { res += ", "; } first = false; res += to_string(x); }
res += "}"; return res; }
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H); debug_out(T...); }
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

const int N = 3005;
int n, t;
int A[N], B[N];
int dp[N][N][2];

int rec(int idx, int left, int last) {
    if (idx == n) {
        return 0;
    }
    if (left <= 0) {
        return 0;
    }
    if (dp[idx][left][last] != -1) return dp[idx][left][last];
    if (last == 1) {
        if (A[idx] <= left) {
            dp[idx][left][last] = max(rec(idx + 1, left - A[idx], 1) + B[idx], rec(idx + 1, left, 1));
        } else {
            dp[idx][left][last] = rec(idx + 1, left, 1);
        }
    } else {
        if (A[idx] <= left) {
            dp[idx][left][last] = max({rec(idx + 1, left - A[idx], 0) + B[idx], rec(idx + 1, left, 0), rec(idx + 1, left - 1, 1) + B[idx]});
        } else {
            dp[idx][left][last] = max(rec(idx + 1, left - 1, 1) + B[idx], rec(idx + 1, left, 0));
        }
    }
    return dp[idx][left][last];
}



int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    cin >> n >> t;
    REP(i, n) {
        cin >> A[i];
        cin >> B[i];
    }
    memset(dp, -1, sizeof dp);
    cout << rec(0, t, 0) << "\n";
}