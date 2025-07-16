#include<bits/stdc++.h>
using namespace std;

int H,W;
short fid[110][110] = {0};
short dp[110][110][110][110] = {0};
int x,y;

short sum(int y1,int x1,int y2,int x2)
{
    if(y1 > y2 || x1 > x2)return 0;
    return fid[y1 - 1][x1 - 1] - fid[y1 - 1][x2] - fid[y2][x1 - 1] + fid[y2][x2];
}

int main()
{
    scanf("%d%d",&H,&W);
    for(int i = 1; i <= H; i++)for(int j = 1; j <= W; j++)
    {
        char c;
        scanf(" %c",&c);
        if(c == 'o')fid[i][j] = 1;
        if(c == 'E')x = j,y = i;
    }

    for(int i = 1; i <= H; i++)for(int j = 1; j <= W; j++)fid[i][j] += fid[i - 1][j];
    for(int i = 1; i <= H; i++)for(int j = 1; j <= W; j++)fid[i][j] += fid[i][j - 1];

    for(int i = 0; i < y; i++)
    {
        for(int j = 0; j <= H - y; j++)
        {
            for(int k = 0; k < x; k++)
            {
                for(int l = 0; l <= W - x; l++)
                {
                    if(i + j + k + l == 0)continue;
                    if(i)
                    {
                        dp[i][j][k][l] = max(dp[i][j][k][l],
                        (short)(dp[i - 1][j][k][l] + sum(max(y - i,j + 1),max(x - k,l + 1),y - i,min(x + l,W - k))));
                    }
                    if(j)
                    {
                        dp[i][j][k][l] = max(dp[i][j][k][l],
                        (short)(dp[i][j - 1][k][l] + sum(y + j,max(x - k,l + 1),min(y + j,H - i),min(x + l,W - k))));
                    }
                    if(k)
                    {
                        dp[i][j][k][l] = max(dp[i][j][k][l],
                        (short)(dp[i][j][k - 1][l] + sum(max(y - i,j + 1),max(x - k,l + 1),min(y + j,H - i),x - k)));
                    }
                    if(l)
                    {
                        dp[i][j][k][l] = max(dp[i][j][k][l],
                        (short)(dp[i][j][k][l - 1] + sum(max(y - i,j + 1),x + l,min(y + j,H - i),min(x + l,W - k))));
                    }
                }
            }
        }
    }
    printf("%d\n",dp[y - 1][H - y][x - 1][W - x]);
    return 0;
}
