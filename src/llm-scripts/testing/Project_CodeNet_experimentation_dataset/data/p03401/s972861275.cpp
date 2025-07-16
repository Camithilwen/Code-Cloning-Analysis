/**
*    created: 01.07.2020 15:47:43
**/
#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
// #include <boost/multiprecision/cpp_int.hpp>
// using bint = boost::multiprecision::cpp_int;
using namespace std;
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define pcnt(bit) __builtin_popcountll(bit)
template<class T> bool chmax(T &a, const T &b) {if (a < b) {a = b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b) {if (b < a) {a = b; return 1;} return 0;}
const int mod = 1000000007;
// const int MOD = 998244353;
const long double pi = acos(-1.0);
const int inf = 1LL << 60;

signed main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    rep(i,n) {
        cin >> a[i];
        if (i != 0) sum += abs(a[i] - a[i-1]);
    }
    sum += abs(a[0]);
    sum += abs(a[n-1]);
    rep(i,n) {
        if (i == 0) cout << sum - (abs(a[0]) + abs(a[1] - a[0])) + abs(a[1]) << endl;
        else if (i == n-1) cout << sum - (abs(a[n-1] - a[n-2]) + abs(a[n-1])) + abs(a[n-2]) << endl;
        else cout << sum - (abs(a[i]-a[i-1]) + abs(a[i+1]-a[i])) + abs(a[i+1]-a[i-1]) << endl;;
    }
    return 0;
}