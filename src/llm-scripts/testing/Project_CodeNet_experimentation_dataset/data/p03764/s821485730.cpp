#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;

int N, M;

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> N >> M;
    ll nsum = 0, nans = 0;
    for (int i = 0; i < N; i++)
    {
        ll x;
        cin >> x;
        nans += (x * i - nsum);
        nans %= MOD;
        nsum = (nsum + x) % MOD;
    }
    ll msum = 0, mans = 0;
    for (int i = 0; i < M; i++)
    {
        ll x;
        cin >> x;
        mans += (x * i - msum);
        mans %= MOD;
        msum = (msum + x) % MOD;
    }

    cout << (nans * mans) % MOD << "\n";
}