#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// --------------------------------------------------------
#define FOR(i,l,r) for (int i = (l); i < (r); ++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(c) (c).begin(), (c).end()
#define RALL(c) (c).rbegin(), (c).rend()
#define SORT(c) sort(ALL(c))
#define RSORT(c) sort(RALL(c))
#define MIN(c) *min_element(ALL(c))
#define MAX(c) *max_element(ALL(c))
#define SUM(c) accumulate(ALL(c), 0)
#define SUMLL(c) accumulate(ALL(c), 0LL)
#define SZ(c) ((int)(c).size())
#define debug(x) cerr << #x << " = " << (x) << '\n';
using P = pair<int,int>;
using VP = vector<P>;
using VVP = vector<VP>;
using VS = vector<string>;
using VI = vector<int>;
using VVI = vector<VI>;
using VLL = vector<ll>;
using VVLL = vector<VLL>;
using VB = vector<bool>;
using VVB = vector<VB>;
using VD = vector<double>;
using VVD = vector<VD>;
const double EPS = 1e-10;
const double PI  = acos(-1.0);
const ll MOD = 1000000007;
// const ll MOD = 998244353;
const int INF = 1 << 30;
// const ll INF = 1LL << 62;
// --------------------------------------------------------


int binary_search_A(vector<int> &a, int key) {
    // Meguru type binary search
    int ok = -1;
    int ng = a.size();

    auto is_ok = [&] (int idx) {
        if (a[idx] < key) {
            return true;
        } else {
            return false;
        }
    };

    int mid;
    while (abs(ok - ng) > 1) {
        mid = (ok + ng) / 2;
        if (is_ok(mid)) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    return ok;
}


int binary_search_C(vector<int> &a, int key) {
    // Meguru type binary search
    int ng = -1;
    int ok = a.size();

    auto is_ok = [&] (int idx) {
        if (key < a[idx]) {
            return true;
        } else {
            return false;
        }
    };

    int mid;
    while (abs(ok - ng) > 1) {
        mid = (ok + ng) / 2;
        if (is_ok(mid)) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    return ok;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(10);

    int N; cin >> N;
    VI A(N); REP(i,N) cin >> A[i];
    VI B(N); REP(i,N) cin >> B[i];
    VI C(N); REP(i,N) cin >> C[i];

    SORT(A);
    SORT(B);
    SORT(C);

    ll ans = 0;
    for (auto b : B) {
        int ia = binary_search_A(A, b);
        int ic = binary_search_C(C, b);
        ans += (ll)(ia + 1) * (N - ic);
    }
    cout << ans << '\n';

    return 0;
}
