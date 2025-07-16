#include <bits/stdc++.h>
#include <string>
//#define local
#ifdef local
#include "dbg-macro/dbg.h"
#endif
#define ll long long
#define pi (acos(-1))
#define rep(i, n) for (unsigned long long i = 0; i < (unsigned long long)(n); ++i)
using namespace std;
std::vector<unsigned ll> genprimevec(const unsigned ll N);


int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> wavec(n, 0);
    vector<bool> aced(n, false);
    ll ac = 0;
    ll wa = 0;
    while (m--)
    {
        int p;
        string s;
        cin >> p >> s;
        if (aced[p]) { continue; }
        if (s == "AC")
        {
            aced[p] = true;
            ++ac;
            wa += wavec[p];
        }
        else
        {
            wavec[p]++; // WA
        }
    }

    cout << ac << ' ' << wa << endl;
    return 0;
}

ll extgcd(ll a, ll b, ll &x, ll &y)
{
    if (b == 0)
    {
        x = 1, y = 0;
        return a;
    }
    ll d = extgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}


std::vector<unsigned ll> genprimevec(const unsigned ll N)
{
    std::vector<bool> is_prime(N + 1);
    for (unsigned ll i = 0; i <= N; i++) { is_prime[i] = true; }
    std::vector<unsigned ll> P;
    for (unsigned ll i = 2; i <= N; i++)
    {
        if (is_prime[i])
        {
            for (unsigned ll j = 2 * i; j <= N; j += i) { is_prime[j] = false; }
            P.emplace_back(i);
        }
    }
    return P;
}
