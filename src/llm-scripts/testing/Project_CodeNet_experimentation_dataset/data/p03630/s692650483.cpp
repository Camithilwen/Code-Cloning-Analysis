#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N=2200;
int a[N][N],n,m,d[N][N],h[N][N],ans,stack[N][2],top,tt;
char ch;
int main(){
//    freopen("1.in","r",stdin);
    scanf("%d%d\n",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%c",&ch);
            if(ch=='#')a[i][j]=1;
            else a[i][j]=0;
        }scanf("\n");
    } ans=max(n,m);n=n-1;m=m-1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            d[i][j]=1-((a[i][j]+a[i+1][j]+a[i][j+1]+a[i+1][j+1])%2);
        }
    }
   
    for(int i=1;i<=n;i++){
        for(int j=m;j>=1;j--){
            if(d[i][j]==1)h[i][j]=h[i][j+1]+1;
            else h[i][j]=0;
        }
    }
//    for(int i=1;i<=n;i++){
//    	for(int j=1;j<=m;j++)printf("%d ",d[i][j]);
//    	printf("\n");
//    }printf("\n\n");
//    for(int i=1;i<=n;i++){
//    	for(int j=1;j<=m;j++)printf("%d ",h[i][j]);
//    	printf("\n");
//    }
    for(int j=1;j<=m;j++){
        top=0;memset(stack,0,sizeof stack);
        for(int i=1;i<=n+1;i++){
            tt=1;
            while(top>0&&stack[top][0]>=h[i][j]){
                tt+=stack[top][1];
                ans=max(ans,(stack[top][0]+1)*(tt));
                --top;
            }
            ++top;
            stack[top][0]=h[i][j];
            stack[top][1]=tt;
        }
    }
    printf("%d",ans);
    return 0;
}