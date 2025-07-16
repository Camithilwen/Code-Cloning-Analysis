#include <bits/stdc++.h>
#include <cmath>

const double PI = 3.14159265358979323846;
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
//typedef pair<ll, ll> P;
typedef pair<ll, ll> P;
const ll INF = 10e17;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

std::istream &operator>>(std::istream &in, set<int> &o) {
    ll a;
    in >> a;
    o.insert(a);
    return in;
}

std::istream &operator>>(std::istream &in, queue<int> &o) {
    ll a;
    in >> a;
    o.push(a);
    return in;
}

bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }

//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
const int mod = 1000000007;
//const ll mod = 1e10;
typedef priority_queue<string, vector<string>, greater<string> > PQ_ASK;

#include <iostream>
#include <vector>

using namespace std;


int main() {
    int n;
    cin >> n;

    vector<int> numbers(n);
    rep(i, n) cin >> numbers[i];

    if (numbers.front() != 0) {
        cout << -1 << endl;
        ret();
    }

    vector<int> dp(n);
    dp.back() = numbers.back();
    for (int i = n - 2; i >= 0; i--) {
        dp[i] = max(numbers[i], dp[i + 1] - 1);
    }

    rep(i, n) {
        if (numbers[i] < dp[i]) {
            cout << -1 << endl;
            ret();
        }
    }
    ll ans = 0;
    rep(i, n - 1) {
        if (dp[i] > dp[i + 1] - 1) {
            ans += dp[i];
        }
    }
    ans += numbers.back();

    cout << ans << endl;

}



