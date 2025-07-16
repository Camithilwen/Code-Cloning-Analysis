#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

int main()
{
    ll K;
    cin >> K;
    const ll size = 50;
    vector<ll> v(50);

    ll n = K / size;
    ll m = K % size;

    REP(i, size)
    {
        v[i] = size - 1 + n;
        if (i < m)
            v[i]++;
        else
            v[i] -= m;
    }

    cout << size << endl;
    REP(i, size)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}