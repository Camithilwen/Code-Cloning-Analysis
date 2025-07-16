#include<bits/stdc++.h>
using namespace std;
const int N=102;
int gi() {
    int x=0,o=1;char ch=getchar();
    while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
    if(ch=='-') o=-1,ch=getchar();
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*o;
}
int n,m,x,y,ans=0,sx[N][N],sy[N][N];
short f[N][N][N][N];
int main() {
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) {
            char ch=getchar();
            while(ch!='.'&&ch!='o'&&ch!='E') ch=getchar();
            sx[i][j]=sy[i][j]=(ch=='o');
            sx[i][j]+=sx[i][j-1];sy[i][j]+=sy[i-1][j];
            if(ch=='E') x=i,y=j;
        }
    for(int i=x;i;i--)
        for(int j=y;j;j--)
            for(int k=x;k<=n;k++)
                for(int l=y;l<=m;l++) {
                    ans=max(ans,(int)f[i][j][k][l]);
                    if(i>1&&k+1<x+i) f[i-1][j][k][l]=max((int)f[i-1][j][k][l],f[i][j][k][l]+max(0,sx[i-1][min(l,m-y+j)]-sx[i-1][max(j-1,l-y)]));
                    if(k<n&&x+k<n+i) f[i][j][k+1][l]=max((int)f[i][j][k+1][l],f[i][j][k][l]+max(0,sx[k+1][min(l,m-y+j)]-sx[k+1][max(j-1,l-y)]));
                    if(j>1&&l+1<y+j) f[i][j-1][k][l]=max((int)f[i][j-1][k][l],f[i][j][k][l]+max(0,sy[min(k,n-x+i)][j-1]-sy[max(i-1,k-x)][j-1]));
                    if(l<m&&y+l<m+j) f[i][j][k][l+1]=max((int)f[i][j][k][l+1],f[i][j][k][l]+max(0,sy[min(k,n-x+i)][l+1]-sy[max(i-1,k-x)][l+1]));
                }
    printf("%d\n",ans);
    return 0;
}
//orzgzy
//鸡贼明年进队超稳
