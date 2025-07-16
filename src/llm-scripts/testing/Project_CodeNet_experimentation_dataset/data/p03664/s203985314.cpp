#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>

using namespace std;

int getint()
{
    char ch=getchar();
    int f=1,x=0;
    while(!isdigit(ch)){if(ch=='-') f=-1; ch=getchar();}
    while(isdigit(ch)){x=x*10+ch-'0'; ch=getchar();}
    return f*x;
}

const int N=16;

int n,m;
int map[N][N];
int f[1<<15][N];
int slf[1<<15],ot[1<<15][N];
int tot;

void init()
{
    n=getint(),m=getint();
    for(int i=1; i<=m; i++){
        int u=getint(),v=getint(),w=getint();
        map[u][v]=map[v][u]=w;
        tot+=w;
    }
    for(int s=1; s<(1<<n); s++){
        for(int j=1; j<=n; j++){
            if(s&(1<<(j-1))){
                for(int k=j+1; k<=n; k++){
                    if(!(s&(1<<(k-1)))) continue;
                    slf[s]+=map[j][k];
                }
            }else{
                for(int k=1; k<=n; k++){
                    if(!(s&(1<<(k-1)))) continue;
                    ot[s][j]+=map[j][k];
                }
            }
        }
    }
}

int main()
{
    init();
    memset(f,128,sizeof(f));
    f[1][1]=0;
    for(int s=1; s<(1<<n); s+=2){
        for(int i=1; i<=n; i++){
            if(!(s&(1<<(i-1)))) continue;
            for(int t=s&(s-1); t; t=s&(t-1)){
                if(!(t&1)) continue;
                f[s][i]=max(f[s][i],f[t][i]+slf[s^t]+ot[s^t][i]);
            }
            for(int j=1; j<=n; j++){
                if(i==j || !(s&(1<<(j-1)))) continue;
                if(map[i][j]==0) continue;
                f[s][i]=max(f[s][i],f[s^(1<<(i-1))][j]+map[i][j]);
            }
        }
    }
    printf("%d\n",tot-f[(1<<n)-1][n]);
    return 0;
}
