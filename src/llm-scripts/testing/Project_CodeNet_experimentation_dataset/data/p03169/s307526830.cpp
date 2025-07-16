#include <bits/stdc++.h>
#include <math.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;
using Graph = vector<vector<int>>;
const int MOD = 1000000007;
const int INF_32 = 1LL << 30;
const int64_t INF_64 = 1LL << 60;

template <typename A, size_t N, typename T>
void Fill(A (&array)[N], const T& val)
{
    std::fill((T*)array, (T*)(array + N), val);
}

// dp[c1][c2][c3]: (1個の皿がc1枚，2個の皿がc2枚，3個の皿がc3枚の状態ですべて食べるまでの操作回数の期待値)
double dp[305][305][305];
int N;

double rec(int c1, int c2, int c3)
{
    if (dp[c1][c2][c3] != -1.0)
        return dp[c1][c2][c3];

    double ret = N;
    if (c1 >= 1) {
        ret += c1 * rec(c1 - 1, c2, c3);
    }
    if (c2 >= 1) {
        ret += c2 * rec(c1 + 1, c2 - 1, c3);
    }
    if (c3 >= 1) {
        ret += c3 * rec(c1, c2 + 1, c3 - 1);
    }
    ret /= (c1 + c2 + c3);

    return dp[c1][c2][c3] = ret;
}
int main()
{
    cin >> N;
    Fill(dp, -1.0);
    dp[0][0][0] = 0;
    int c1, c2, c3;
    c1 = c2 = c3 = 0;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        if (a == 1)
            c1++;
        if (a == 2)
            c2++;
        if (a == 3)
            c3++;
    }

    cout << fixed << setprecision(9);
    cout << rec(c1, c2, c3) << endl;

    return 0;
}