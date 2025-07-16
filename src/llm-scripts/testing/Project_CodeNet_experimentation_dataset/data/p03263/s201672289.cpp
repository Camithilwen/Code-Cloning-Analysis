// #pragma GCC target("avx2")
#pragma GCC optimize("O3", "unroll-loops")

// #include <bits/extc++.h>
// using namespace __gnu_pbds;

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define double long double
// template <typename T>
// using pbds_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
using pii = pair<int, int>;
template<typename T>
using prior = priority_queue<T, vector<T>, greater<T>>;
template<typename T>
using Prior = priority_queue<T>;

#define X first
#define Y second
#define ALL(x) (x).begin(), (x).end()
#define eb emplace_back
#define pb push_back

#define fastIO() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define RANDOM() random_device __rd; \
                 mt19937 __gen = mt19937(__rd()); \
                 uniform_int_distribution<int> __dis(1, 1E8); \
                 auto rnd = bind(__dis, __gen)

const int INF = 1E18;
const int mod = 1E9 + 7;
const int maxn = 100 + 5;

int32_t main() {
    fastIO();
    
    int n, m;
    cin >> n >> m;
    
    int vec[n][m];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) cin >> vec[i][j];
    }
    
    vector<pair<pii, pii>> op;
    for (int i = 0; i < n; ++i) {
        if (i < n-1) {
            for (int j = 0; j < m; ++j) {
                if (vec[i][j] & 1) {
                    op.pb({{i+1, j+1}, {i+2, j+1}});
                    ++vec[i+1][j];
                }
            }
        }
        else {
            for (int j = 0; j < m-1; ++j) {
                if (vec[i][j] & 1) {
                    op.pb({{i+1, j+1}, {i+1, j+2}});
                    ++vec[i][j+1];
                }
            }
        }
    }
    
    cout << op.size() << "\n";
    for (auto x : op) cout << x.X.X << " " << x.X.Y << " " << x.Y.X << " " << x.Y.Y << "\n";
    
    return 0;
}