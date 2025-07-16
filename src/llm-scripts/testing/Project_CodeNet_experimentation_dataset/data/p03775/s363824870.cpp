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
constexpr ll TEN(int n) { return (n==0) ? 1 : 10*TEN(n-1); }

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

bool is_prime(ll n) {
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return n != 1;
}

vector<vector<int>> d(10, vector<int>(10, 1000000));

void warshall_floyd(int n) {
    rep(k,n) rep(i,n) {
        rep(j,n) {
            d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
        }
    }
}
int main()
{
    ll n; cin >> n;
    vector<ll> a;
    int ans = 20;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            a.push_back(i);
            a.push_back(n/i);
        }
    }
    for (int i = 0; i < a.size(); i += 2) {
        int tmp1 = to_string(a[i]).length();
        int tmp2 = to_string(a[i+1]).length();
        ans = min(ans, max(tmp1, tmp2));
    }
    cout << ans << endl;

    return 0;
}
