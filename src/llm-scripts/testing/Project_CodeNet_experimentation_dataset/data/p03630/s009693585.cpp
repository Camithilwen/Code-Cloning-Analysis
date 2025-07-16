//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define db long double
#define pb push_back
#define ppb pop_back
#define fi first
#define se second
#define mp make_pair
#define all(x) (x).begin(), (x).end()

void dout() { cerr << '\n'; }

template <typename Head, typename... Tail>
void dout(Head H, Tail... T) {
    cerr << " " << H;
    dout(T...);
}

#ifdef LOCAL
    #define dbg(...) cerr << #__VA_ARGS__, dout(__VA_ARGS__)
#else
    #define dbg(...) ;
#endif

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef pair <int, int> pii;

const int N = 2007;
int n, m, adj[N][N], good[N][N];
int f[N][N], l[N][N], r[N][N];

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif

    cin >> n >> m;
    char ch;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> ch;
            if (ch == '.') {
                adj[i][j] = 1;
            }
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            good[i][j] = 1;
            if (adj[i][j] ^ adj[i][j + 1] ^ adj[i + 1][j] ^ adj[i + 1][j + 1]) {
                good[i][j] = 0;
            }
        }
    }
    for (int j = 1; j < m; j++) {
        for (int i = 1; i < n; i++) {
            if (good[i][j]) {
                f[i][j] = f[i - 1][j] + 1;
            }
        }
    }
    stack <int> st;
    int ans = max(n, m);
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            while (!st.empty() && f[i][st.top()] >= f[i][j]) {
                st.pop();
            }
            if (st.empty()) {
                l[i][j] = 1;
            }   else {
                l[i][j] = st.top() + 1;
            }
            st.push(j);
        }
        while (!st.empty()) {
            st.pop();
        }
        for (int j = m - 1; j >= 1; j--) {
            while (!st.empty() && f[i][st.top()] >= f[i][j]) {
                st.pop();
            }
            if (st.empty()) {
                r[i][j] = m - 1;
            }   else {
                r[i][j] = st.top() - 1;
            }
            st.push(j);

            ans = max(ans, (r[i][j] - l[i][j] + 2) * (f[i][j] + 1));
        }
        while (!st.empty()) {
            st.pop();
        }
    }
    cout << ans;
}
