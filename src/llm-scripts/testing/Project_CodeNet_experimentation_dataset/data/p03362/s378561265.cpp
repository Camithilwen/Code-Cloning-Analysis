#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// --------------------------------------------------------
template<class T> bool chmax(T& a, const T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T& a, const T b) { if (b < a) { a = b; return 1; } return 0; }
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
static const double EPS = 1e-10;
static const double PI  = acos(-1.0);
static const ll MOD = 1000000007;
// static const ll MOD = 998244353;
static const int INF = 1 << 30;
// static const ll INF = 1LL << 62;
// --------------------------------------------------------

vector<bool> is_prime_numbers(ll n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = false;
    is_prime[1] = false;
    ll root_n = (ll)(sqrt(n) + 0.5);
    for (int i = 2; i <= root_n; i++) {
        for (int j = 2 * i; j <= n; j += i) {
            is_prime[j] = false;
        }
    }
    return is_prime;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(10);

    ll N; cin >> N;

    static const int MAX_A = 55555;
    auto is_prime = is_prime_numbers(MAX_A);
    
    VI B;
    FOR(i,11,MAX_A+1) {
        if (is_prime[i]) {
            if (i % 5 == 1) {
                B.push_back(i);
                if (SZ(B) == N) break;
            }
        }
    }

    REP(i,N) {
        if (i) cout << " ";
        cout << B[i];
    }
    cout << endl;

    return 0;
}
