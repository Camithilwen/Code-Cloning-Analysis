#include <bits/stdc++.h>
using namespace std;
int n,m,ans,li[505][505],h[10005],a,b;
int main(){
    while(1){
    cin >> n >>m;
    if(n==0&&m==0)break;

    for(int i=0;i<m;i++){
        cin >> a >> b;
        li[a][b]=1;
    }

    for(int i=2;i<=n;i++){
        if(li[1][i]==1||li[i][1]==1){
            if(h[i]==0){
                h[i]=1;
                ans++;
            }
                for(int j=2;j<=n;j++){
        if(li[j][i]==1||li[i][j]==1){
            if(h[j]==0){
                h[j]=1;
                ans++;
            }
        }
    }

        }
    }

    cout << ans << endl;
    for(int i=0;i<=n;i++)h[i]=0;
    std::fill(li[0],li[504],0);
    ans=0;
    }

return 0;
}