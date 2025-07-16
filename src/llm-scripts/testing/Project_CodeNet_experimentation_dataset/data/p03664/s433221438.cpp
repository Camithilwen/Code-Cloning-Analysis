#include<bits/stdc++.h>
using namespace std;

int dp[1<<15][15];
int g[15][15];
int dis[1<<15];
int n,m,ans=0x3f3f3f3f,sum;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;a--;b--;
        g[a][b]=g[b][a]=c;
        sum+=c;
    }
    for(int s=0;s<1<<n;s++){
        for(int i=0;i<n;i++)if(s>>i&1){
            for(int j=i+1;j<n;j++)if(s>>j&1){
                dis[s]+=g[i][j];
            }
        }
    }
    memset(dp,0x3f,sizeof(dp));
    dp[1][0]=sum;
    for(int s=0;s<1<<n;s++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)if(!(s>>j&1)&&g[i][j]){
                dp[s|(1<<j)][j]=min(dp[s|(1<<j)][j],dp[s][i]-g[i][j]);
            }
            int rs=(s^((1<<n)-1))|(1<<i);
            for(int j=rs;j;j=rs&(j-1)){
                dp[s|j][i]=min(dp[s|j][i],dp[s][i]-dis[j]);
            }
        }
    }
    for(int s=0;s<1<<n;s++){
        ans=min(ans,dp[s][n-1]);
    }
    cout<<ans<<endl;

    return 0;
}