#include <iostream>
#include <bitset>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <cmath>
#include <regex>
#include <iomanip>
#include <climits>
#include <utility>
#include <queue>
using namespace std;
using ll = long long int;
using dd = long double;
const ll MOD = 1e9 + 7;
const dd PI = 3.1415926435;

class UnionFind
{
public:
    UnionFind(int N) : par(N)
    {
        for (ll i = 0; i < N; i++)
        {
            par[i] = i;
        }
    }

    int root(int x)
    {
        if (par[x] == x)
            return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y)
    {
        int rx = root(x);
        int ry = root(y);
        if (rx == ry)
            return;
        par[rx] = ry;
    }

    bool same(int x, int y)
    {
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }

private:
    vector<int> par;
};

ll gcd(ll a, ll b)
{
    if (a % b == 0)
    {
        return b;
    }
    return gcd(b, a % b);
}

ll fact(ll n)
{
    if (n == 0)
    {
        return 1;
    }
    if (n == 1)
    {
        return 1;
    }
    return n * fact(n - 1) % MOD;
}

ll pow_fast(ll n, ll k)
{
    if (k == 0)
    {
        return 1;
    }
    if (k == 1)
    {
        return n;
    }

    if (k % 2 == 0)
    {
        ll tmp = pow_fast(n, k / 2LL);
        return tmp * tmp % MOD;
    }
    else
    {
        ll tmp = pow_fast(n, k / 2LL);
        tmp *= tmp;
        tmp %= MOD;
        return tmp * n % MOD;
    }
}

map<ll, ll> sosuu(ll n)
{
    map<ll, ll> res;
    for (ll i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            res[i] += 1;
            n /= i;
        }
    }
    if (n != 1)
    {
        res[n] += 1;
    }
    return res;
}

struct Dish{
    ll time;
    ll taste;
};
int main()
{
    ll N, T;
    cin >> N >> T;
    vector<Dish> dishes(N + 1);
    for (ll i = 0; i < N; i++)
    {
        ll ai, bi;
        cin >> ai >> bi;
        Dish d = {ai, bi};
        dishes[i + 1] = d;
    }

    vector<vector<ll>> DP1(N + 1, vector<ll>(T + 1, 0));
    vector<vector<ll>> DP2(N + 1, vector<ll>(T + 1, 0));

    // DP1 => 1-i 種類までの料理の中で j 分以内で最大の満腹度
    for (ll i = 1; i <= N; i++)
    {
        for (ll j = 0; j <= T; j++)
        {
            if (j < dishes[i].time) {
                DP1[i][j] = DP1[i - 1][j];
                continue;
            }
            DP1[i][j] = max(DP1[i - 1][j], dishes[i].taste + DP1[i - 1][j - dishes[i].time]);
        }
    }
    for (ll i = 1; i <= N; i++)
    {
        for (ll j = 0; j <= T; j++)
        {
            if (j < dishes[N - i + 1].time) { 
                DP2[i][j] = DP2[i - 1][j];
                continue;
            }
            DP2[i][j] = max(DP2[i - 1][j], dishes[N - i + 1].taste + DP2[i - 1][j - dishes[N - i + 1].time]);
        }
    }

    ll ans = 0;    
    for (ll i = 1; i <= N; i++)
    {
        for (ll j = 0; j <= T - 1; j++)
        {
            ans = max(ans, DP1[i - 1][j] + DP2[N - i][T - 1 - j] + dishes[i].taste);
        }
    }
    cout << ans << endl;
}