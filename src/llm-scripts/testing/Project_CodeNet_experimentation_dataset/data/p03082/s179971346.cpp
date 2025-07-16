#include <bits/stdc++.h>

using namespace std;

long long D[201][100001], MOD=1000000007;

int main()
{
    int n, x, a;
    cin >> n >> x;
    vector <int> A;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        A.push_back(a);
    }
    sort(A.begin(),A.end());
    for (int i = 0; i <= x; i++)
    {
        for (int y = 1; y <= n; y++)
        {
            D[y][i] = 0;
        }
        D[0][i] = i;
    }
    for (int i = 0; i < n; i++)
    {
        for (int y = 0; y <= x; y++)
        {
            D[i+1][y] += D[i][y] * i;
            D[i+1][y] %= MOD;
            D[i+1][y] += D[i][y % A[i]];
            D[i+1][y] %= MOD;
        }
    }
    cout << D[n][x];
    return 0;
}
