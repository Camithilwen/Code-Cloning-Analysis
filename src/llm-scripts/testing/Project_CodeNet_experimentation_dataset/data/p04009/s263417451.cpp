#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

#define x first
#define y second
typedef pair<int,int> pii;
const int MAXN=105;

int n,m;
int sumr[MAXN][MAXN],sumc[MAXN][MAXN],f[MAXN][MAXN][MAXN];
char s[MAXN][MAXN];
pii ed;

int main(){
    //freopen("robot.in","r",stdin);
    //freopen("robot.out","w",stdout);

    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%s",s[i]+1);
        for(int j=1;j<=m;j++){
            sumr[i][j]=sumr[i-1][j];
            sumc[i][j]=sumc[i][j-1];
            if(s[i][j]=='o') sumr[i][j]++,sumc[i][j]++;
            if(s[i][j]=='E') ed.x=i,ed.y=j;
        }
    }
    int ans=0;
    memset(f,-1,sizeof f);
    f[0][0][0]=0;
    int U=ed.x-1,D=n-ed.x,L=ed.y-1,R=m-ed.y;
    for(int l=0;l<=L;l++)
        for(int r=0;r<=R;r++)
            for(int u=0;u<=U;u++)
                for(int d=0;d<=D;d++){
                    if(f[r][u][d]==-1) continue;
                    ans=max(ans,f[r][u][d]);
                    int left=max(r+1,ed.y-l),right=min(m-l,ed.y+r);
                    int up=max(d+1,ed.x-u),down=min(n-u,ed.x+d);
                    if(left>right||up>down) continue;
                    int temp;
                    if(u<U-d){
                        temp=sumc[ed.x-u-1][right]-sumc[ed.x-u-1][left-1];
                        f[r][u+1][d]=max(f[r][u+1][d],f[r][u][d]+temp);
                    }
                    if(d<D-u){
                        temp=sumc[ed.x+d+1][right]-sumc[ed.x+d+1][left-1];
                        f[r][u][d+1]=max(f[r][u][d+1],f[r][u][d]+temp);
                    }
                    if(r<R-l){
                        temp=sumr[down][ed.y+r+1]-sumr[up-1][ed.y+r+1];
                        f[r+1][u][d]=max(f[r+1][u][d],f[r][u][d]+temp);
                    }
                    if(l<L-r){
                        temp=sumr[down][ed.y-l-1]-sumr[up-1][ed.y-l-1];
                        f[r][u][d]=max(f[r][u][d],f[r][u][d]+temp);
                    }
                }
    printf("%d",ans);

    fclose(stdin);
    fclose(stdout);
}
