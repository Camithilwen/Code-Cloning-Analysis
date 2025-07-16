#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
const int N=205,M=1e5+5;
const int mod=1e9+7;
int dp[N][M],a[N],n,X;
int dfs(int u,int x) {
    if(!u) return x%a[u];
    if(dp[u][x]!=-1) return dp[u][x];
    return dp[u][x]=(dfs(u-1,x%a[u])+1LL*u*dfs(u-1,x))%mod;
}
int main() {
    scanf("%d%d",&n,&X);
    for(int i=0;i<n;i++) scanf("%d",a+i);
    std::sort(a,a+n);
    memset(dp,-1,sizeof(dp));
    printf("%d\n",dfs(n-1,X));
    return 0;
}
