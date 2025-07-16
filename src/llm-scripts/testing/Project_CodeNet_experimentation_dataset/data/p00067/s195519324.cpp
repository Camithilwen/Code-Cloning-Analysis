#include<cstdio>
int sima(int x,int y);
char SIMA[14][14];
int main ()
{
    while(scanf("%s",SIMA[1]+1)!=EOF){
        int i,j,ans=0;
        for(i=2;i<13;i++){
            scanf("%s",SIMA[i]+1);
        }
        for(i=1;i<13;i++){
            for(j=1;j<13;j++){
                if(SIMA[j][i]=='1'){
                    ans+=sima(j,i);
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
int sima(int x,int y)
{
    if(SIMA[x][y]=='0' || SIMA[x][y]==0) return 1;
    else SIMA[x][y]='0';
    return sima(x+1,y)*sima(x,y+1)*sima(x-1,y)*sima(x,y-1);
}