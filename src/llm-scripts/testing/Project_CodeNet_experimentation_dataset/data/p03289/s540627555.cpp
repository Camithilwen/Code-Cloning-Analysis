#include <iostream>
#include <bitset>
#include <vector>
#include <string>
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

int main()
{
    string S;
    cin >> S;
    bool ok = false;
    bool ok2 = false;
    bool ok3 = true;

    if (S[0] == 'A') {
        ok = true;
    }

    for (ll i = 2; i < S.size() - 1; i++)
    {
        if (ok2 && S[i] == 'C') {
            ok2 = false;
            break;
        }
        if (S[i] == 'C') {
            ok2 = true;
        }
    }

    for (ll i = 0; i < S.size(); i++)
    {
        if (i == 0 || S[i] == 'C') {
            continue;
        }
        if ('a' > S[i] || S[i] > 'z') {
            ok3 = false;
        }
    }
    if (ok && ok2 && ok3) {
        cout << "AC" << endl;
    } else {
        cout << "WA" << endl;
    }
    
}