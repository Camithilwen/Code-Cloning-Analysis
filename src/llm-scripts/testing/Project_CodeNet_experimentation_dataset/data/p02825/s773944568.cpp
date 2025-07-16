#include <bits/stdc++.h>
using namespace std;
typedef long long llong;
#define rep(i, n) for (int i = 0; i < n; ++i)
char gf[1200][1200];
int main()
{
    int n;
    scanf("%d", &n);
    if (n < 3)
        printf("-1");
    else if (n == 3)
        printf("z..\nz..\n.zz");
    else if (n == 7)
        printf("a..bbaa\na...abb\n.az.a..\n.az..a.\n..azza.\nbba...a\naabb..a");
    else
    {
        int rn = n;
        if (n & 1)
            rn -= 5;
        for (int i = 0; i < rn; i += 2)
            gf[i][i] = gf[i + 1][i] = 'a',
            gf[i][i + 1] = gf[i + 1][i + 1] = 'b';
        for (int i = 2; i < rn; i += 2)
            gf[i][i - 2] = gf[i][i - 1] = 'c',
            gf[i + 1][i - 2] = gf[i + 1][i - 1] = 'd';
        gf[0][rn - 2] = gf[0][rn - 1] = 'c';
        gf[1][rn - 2] = gf[1][rn - 1] = 'd';
        if (n & 1)
            strcpy(&gf[rn][rn], "aabba"),
            strcpy(&gf[rn + 1][rn], "bz..a"),
            strcpy(&gf[rn + 2][rn], "bz..b"),
            strcpy(&gf[rn + 3][rn], "a.zzb"),
            strcpy(&gf[rn + 4][rn], "abbaa");
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
                if (gf[i][j])
                    printf("%c", gf[i][j]);
                else
                    printf(".");
            printf("\n");
        }
    }
    return 0;
}