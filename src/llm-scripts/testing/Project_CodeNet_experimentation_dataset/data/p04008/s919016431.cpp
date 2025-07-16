#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vs = vector<string>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int cuts = 0;

int go(auto& g, int K, int loc) {
    int ht = 0;
    for (int ch : g[loc]) {
        int bl = go(g, K, ch);

        if (bl + 1 > K - !!loc)
            cuts++;
        else
            ht = max(ht, bl + 1);
    }
    return ht;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K;
    cin >> N >> K;

    vvi g(N);

    vi par(N);
    for (int i = 0; i < N; i++) {
        cin >> par[i];
        --par[i];
        if (i) {
            g[par[i]].push_back(i);
        }
    }

    go(g, K, 0);
    cout << !!par[0] + cuts << endl;

    return 0;
}

