#include <bits/stdc++.h>
#define ALL(A) (A).begin(), (A).end()
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); i++)

const ll MOD = 1e9 + 7;
const ll INF = -1 * ((1LL << 63) + 1);
const int inf = -1 * ((1 << 31) + 1);

using namespace std;

int N, M;
vector<int> A, B;

long long solve()
{
    ll res = 1;
    int biggerX_a = 0, biggerX_b = 0; // A,B でxより大きい数値の個数

    for (int x = N * M; x >= 1; x--)
    {
        if (A[biggerX_a] > x)
            return 0;
        if (B[biggerX_b] > x)
            return 0;

        long long tmp = 1;
        if (A[biggerX_a] == x && B[biggerX_b] == x)
        {
            tmp = 1;
            ++biggerX_a, ++biggerX_b;
        }
        else if (A[biggerX_a] == x)
        {
            tmp = biggerX_b;
            ++biggerX_a;
        }
        else if (B[biggerX_b] == x)
        {
            tmp = biggerX_a;
            ++biggerX_b;
        }
        else
        {
            tmp = biggerX_a * biggerX_b - (N * M - x);
            if (tmp <= 0)
                return 0;
        }
        res = (res * tmp) % MOD;
    }
    return res;
}
int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> M;
    A.resize(N+1);
    B.resize(M+1);
    rep(i, N) cin >> A[i];
    rep(i, M) cin >> B[i];
    sort(ALL(A), greater<int>());
    sort(ALL(B), greater<int>());
    cout << solve() << endl;
}