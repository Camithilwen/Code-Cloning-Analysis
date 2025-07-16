#include <algorithm>
#include <bitset>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <cctype>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <cassert>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <limits>
#include <map>
#include <memory>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;
using ll = long long; 
using ld = long double;
#define endl "\n"
//#define int long long
#define ALL(x) begin(x),end(x)
#define RALL(a) (a).rbegin(), (a).rend()
#define _CRT_SECURE_NO_WARNINGS
#define rep(i, n) for (int i = 0; i < n; i++)
const int MOD = 1e9 + 7;
const ll INF = 1LL << 60;
const int inf = 1 << 25;
constexpr long double pi = 3.141592653589793238462643383279;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
ll fact(ll i) {
    if (i == 0) return 1;
    return ((fact(i - 1)) * i) % MOD;
}
ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}
ll keta(ll n) {
    if (n == 0) return 1;
    ll count = 0;
    while (n != 0) {
        n /= 10;
        count++;
    }
    return count;
}
ll ketasum(ll n) {
    ll sum = 0;
    while (n != 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
ll mch(ll n) {
    if (n == 1) return 1;
    else return n * mch(n - 1);
}
ll modpow(ll a, ll n, ll mod) {
    ll hi = 1;
    while (n > 0) {
        if (n & 1) hi = hi * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return hi;
}
bool is_prime(const unsigned n) {
    switch (n) {
    case 0: // fall-through
    case 1: return false;
    case 2: // fall-through
    case 3: return true;
    } // n > 3 が保証された
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (unsigned i = 5; i * i <= n; i += 6) {
        if (n % i == 0) return false; // (6の倍数)-1
        if (n % (i + 2) == 0) return false; // (6の倍数)+1
    }
    return true;
}
/*signed*/int main(void) {
    int n, m; 
    cin >> n >> m;
    vector<pair<int, int>> p(m);
    rep(i, m) {
        int s, c; 
        cin >> s >> c;
        s--;
        p[i] = make_pair(s, c);
    }
    rep(i, 1000) {
        string s = to_string(i);
        if (s.size() == n) {
            bool ans = true;
            rep(j, m) {
                if ((s[p[j].first] - '0') != p[j].second)ans = false;
            }
            if (ans) {
                cout << i << endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;
    return 0;
}