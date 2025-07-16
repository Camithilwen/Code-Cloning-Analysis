#include <bits/stdc++.h>

using namespace std;

int N;

vector<int> a, b;

vector<int> kmp(const vector<int> &vt, vector<int> &vp)

{

    int i, q, k;

    int n = vt.size();

    int m = vp.size();

    vector<int> nxt(m);

    vector<int> res;

    for (q = 1, k = 0; q < m; ++q) {

        while (k > 0 && vp[q] != vp[k]) k = nxt[k - 1];

        if (vp[q] == vp[k]) k++;

        nxt[q] = k;

    }

    for (i = 0, q = 0; i < n; ++i) {

        while (q > 0 && vp[q] != vt[i]) q = nxt[q - 1];

        if (vp[q] == vt[i]) q++;

        if (q == N) {

            res.push_back(i - m + 1);

            q = nxt[q - 1];

        }

    }

    return res;

}

void solve()

{

    vector<int> c(2*N-1);

    vector<int> d(N);

    for (int i = 0; i < N - 1; i++) {

        c[i] = a[i] ^ a[i + 1];

        d[i] = b[i] ^ b[i + 1];

    }

    c[N - 1] = a[N - 1] ^ a[0];

    d[N - 1] = b[N - 1] ^ b[0];

    for (int i = N; i < 2*N; i++) c[i] = c[i - N];

    auto pos = kmp(c, d);

    for (int k : pos) cout << k << " " << (b[0] ^ a[k]) << endl;

}

int main()

{
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> N;

    a.resize(N);

    b.resize(N);

    for (int i = 0; i < N; i++) cin >> a[i];

    for (int i = 0; i < N; i++) cin >> b[i];

    solve();

    return 0;

}