#include<bits/stdc++.h>
using namespace std;
const int maxn=2005;
int T,n,m,a[maxn<<1][maxn<<1],now;
int b[maxn<<1][maxn<<1],c[maxn<<1][maxn<<1],d[maxn<<1][maxn<<1];
bool vis[maxn][maxn];
inline int read(){
    int res=0,f_f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f_f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') res=(res<<3)+(res<<1)-'0'+ch,ch=getchar();
    return res*f_f;
}
inline bool check(int ux,int uy,int fx,int fy){
    if(ux==fx&&uy==fy) return false;
    if(ux<1||ux>n||uy<1||uy>m) return false;
    if(vis[ux][uy]||a[ux][uy]==0) return false;
    return true;
}
inline void dfs(int ux,int uy,int fx,int fy){
    vis[ux][uy]=true;
    if(fx&&fy) b[ux+fx][uy+fy]=1;
    if(check(ux+1,uy,fx,fy)) dfs(ux+1,uy,ux,uy);
    if(check(ux-1,uy,fx,fy)) dfs(ux-1,uy,ux,uy);
    if(check(ux,uy+1,fx,fy)) dfs(ux,uy+1,ux,uy);
    if(check(ux,uy-1,fx,fy)) dfs(ux,uy-1,ux,uy);
}
int main(){
    n=read(),m=read(),T=read();
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            char ch=getchar();
            while(ch!='0'&&ch!='1') ch=getchar();
            a[i][j]=ch-'0';
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if(a[i][j]==1){
                if(!vis[i][j]) dfs(i,j,0,0);
                c[i<<1][j<<1]=1;
            }
        }
    }
    for (int i=1;i<=(n<<1);i++){
        for (int j=1;j<=(m<<1);j++){
            b[i][j]+=b[i][j-1];
            c[i][j]+=c[i][j-1];
        }
    }
    for (int i=1;i<=(n<<1);i++){
        for (int j=1;j<=(m<<1);j++){
            b[i][j]+=b[i-1][j];
            c[i][j]+=c[i-1][j];
        }
    }
    while(T--){
        int fx=read(),fy=read(),tx=read(),ty=read(),ans=0;
        ans+=c[tx<<1][ty<<1]-c[tx<<1][(fy<<1)-1]-c[(fx<<1)-1][ty<<1]+c[(fx<<1)-1][(fy<<1)-1];
        ans-=b[tx<<1][ty<<1]-b[tx<<1][(fy<<1)-1]-b[(fx<<1)-1][ty<<1]+b[(fx<<1)-1][(fy<<1)-1];
        printf("%d\n",ans);
    }
    return 0;
}