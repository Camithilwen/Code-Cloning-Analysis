#include <bits/stdc++.h>
#define pb          emplace_back
#define ll          long long
#define fi          first
#define se          second
#define mp          make_pair
#define int         int64_t

using namespace std;

typedef pair<int, int> pii;
const int N = int(1e5) + 2;
const int inf = (int)1e15;

int n, a[N], sumxor, basis[N];

void Ins(int x) {
    for(int i = 59; i >= 0; --i) {
        if(!(x >> i & 1)) continue;
        if(basis[i] == 0) {
           basis[i] = x; return;
        }
        x ^= basis[i];
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    #define Task        "test"
    if(fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        sumxor ^= a[i];
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j < 60; ++j)
            if(sumxor & a[i] & (1ll << j)) a[i] ^= (1ll << j);
        Ins(a[i]);
    }
    int ans = 0;
    for(int i = 59; i >= 0; --i) {
        if(!basis[i]) continue;
        if(ans >> i & 1) continue;
        ans ^= basis[i];
    }
    cout << ans * 2  + sumxor;
}
