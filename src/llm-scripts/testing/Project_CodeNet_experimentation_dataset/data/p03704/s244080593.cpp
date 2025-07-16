#include<queue>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MN 21001
#define int long long
using namespace std;

int read_p,read_ca;
inline int read(){
    read_p=0;read_ca=getchar();
    while(read_ca<'0'||read_ca>'9') read_ca=getchar();
    while(read_ca>='0'&&read_ca<='9') read_p=read_p*10+read_ca-48,read_ca=getchar();
    return read_p;
}
const int MOD=1e9+7;
int n,a[MN],B[MN],x,mmh=0,mm[20][20][2][2];
inline int M(int x){return x<0?x+10:x;}
inline void work(int p,int n,int a,int b){
    if (mm[p][n][a][b]!=-1) {mmh+=mm[p][n][a][b];return;}
    int u=mmh;
    if (p+p-1==n){
        if (a==0&&b==0) mmh+=10*(B[p]==0);else
        if (a==1&&b==1) mmh+=10*(B[p]==9);
        return;
    }
    if (p+p-1>n){
        mmh+=a==b;
        return;
    }
    for (int i=p==1;i<=9;i++)
    for (int j=0;j<=9;j++)
    if (M(i-j-b)==B[p]&&(a==(j<i)||j==i)&&(M(j-i)==B[n+1-p]||M(j-1-i)==B[n+1-p])){
        if (a){
            if (j==i&&B[n+1-p]==0) continue;
            work(p+1,n,M(j-1-i)==B[n+1-p],i-b-j<0);
        }else{
            if (j==i&&B[n+1-p]==9) continue;
            work(p+1,n,M(j-1-i)==B[n+1-p],i-b-j<0);
        }
    }
    mm[p][n][a][b]=mmh-u;
}
signed main(){
    int i,j,k;
    x=n=read();
    if (n%9) return puts("0"),0;
    for (k=1;k<=10&&x;k++) B[k]=x%10,x/=10;k--;
    for (int i=k;i<=18;i++) memset(mm,-1,sizeof(mm)),work(1,i,0,0);
    printf("%lld\n",mmh);
}
