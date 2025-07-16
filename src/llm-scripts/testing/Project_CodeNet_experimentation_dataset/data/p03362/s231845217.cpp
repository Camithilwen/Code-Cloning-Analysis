/**
*	created: 24.08.2020 21:32:00
**/
#include <bits/stdc++.h>
// #include <boost/multiprecision/cpp_int.hpp>
// using bint = boost::multiprecision::cpp_int;
using namespace std;
using ll = long long;
using P = pair<int,int>;
// #define endl '\n'
#define int long long
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define rep2(i,s,n) for (int i = (s); i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define pcnt(bit) __builtin_popcountll(bit)
template<class T> bool chmax(T &a, const T &b) {if (a < b) {a = b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b) {if (b < a) {a = b; return 1;} return 0;}
const long double pi = acos(-1.0);
const int MAX = 1000010;
const int INF = 1ll << 60;
const int MOD = 1000000007;
// const int MOD = 998244353;



signed main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n; cin >> n;
    vector<int> v;
    v.push_back(2);
    rep2(i,3,55556) {
        bool ok = true;
        rep2(j,2,sqrt(i)+1) if (i % j == 0) ok = false;
        if (ok) v.push_back(i);
    }
    vector<int> v1;
    for (auto p : v) if (p % 5 == 1) v1.push_back(p);
    rep(i,n) {
        if (i == 0) cout << v1[i];
        else cout << " " << v1[i];
    }
    cout << endl;
    return 0;
}