#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int add(int x,int y){return x+y<mod?x+y:x+y-mod;}
void ade(int& x,int y){x+=y;if(x>=mod)x-=mod;}
int n;
char s[300300];
int tran[2][9]={{1,3,4,1,6,7,4,8,7},{2,0,5,1,2,5,4,5,7}};
int dp[300300][10];
int main()
{
    scanf("%s",s+1);
    n=strlen(s+1);
    dp[0][0]=1;
    for(int i=0;i<n;++i)
        for(int j=0;j<=8;++j)
        {
            if(s[i+1]!='1')ade(dp[i+1][tran[0][j]],dp[i][j]);
            if(s[i+1]!='0')ade(dp[i+1][tran[1][j]],dp[i][j]);
        }
    printf("%d\n",add(dp[n][2],add(dp[n][5],add(dp[n][7],dp[n][8]))));
    return 0;
}
