#include <bits/stdc++.h>
using namespace std;
#define ll long long

#define maxn 1005

int n;
char ans[maxn][maxn];
char s3[5][5] = {"aa.", "..b", "..b"};
char s4[5][5] = {"aabd", "ccbd", "deff", "degg"};
char s5[6][6] = {"aaeff", "b.e.g", "b.jjg", ".ccih", "dd.ih"};
char s6[8][8] = {"aabcc.", "b.b..d", "baa..d", "cc.aab", "..db.b", "..dbaa"};
char s7[8][8] = {"a.aa.a.", "a....ac", ".dd.bbc", "b..b..a", "b..b..a", ".ee.ccb", "cc.aa.b"};

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            ans[i][j] = '.';
    if (n == 2)
    {
        printf("-1\n");
        return 0;
    }
    if (n == 7)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                printf("%c", s7[i][j]);
            printf("\n");
        }
        return 0;
    }
    if (n == 3)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                printf("%c", s3[i][j]);
            printf("\n");
        }
        return 0;
    }
    if (n == 6)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                printf("%c", s6[i][j]);
            printf("\n");
        }
        return 0;
    }
    if (n == 11)
    {
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 6; j++)
                ans[i][j] = s6[i][j];
        }
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
                ans[6 + i][6 + j] = s5[i][j];
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                printf("%c", ans[i][j]);
            printf("\n");
        }
        return 0;
    }
    int x, y;
    // 4x+5y=n
    for (int i = 0; i * 4 <= n; i++)
    {
        if ((n - 4 * i) % 5 == 0)
        {
            x = i;
            y = (n - 4 * i) / 5;
        }
    }
    //printf("%d %d\n", x, y);
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 4; k++)
                ans[i * 4 + j][i * 4 + k] = s4[j][k];
        }
    }
    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            for (int k = 0; k < 5; k++)
                ans[4 * x + i * 5 + j][4 * x + i * 5 + k] = s5[j][k];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%c", ans[i][j]);
        printf("\n");
    }
    return 0;
}