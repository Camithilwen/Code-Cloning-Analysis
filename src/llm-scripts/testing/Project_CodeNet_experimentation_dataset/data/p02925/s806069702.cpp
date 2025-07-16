#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)(j);i <= (int)(k);i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
#define fix cout<<fixed<<setprecision(20);
const int maxn=(int)2e6+5;
vector<int> E[maxn];
int vis[maxn],ind[maxn],dis[maxn];
int reach[maxn];//longest can reach
inline int id(int x,int y){
    if(x>y)swap(x,y);
    //x--,y--;
    return x+1000*y;
}
int ans=-1;

int dfs(int x){
    //debug(x);
    if(vis[x]==2)return dis[x];
    vis[x]=1;
    for(auto v:E[x]){
        if(vis[v]==1)return -1;
        
        //dis[v]=dis[x]+1;ans=max(ans,dis[v]);
        int ret=dfs(v);
        if(ret==-1)return -1;
        dis[x]=max(dis[x],ret+1);//每个节点存最大值。
        
        
    }
    
    //debug(dis[x]);debug(x);
    
    vis[x]=2;
    return dis[x];
}
int main(){
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    rep(i,1,n){
        int last=0;
        rep(j,1,n)if(i!=j){
            int x;scanf("%d",&x);
            if(last==0){last=id(i,x);continue;}
            E[last].push_back(id(i,x));ind[id(i,x)]++;
            last=id(i,x);
        }
    }
    
    rep(i,1,n)rep(j,1,i-1)if(ind[id(i,j)]==0){
       // memset(vis,0,sizeof(vis));
        E[0].push_back(id(i,j));
        /* dis[id(i,j)]=1;
        if(dfs(id(i,j))==0){cout<<-1<<endl;return 0;};
        //debug("--"); */
    }
    dis[0]=-1;
    int ans=dfs(0);
    
    cout<<ans<<endl;
    

}
/* 
建DAG，判环
topo 可判环（无法进入队列的点），但无法找最长路径
两种环
一种是链环，用
一种是纯环，
3
2 3
1 3
1 2

12-13
12-23
13-23

4
2 3 4
1 3 4
4 1 2
3 1 2

12-13
13-14
12-23
23-24
34-13
13-23
34-14
14-24

 queue<int> Q;
    rep(i,1,n)rep(j,1,i-1)if(ind[id(i,j)]==0)Q.push(id(i,j)),vis[id(i,j)]=1;
    while(!Q.empty()){
        
        int cur=Q.front();Q.pop();
        debug(cur);debug(vis[cur]);
        for(auto v:E[cur]){
            if(vis[v]){continue;}
            //if(vis[v]==1){cout<<-1<<endl;return 0;}
            ind[v]--;
            if(ind[v]==0)Q.push(v),vis[v]=vis[cur]+1,ans=max(ans,vis[v]);
        }
    }
   // rep(i,1,n)rep(j,1,n)if(i!=j)debug(vis[id(i,j)]),debug(i),debug(j);
 */