#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;
int sum1[105][105],sum2[105][105];
int f[2][105][105][105];
char s[105];
int main(){
    int n,i,j,k,o,p,l,m;
    int tx,ty;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
    scanf("%s",s+1);
    for(j=1;j<=m;j++)
    if(s[j]=='E')tx=i,ty=j;
    else if(s[j]=='o')sum1[i][j]=sum1[i][j-1]+1,sum2[i][j]=sum2[i-1][j]+1;
    else sum1[i][j]=sum1[i][j-1],sum2[i][j]=sum2[i-1][j];
    }
    int limu=tx-1,limd=n-tx,liml=ty-1,limr=m-ty;
    for(int u=0;u<=limu;u++)
    for(int d=0;d<=limd;d++)
    for(int l=0;l<=liml;l++)
    for(int r=0;r<=limr;r++){
    int L=max(ty-l,r+1),R=min(ty+r,m-l);
    if(L<=R){
    f[u+1&1][d][l][r]=max(f[u+1&1][d][l][r],f[u&1][d][l][r]+(tx-u-1>=d+1?sum1[tx-u-1][R]-sum1[tx-u-1][L-1]:0));
    f[u&1][d+1][l][r]=max(f[u&1][d+1][l][r],f[u&1][d][l][r]+(tx+d+1<=n-u?sum1[tx+d+1][R]-sum1[tx+d+1][L-1]:0));
    }
    L=max(tx-u,d+1),R=min(tx+d,n-u);
    if(L<=R){
    f[u&1][d][l+1][r]=max(f[u&1][d][l+1][r],f[u&1][d][l][r]+(ty-l-1>=r+1?sum2[R][ty-l-1]-sum2[L-1][ty-l-1]:0));
    f[u&1][d][l][r+1]=max(f[u&1][d][l][r+1],f[u&1][d][l][r]+(ty+r+1<=m-l?sum2[R][ty+r+1]-sum2[L-1][ty+r+1]:0));
    }
    }
    printf("%d\n",f[limu&1][limd][liml][limr]);
    return 0;
}