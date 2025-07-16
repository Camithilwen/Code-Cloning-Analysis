#include<bits/stdc++.h>
using namespace std;
int n,m,a[310][310];
int c[310],u[310],ans;

int main(){
    scanf("%d %d",&n,&m);
    ans=n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(int x=1;x<=m;x++){
    	memset(u,0,sizeof(u));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(c[a[i][j]]) continue;
                u[a[i][j]]++;
                break;
            }
        }
        int maxn=0,p;
        for(int i=1;i<=m;i++){
            if(u[i]>maxn)  maxn=u[i],p=i;
        }
        c[p]=1;
        ans=min(ans,maxn);
    }
    printf("%d\n",ans);
    
    return 0;
}