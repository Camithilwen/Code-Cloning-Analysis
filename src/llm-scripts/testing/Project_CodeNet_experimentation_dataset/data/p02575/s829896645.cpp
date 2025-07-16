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
void read(vector<T> & _data, L & _size, bool _shift) {
    _data.resize(_size + (ll)_shift);
    for (ll i = (ll)_shift; i < _size + (ll)_shift; i++)
        cin >> _data[i];
}

template <typename T, typename L>
void read(vector<vector<T>> & _data, L & _rows, L & _cols, bool _shiftRows, bool _shiftCols) {
    _data.resize(_rows + (ll)_shiftRows);
    for (ll i = 0; i < _rows + (ll)_shiftRows; i++)
        _data[i].resize(_cols + (ll)_shiftCols);
    for (ll i = (ll)_shiftRows; i < _rows + (ll)_shiftRows; i++)
        for (ll j = (ll)_shiftCols; j < _cols + (ll)_shiftCols; j++)
            cin >> _data[i][j];
}

template <typename T>
void write(vector<T> & _data, bool _shift) {
    for (ll i = (ll)_shift; i < _data.size(); i++)
        cout << _data[i] << " ";
    cout << endl;
}


//TODO: SOLUTION

ll h, w;
vll l, r;

void solve() {
    cin >> h >> w;
    l.resize(h + 1);
    r.resize(h + 1);
    repi(i, 1, h) {
        cin >> l[i] >> r[i];
    }

    set<pll> s;
    map<ll, ll> m;
    m[0] = 0;

    repi(i, 1, w) {
        s.insert({i, i});
        m[0]++;
    }

    ll x = 1;
    while (x != h + 1) {
        auto it = s.lower_bound({l[x], 0});
        ll ans = INF;
        vpll todel;
        vpll toins;
        while (it != s.end() && it->first <= r[x]) {
            //cout << it->fi << " "<< it->se << ", ";
            toins.push_back({r[x] + 1, it->second});
            todel.push_back({it->first, it->second});
            it++;
        }
        for (auto p : todel) {
            m[p.first - p.second]--;
            if (m[p.first - p.second] == 0)
                m.erase(p.first - p.second);
            s.erase(p);
            //cout << "delete " << p.second << ":" << p.first << endl;
        }

        if (!toins.empty()) {
            auto p = toins[toins.size() - 1];
            //cout << "insert " << p.se << ":" << p.fi << endl;
            if (m.count(p.first - p.second) && p.first <= w)
                m[p.first - p.second]++;
            else if (p.first <= w)
                m[p.first - p.second] = 1;
            if (p.first <= w)
                s.insert(p);
        }
        if (m.empty()) {
            cout << -1 << endl;
        }
        else {
            cout << x + m.begin()->fi << endl;
        }
        x++;
    }
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