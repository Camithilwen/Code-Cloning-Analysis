#include <bits/stdc++.h>
using namespace std;

int n, m;
int mem[4010][6010][3];

void add(int &x, int v)
{
    x = (x + v) % m;
}

int main()
{
    scanf("%d%d", &n, &m);

    mem[1][1][0] = 1;
    for(int i = 1; i <= 2 * n; i++)
    {
        for(int j = 1; j <= 3 * n - 1; j++)
        {
            for(int k = 0; k < 3; k++)
            {
                if(k == 0)
                    add(mem[i][j + 1][0], mem[i][j][k]);
                else
                    add(mem[i + 1][j + 1][0], mem[i][j][k]);

                if(k < 2)
                    add(mem[i][j + 1][k + 1], 1LL * mem[i][j][k] * j % m);
            }
        }
    }
    
    int r = 0;
    for(int i = 1; i <= n; i++)
        for(int k = 0; k < 3; k++)
            add(r, mem[i][3 * n][k]);
    add(r, mem[n + 1][3 * n][0]);

    printf("%d\n", r);
    return 0;
}
