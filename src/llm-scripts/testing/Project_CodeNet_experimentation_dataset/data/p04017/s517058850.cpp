#include <bits/stdc++.h>
#define pb          emplace_back
#define ll          long long
#define fi          first
#define se          second
#define mp          make_pair

using namespace std;

const int N = int(3e5) + 7;
const int logN = 17;
const int mod = int(1e9) + 7;
typedef pair<int, int> pii;

int p[N][logN + 1], x[N], n, l, q, a, b;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    #define Task        "test"
    if(fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> x[i];
    cin >> l;
    for(int i = 1, j = 1; i <= n; ++i) {
       while(j <= n && x[j] - x[i] <= l) ++j;
       p[i][0] = j - 1;
    }
    for(int j = 1; j <= logN; ++j) {
       for(int i = 1; i <= n; ++i)
          p[i][j] = p[p[i][j - 1]][j - 1];
    }
    cin >> q;
    while(q --) {
        cin >> a >> b; int res = 1;
        if(a > b) swap(a, b);
        for(int j = logN; j >= 0; --j)
            if(p[a][j] < b) res += (1 << j), a = p[a][j];
        cout << res << '\n';
    }
}
