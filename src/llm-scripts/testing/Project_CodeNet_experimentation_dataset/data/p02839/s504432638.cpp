//#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <deque>
#include <map>
using namespace std;

#define ii pair <int, int>
#define lli long long
#define pb push_back
#define X first
#define Y second

const int Mod = 1E9 + 7;
const int Inf = 1E9 + 7;
const int N = 80 + 10;
const int M = 80 * 160 + 1;

int n, m, a[N][N], b[N][N];
bool F[N][N][M][2];

void Input()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) cin >> a[i][j];
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) cin >> b[i][j];
}

void Solve()
{
    memset(F, 0, sizeof(F));
    int Sum = a[1][1] - b[1][1];
    Sum = abs(Sum);
    F[1][1][Sum][1] = F[1][1][Sum][0] = true;


    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
    for (int k = 0; k < M; k++)
    for (int l = 0; l <= 1; l++){
        if (F[i][j][k][l] == true) {
            int sign = 1;
            if (l == 0) sign = -1;
            int k1 = k * sign + a[i + 1][j] - b[i + 1][j];
            int k2 = k * sign + a[i][j + 1] - b[i][j + 1];

            if (k1 >= 0) F[i + 1][j][k1][1] = true;
            else F[i + 1][j][-k1][0] = true;

            if (k2 >= 0) F[i][j + 1][k2][1] = true;
            else F[i][j + 1][-k2][0] = true;
            ///
            k1 = k * sign - a[i + 1][j] + b[i + 1][j];
            k2 = k * sign - a[i][j + 1] + b[i][j + 1];

            if (k1 >= 0) F[i + 1][j][k1][1] = true;
            else F[i + 1][j][-k1][0] = true;

            if (k2 >= 0) F[i][j + 1][k2][1] = true;
            else F[i][j + 1][-k2][0] = true;

        }
    }

    for (int k = 0; k < M; k++) if (F[n][m][k][0] == true || F[n][m][k][1] == true) {
        cout << k << " ";
        return ;
    }
}

#define task "test"
int main()
{
    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int testcase = 1;
    /// cin >> testcase;
    while (testcase--) {
        Input();
        Solve();
    }
}


