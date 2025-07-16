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
using namespace std;
using ll = long long;
using PII = pair<int, int>;
using PLL = pair<ll, ll>;
const int INF = numeric_limits<int>::max();
const ll INFL = numeric_limits<ll>::max();


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

int main()
{
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    const int MAX = 100001;

    vector<int> odd_hist(MAX, 0), even_hist(MAX, 0);
    rep(i,n) {
        if (i & 1) odd_hist[a[i]]++;
        else even_hist[a[i]]++;
    }

    vector<PII> odd, even;
    rep(i,MAX) {
        odd.push_back(PII(odd_hist[i], i));
        even.push_back(PII(even_hist[i], i));
    }
    sort(odd.begin(), odd.end(), greater<PII>());
    sort(even.begin(), even.end(), greater<PII>());

    if (odd[0].second != even[0].second) {
        cout << n - (odd[0].first + even[0].first) << endl;
    }
    else {
        cout << n - max(odd[0].first + even[1].first,
                odd[1].first + even[0].first) << endl;
    }

    return 0;
}
