#include<bits/stdc++.h>

using namespace std;

int ans, X, Y, N, M, dp[2][102][102][102], s[102][102];
char sir[102][102];

void U (int &x, int val) {if (val > x) x = val;}
int get_sub (int a1, int b1, int a2, int b2)
{
    if (a1 < 1) a1 = 1;
    if (b1 < 1) b1 = 1;
    if (a2 > N) a2 = N;
    if (b2 > M) b2 = M;
    if (a1 > a2 || b1 > b2) return 0;
    return s[a2][b2] - s[a1 - 1][b2] - s[a2][b1 - 1] + s[a1 - 1][b1 - 1];
}
int sum_lin (int i, int j1, int j2) {return get_sub (i, j1, i, j2);}
int sum_col (int j, int i1, int i2) {return get_sub (i1, j, i2, j);}
int intersect (int a1, int b1, int a2, int b2, int &st, int &dr) {st = max (a1, a2), dr = min (b1, b2);}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d\n", &N, &M);
for (int i=1; i<=N; i++)
    scanf ("%s\n", sir[i] + 1);
for (int i=1; i<=N; i++)
    for (int j=1; j<=M; j++)
    {
        s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + (sir[i][j] == 'o');
        if (sir[i][j] == 'E') X = i, Y = j;
    }
for (int l=0; l<Y; l++)
{
    for (int r=0; r<=M - Y; r++)
        for (int u=0; u<X; u++)
            for (int d=0; d<=N - X; d++)
                dp[(l & 1) ^ 1][r][u][d] = 0;
    for (int r=0; r<=M - Y; r++)
        for (int u=0; u<X; u++)
            for (int d=0; d<=N - X; d++)
            {
                int curr = dp[l & 1][r][u][d], st, dr;
                if (curr > ans) ans = curr;
                intersect (r + 1, M - l, Y - l, Y + r, st, dr);
                U (dp[l & 1][r][u][d + 1], curr + (X + d + 1 <= N - u) * sum_lin (X + d + 1, st, dr));
                U (dp[l & 1][r][u + 1][d], curr + (X - u - 1 >= 1 + d) * sum_lin (X - u - 1, st, dr));
                intersect (d + 1 , N - u, X - u, X + d, st, dr);
                U (dp[l & 1][r + 1][u][d], curr + (Y + r + 1 <= M - l) * sum_col (Y + r + 1, st, dr));
                U (dp[(l & 1) ^ 1][r][u][d], curr + (Y - l - 1 >= 1 + r) * sum_col (Y - l - 1, st, dr));
            }
}
printf ("%d\n", ans);
return 0;
}
