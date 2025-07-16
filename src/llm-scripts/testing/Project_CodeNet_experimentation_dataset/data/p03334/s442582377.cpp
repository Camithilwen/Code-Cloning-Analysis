#include<cstdio>
#include<algorithm>
using namespace std;
const int N=602,K=200020;
int n,m,a,b,i,j,d;
bool col[N][N];
void Col(int x){
    d=0;
    while(x%4==0)
        x/=4,d++;
    if(x&1){
        for(i=0;i<m;i++)
            for(j=0;j<m;j++)
                if((i>>d&1)^(j>>d&1))
                    col[i][j]=1;
    }
    else{
        for(i=0;i<m;i++)
            for(j=0;j<m;j++)
                if((i>>d&1))
                    col[i][j]=1;       
    }
}
int main(){
    scanf("%d%d%d",&n,&a,&b);
    m=n*2;
    n*=n;
    Col(a);Col(b);
    for(i=0;i<m;i++)
        for(j=0;j<m;j++)
            if(col[i][j]==0){
                printf("%d %d\n",i,j);
                n--;
                if(!n)return 0;
            }
}