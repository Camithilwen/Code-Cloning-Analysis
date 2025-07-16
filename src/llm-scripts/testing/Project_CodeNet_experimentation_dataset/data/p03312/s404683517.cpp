#include <bits/stdc++.h>

#define ll long long
#define str string
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fi first
#define se second

#define vc vector<char>
#define vvc vector<vc>
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vi>
#define vvll vector<vll>
#define vvvll vector<vvll>
#define vs vector<str>
#define vvs vector<vs>
#define vpii vector<pii>
#define vvpii vector<vpii>
#define vpll vector<pll>
#define vvpll vector<vpll>
#define vb vector<bool>
#define vvb vector<vb>
#define rep(i, a, b) for (int i = (a); i < int(b); i++)
#define repi(i, a, b) for (int i = (a); i <= int(b); i++)


using namespace std;
ll INF = LONG_LONG_MAX;
ll mod = 1000000000 + 7;

template <typename T, typename L>
void readVector(vector<T> & _data, L & _size, bool _shift) {
    _data.resize(_size + (ll)_shift);
    for (ll i = (ll)_shift; i < _size + (ll)_shift; i++)
        cin >> _data[i];
}

template <typename T, typename L>
void readMatrix(vector<vector<T>> & _data, L & _rows, L & _cols, bool _shiftRows, bool _shiftCols) {
    _data.resize(_rows + (ll)_shiftRows);
    for (ll i = 0; i < _rows + (ll)_shiftRows; i++)
        _data[i].resize(_cols + (ll)_shiftCols);
    for (ll i = (ll)_shiftRows; i < _rows + (ll)_shiftRows; i++)
        for (ll j = (ll)_shiftCols; j < _cols + (ll)_shiftCols; j++)
            cin >> _data[i][j];
}


//TODO: SOLUTION

ll n;
vll a, pre, f, g;

void computeG() {
    ll j = n - 2;
    g[n - 1] = n;

    while (j >= 1) {
        int k = g[j + 1];
        while (abs(pre[n] - (2*pre[k - 1]) + pre[j - 1]) > abs(pre[n] - (2*pre[k - 2]) + pre[j - 1]))
            k--;
        g[j] = k;
        j--;
    }
}

void computeF() {
    ll j = 3;
    f[2] = 1;

    while (j <= n) {
        int k = f[j - 1];
        while (abs(pre[j] - (2*pre[k])) > abs(pre[j] - (2*pre[k + 1])))
            k++;
        f[j] = k;
        j++;
    }
}

void solve() {
    cin >> n;
    readVector(a, n, 1);
    pre.resize(n + 1, 0);

    repi(i, 1, n) {
        pre[i] = pre[i - 1] + a[i];
    }

    f.resize(n + 1);
    g.resize(n + 1);

    computeF();
    computeG();

    ll ans = INF;
    repi(i, 2, n - 2) {
        ans = min(ans, max(max(max(pre[f[i]], pre[i] - pre[f[i]]), pre[n] - pre[g[i + 1] - 1]), pre[g[i + 1] - 1] - pre[i])
                      -min(min(min(pre[f[i]], pre[i] - pre[f[i]]), pre[n] - pre[g[i + 1] - 1]), pre[g[i + 1] - 1] - pre[i]));
    }

    cout << ans << endl;
}


int main() {

    // TODO: Set value of this variable manually
    bool _multipleTestCases = false;

    if (_multipleTestCases) {
        ll t; cin >> t;
        while (t--)
            solve();
    }
    else {
        solve();
    }

    return 0;
}