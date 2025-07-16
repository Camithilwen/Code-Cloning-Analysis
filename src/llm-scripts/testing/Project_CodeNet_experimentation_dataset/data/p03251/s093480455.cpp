#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <iomanip>
#include <bitset>
#include <set>
#include <map>
#include <stdio.h>
#include <numeric>
#include <cstring>

#define rep(i,n) for (int i = 0; i < (n); i++)
#define rep1(i,n) for (int i = 1; i < (n); i++)
#define FOR(i,a,b) for (int i=(a); i < (b); i++)
#define MOD 1000000007 //10^9+7
#define ALL(a)  (a).begin(),(a).end()
using namespace std;
using ll = long long;
using PII = pair<int, int>;
using PLL = pair<long long, long long>;
const int INF = numeric_limits<int>::max();
const ll INFL = numeric_limits<ll>::max();
constexpr ll TEN(int n) { return (n==0) ? 1 : 10*TEN(n-1); }
const double PI = acos(-1);

// 負の数にも対応した % 演算
long long mod(long long val, long long m) {
    long long res = val % m;
    if (res < 0) res += m;
    return res;
}

//greatest common divisor
long long gcd(ll a, ll b) 
{
    if (a % b == 0) {
        return b;
    } else {
        return gcd(b, a % b);
    }
}

//least common multiple
long long lcm(ll a, ll b)
{
    return a / gcd(a, b) * b ;
}

ll factorial(ll n) {
    ll res = 1;
    for (ll i = 1; i <= n; i++) {
        res *= i;
    }
    return res;
}

bool fn_is_prime(ll n) {
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return n != 1;
}

bool isOK(int index, int key, vector<ll>& a) {
    if (a[index] >= key) return true;
    else return false;
}

int binary_search(int key, vector<ll>& a) {
    int ng = -1;
    int ok = a.size();

    while (abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;

        if (isOK(mid, key, a)) ok = mid;
        else ng = mid;
    }
    return ok;
}

struct UnionFind {
    vector<int> r;

    UnionFind(int N) {
        r = vector<int>(N, -1);
    }

    int root(int x) {
        if (r[x] < 0) return x;
        return r[x] = root(r[x]);
    }

    bool unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (r[x] > r[y]) swap(x, y);
        r[x] += r[y];
        r[y] = x;
        return true;
    }

    int size(int x) {
        return -r[root(x)];
    }

    bool same(int x, int y) {
        return root(x) == root(y);
    }
};

//素因数分解
vector<pair<long long, long long> > prime_factorize(long long N) {
    vector<pair<long long, long long> > res;
    for (long long a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        long long ex = 0;
        while (N % a == 0) {
            ++ex;
            N /= a;
        }
        res.push_back({a, ex});
    }
    if (N != 1) res.push_back({N, 1});
    return res;
}
//const auto &pf = prime_factorize(i);
//for (auto p : pf) cout << p.first << " " << p.second;

long long pow(long long x, long long n) {
    long long ret = 1;
    while (n > 0) {
        if (n & 1) ret = ret * x % MOD;  // n の最下位bitが 1 ならば x^(2^i) をかける
        x = x * x % MOD;
        n >>= 1;  // n を1bit 左にずらす
    }
    return ret;
}

int main()
{
    int n, m; cin >> n >> m;
    vector<int> x(n+1), y(m+1);
    cin >> x[0] >> y[0];
    for (int i = 1; i<= n; i++)
        cin >> x[i];
    for (int i = 1; i<= m; i++)
        cin >> y[i];
    sort(ALL(x));
    sort(ALL(y));
    if (x[n] < y[0])
        cout << "No War" << endl;
    else
        cout <<"War" << endl;
    return 0;
}
