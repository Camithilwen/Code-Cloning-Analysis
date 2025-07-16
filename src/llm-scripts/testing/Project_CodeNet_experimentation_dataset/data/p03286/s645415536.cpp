
#pragma GCC optimize ("O3")

#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include <prettyprint.hpp>
#define debug(...)  cerr << "[" << #__VA_ARGS__ << "]: ", d_err(__VA_ARGS__);
#else
#define debug(...) 83;
#endif

void d_err() {
    cerr << endl;
}

template <typename H, typename... T>
void d_err(H h, T... t) {
    cerr << h << " ";
    d_err(t...);
}

template <typename T>
void print(T x) {
    cout << x << endl;
}

#define ALL(x) (x).begin(), (x).end()
#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define REVFOR(i, m, n) for (int i = (n - 1); i >= (m); --i)
#define REP(i, n) FOR(i, 0, n)
#define REVREP(i, n) REVFOR(i, 0, n)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define bcnt __builtin_popcountll

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<ll,ll> Pll;
typedef pair<int,int> Pin;

ll INF = 1e16;
int inf = 1e9;
ll MOD = 1e9+7;


int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    ll N;
    cin >> N;
    
    if (N == 0) {
        print(0);
        return 0;
    }

    vector<pair<ll, ll>> v;

    ll l = 0, r = 0;
    ll c = 1;
    REP(i, 50) {
        v.eb(l, r);
        if (l <= N && N <= r) break;
        (i % 2 ? l : r) += c;

        c *= -2;
    }

    string S(v.size() - 1, '0');

    c /= -2;
    REVFOR(i, 1, v.size()) {
        if (v[i].fi <= N && N <= v[i].se && (v[i-1].fi > N || v[i-1].se < N)) {
            S[i - 1] = '1';
            N -= c;
        }

        c /= -2;
    }

    reverse(ALL(S));
    print(S);
}
