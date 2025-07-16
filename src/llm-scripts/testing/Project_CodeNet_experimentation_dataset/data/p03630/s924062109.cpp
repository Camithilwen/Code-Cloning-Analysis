#include<cstdio>
#include<algorithm>
using namespace std;
const int N=2010;
int n,m,ans,a[N][N],up[N],L[N],R[N];
char s[N];
int main(){
    scanf("%d%d",&n,&m);ans=max(n,m);
    for(int i=1;i<=n;i++){
        scanf("%s",s+1);
        for(int j=1;j<=m;j++)
            a[i][j]=s[j]=='.'?0:1;
    }
    --n;--m;
    for(int i=1;i<=m;i++)L[i]=1,R[i]=m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            a[i][j]^=a[i+1][j]^a[i][j+1]^a[i+1][j+1];
    for(int i=1;i<=n;i++){
        int l=0,r=m+1;
        for(int j=1;j<=m;j++)
            if(a[i][j])up[j]=0,l=j,L[j]=1;
            else ++up[j],L[j]=max(L[j],l+1);
        for(int j=m;j;j--)
            if(a[i][j])r=j,R[j]=m;
            else {
                R[j]=min(R[j],r-1);
                ans=max((R[j]-L[j]+2)*(up[j]+1),ans);
            }
    }
    printf("%d\n",ans);
}