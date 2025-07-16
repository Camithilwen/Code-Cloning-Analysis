#include<bits/stdc++.h>
#define ll long long
using namespace std;

int dp[85][85][40000]={};
int grid[85][85];

int main(){
    int h,w;
    cin>>h>>w;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>grid[i][j];
        }
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            int k;
            cin>>k;
            grid[i][j]=abs(grid[i][j]-k);
        }
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            int x=grid[i][j];
            if(i==0&&j==0){
                dp[i][j][20000+x]=1;
                dp[i][j][20000-x]=1;
                continue;
            }
            if(i==0){
                for(int k=1000;k<39000;k++){
                    dp[i][j][k]+=max(dp[i][j-1][k+x],0);
                    dp[i][j][k]+=max(dp[i][j-1][k-x],0);
                    dp[i][j][k]=min(1,dp[i][j][k]);
                }
                continue;
            }
            if(j==0){
                for(int k=1000;k<39000;k++){
                    dp[i][j][k]+=max(dp[i-1][j][k+x],0);
                    dp[i][j][k]+=max(dp[i-1][j][k-x],0);
                    dp[i][j][k]=min(1,dp[i][j][k]);
                }
                continue;
            }

            for(int k=1000;k<39000;k++){
                dp[i][j][k]+=max(dp[i][j-1][k+x],0);
                dp[i][j][k]+=max(dp[i][j-1][k-x],0);
                dp[i][j][k]=min(1,dp[i][j][k]);
            }
            for(int k=1000;k<39000;k++){
                dp[i][j][k]+=max(dp[i-1][j][k+x],0);
                dp[i][j][k]+=max(dp[i-1][j][k-x],0);
                dp[i][j][k]=min(1,dp[i][j][k]);
            }
        }
    }

    int ans=50000;
    for(int i=0;i<40000;i++){
        if(dp[h-1][w-1][i]>0){
            ans=min(ans,abs(i-20000));
        }
    }
    cout<<ans<<endl;
}