#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1000000007;
#define REP(i, n) for (ll i = 0; i < (n); i++)
#define REP2(i, x, n) for (ll i = x; i < (n); i++)
const long long INF = numeric_limits<long long>::max();
template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}

string func(ll N, ll Y)
{

    for (ll i = 0; i <= N; ++i)
    {
        ll iAmount = 10000 * i;
        for (ll j = 0; j <= (N-i); ++j)
        {
            ll jAmount = 5000 * j;
            ll k = N - (i + j);
            if ( k < 0 )    continue;
            if (iAmount + jAmount + 1000 * k == Y)
            {

#ifdef SOURCE_TEST
                cout << N << " " << Y << endl;
                cout << i + j + k << endl;
                cout << i * 10000 + j * 5000 + k * 1000 << endl;
#endif
                return to_string(i) + " " + to_string(j) + " " + to_string(k);
            }
        }
    }

    return "-1 -1 -1";
}
int main()
{
    ll N, Y;
    cin >> N >> Y;

    cout << func(N, Y) << endl;

    return 0;
}