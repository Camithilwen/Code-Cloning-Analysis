#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
#include<map>
using namespace std;

typedef long long ll;
typedef short int sh;

const int inf=0x3f3f3f3f;
const int MAX=1e5+10;
const int mod=1e9+7;

int position[26][MAX],Size[26];
char str[MAX];

void Get_Pos()
{
    memset(Size,0,sizeof(Size));
    for(int i=0;str[i];i++)
    {
        int k=str[i]-'a';
        position[k][Size[k]++]=i;
    }
}

void Solve()
{
    for(int i=0;i<26;i++)
    {
        for(int j=0;j<Size[i]-1;j++)
        {
            for(int k=j+1;k<Size[i];k++)
            {
                if(((k-j+1)<<1)>position[i][k]-position[i][j]+1)
                {
                    printf("%d %d\n",position[i][j]+1,position[i][k]+1);
                    return;
                }
            }
        }
    }
    printf("-1 -1\n");
}

int main()
{
    int n;
    while(scanf("%s",str)!=EOF)
    {
        Get_Pos();
        Solve();
    }
    return 0;
}
