#include<bits/stdc++.h>
using namespace std;

char str[100100];

int ty[4][100100];

main()
{
    int n;
    scanf("%d",&n);
    scanf("%s",str);
    ty[0][0]=ty[0][1]=ty[1][0]=ty[2][1]=0; // sheep
    ty[1][1]=ty[2][0]=ty[3][0]=ty[3][1]=1; // wolf
    for(int i=1;i<n;i++)
    {
        if(str[i]=='o')
        {
            for(int j=0;j<4;j++)
            {
                if(ty[j][i]==0)ty[j][i+1]=ty[j][i-1];
                else ty[j][i+1]=(ty[j][i-1]+1)%2;
            }
        }
        else
        {
            for(int j=0;j<4;j++)
            {
                if(ty[j][i]==1)ty[j][i+1]=ty[j][i-1];
                else ty[j][i+1]=(ty[j][i-1]+1)%2;
            }
        }
    }
    for(int i=0;i<4;i++)
    {
        if(str[0]=='o')
        {
            if(ty[i][0]==0&&ty[i][n-1]==ty[i][1]&&ty[i][0]==ty[i][n])
            {
                //printf("%d %d\n",ty[i][n-1],ty[i][1]);
                for(int j=0;j<n;j++)printf("%s",ty[i][j]==0?"S":"W");
                return 0;
            }
            if(ty[i][0]==1&&ty[i][n-1]!=ty[i][1]&&ty[i][0]==ty[i][n])
            {
                for(int j=0;j<n;j++)printf("%s",ty[i][j]==0?"S":"W");
                return 0;
            }
        }
        else
        {
            if(ty[i][0]==1&&ty[i][n-1]==ty[i][1]&&ty[i][0]==ty[i][n])
            {
                for(int j=0;j<n;j++)printf("%s",ty[i][j]==0?"S":"W");
                return 0;
            }
            if(ty[i][0]==0&&ty[i][n-1]!=ty[i][1]&&ty[i][0]==ty[i][n])
            {
                for(int j=0;j<n;j++)printf("%s",ty[i][j]==0?"S":"W");
                return 0;
            }
        }
    }
    printf("-1");
}
