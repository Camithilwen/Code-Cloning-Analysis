#include <cstdio>
#include <cstring>
using namespace std;

int map[22][22];
int st[2],gl[2];
int n,m,ans;
int move[4][2]={{0,1},{0,-1},{1,0},{-1,0}};

void dfs(int x,int y,int z){
    if(z>=ans)return;
    for(int i=0;i<4;i++){
        int xx=x,yy=y;
        if(map[x+move[i][0]][y+move[i][1]]!=0&&map[x+move[i][0]][y+move[i][1]]!=3)continue;
        for(int j=0;map[xx][yy]==0;j++){
            xx+=move[i][0];
            yy+=move[i][1];
            if(map[xx][yy]==3){
                ans=z;
                return;
            }
        }
        if(map[xx][yy]==1){
            map[xx][yy]=0;
            dfs(xx-move[i][0],yy-move[i][1],z+1);
            map[xx][yy]=1;
        }
    }
}
int main(){
    scanf("%d%d",&m,&n);
    while(n*m!=0){
        for(int i=0;i<=n+1;i++){
            map[i][0]=-1;
            map[i][m+1]=-1;
        }
        for(int i=0;i<=m+1;i++){
            map[0][i]=-1;
            map[n+1][i]=-1;
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++){
                scanf("%d",&map[i][j]);
                if(map[i][j]==2){
                    st[0]=i;st[1]=j;
                    map[i][j]=0;
                }
            }
        ans=11;
        dfs(st[0],st[1],1);
        if(ans>10)ans=-1;
        printf("%d\n",ans);
        scanf("%d%d",&m,&n);
    }
    
    return 0;
}