#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define KK 500
#define MXN 200005
vector<int> v[200005];
int color[200005];
int  dfs(int x,int col){
    color[x]=col;
    int ans=1;
    for(auto it:v[x]){
        if(color[it]==-1){
            ans &= dfs(it,col^1);
        }
        else{
            if(color[it]==col){
                ans=0;
            }
        }
    }
    return ans;
}
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    MEMS(color);
    for(int i=0;i<m;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(y);
        v[y].pb(x);
    }
    LL a=0,b=0,c=0;
    for(int i = 1;i<=n;i++){
        if(color[i]==-1){
            if(v[i].empty())c++;
            else if(dfs(i,0))b++;
            else a++;
        }
    }
    //printf("?%d %d\n",a,b);
    printf("%lld\n",a*(a+b)*2-a*a+b*b*2+c*n*2-c*c);
    return 0;
}
