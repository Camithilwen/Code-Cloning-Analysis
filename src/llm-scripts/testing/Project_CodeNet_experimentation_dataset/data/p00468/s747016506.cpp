#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

void solve(int n,int m){
    int fr[501][501],a,b,ans=0;
    
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            fr[i][j]=100;
    
    
            
    for(int i=0;i<m;i++){
        scanf("%d%d",&a,&b);
        fr[a][b]=1;
        fr[b][a]=1;
    }
    
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                fr[i][j]=min(fr[i][j],fr[i][k]+fr[k][j]);
    
    for(int i=2;i<=n;i++)
        ans+=(fr[1][i]==2 || fr[1][i]==1);
    
    printf("%d\n",ans);
    
    return;
}


int main(){
    int n,m;
    
    while(1){
        scanf("%d%d",&n,&m);
        if(n+m==0) break;
        solve(n,m);
    }
    
    return 0;
}