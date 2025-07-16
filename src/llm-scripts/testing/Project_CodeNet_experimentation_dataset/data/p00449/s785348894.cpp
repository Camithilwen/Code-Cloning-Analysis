#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#define int long long
using namespace std;
int cost[101][101];
int d[101];
bool used[101];
int V,k,o,a,b,c,di,e,ans;
void dij(int s){
    fill(d,d+101,10000000);
    fill(used,used+101,false);
    d[s]=0;
    while(true){
        int v=-1;
        for(int u=0;u<V;u++){
            if(!used[u]&&(v==-1||d[u]<d[v]))v=u;
        }
        if(v==-1)break;
        used[v]=true;
        for(int u=0;u<V;u++){
            d[u]=min(d[u],d[v]+cost[v][u]);
        }
    }
}
signed main(){
    for(;;){
        cin>>V>>k;
        if(V==0&&k==0)break;
        fill(cost[0],cost[0]+101*101,10000000);
        for(int i=0;i<k;i++){
            cin>>o;
            if(o==1){
                cin>>c>>di>>e;
                cost[c-1][di-1]=min(cost[c-1][di-1],e);
                cost[di-1][c-1]=min(cost[di-1][c-1],e);
            }
            if(o==0){
                cin>>a>>b;
                dij(a-1);
                if(d[b-1]==10000000)cout<<-1<<endl;
                else cout<<d[b-1]<<endl;
            }
        }
    }
    return 0;
}