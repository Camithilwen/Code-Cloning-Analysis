//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using ld = long double;
using P = pair<int, int>;
using vs = vector<string>;
using vi = vector<int>;
using vvi = vector<vi>;
template<class T> using PQ = priority_queue<T>;
template<class T> using PQG = priority_queue<T, vector<T>, greater<T> >;
const int INF = 100010001;
const ll LINF = (ll)INF*INF*10;
template<typename T1, typename T2>
inline bool chmax(T1 &a, T2 b) {return a < b && (a = b, true);}
template<typename T1, typename T2>
inline bool chmin(T1 &a, T2 b) {return a > b && (a = b, true);}
template<typename T1, typename T2>
istream &operator>>(istream &is, pair<T1, T2> &p) { return is >> p.first >> p.second;}
template<typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) { return os << p.first << ' ' << p.second;}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<P> lr(n);
    rep(i, n) cin >> lr[i];

    sort(all(lr));
    int ans = 0;
    vi mil(n+1, INT_MAX), mir(n+1, INT_MAX);
    rep(i, n) {
        mil[i+1] = min(mil[i], lr[i].second);
        mir[n-1-i] = min(mir[n-i], lr[n-1-i].second);
    }

    int min = INT_MAX;
    rep(i, n-1) {
        chmin(min, lr[i].second);
        if(min < lr[i].first) break;
        chmax(ans, min-lr[i].first + mir[i+1]-lr[n-1].first + 2);
    }
    rep(i, n) {
        chmax(ans, lr[i].second - lr[i].first + 1 + (mil[n] >= lr[n-1].first?mil[n]-lr[n-1].first+1:0));
    }

    cout << ans << endl;
}