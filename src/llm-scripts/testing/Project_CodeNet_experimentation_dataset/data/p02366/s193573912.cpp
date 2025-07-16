#include <stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN=1000005;
vector <int> adj[MAXN];
int prof[MAXN],low[MAXN],padre[MAXN],cont,N,M,root;
bool usa[MAXN],ap[MAXN];
void articulationPoints(int v){
    int child=0;
    usa[v]=true;
    low[v]=prof[v]=++cont;
    for (int i=0; i<(int)adj[v].size(); i++){
        int w=adj[v][i];
        if (!usa[w]){
            child++;
            padre[w]=v;
            articulationPoints(w);
            low[v]=min(low[v],low[w]);
            if (padre[v]==-1 && child>1) ap[v]=true;
            if (padre[v]!=-1 && low[w]>=prof[v]) ap[v]=true;
        } else if(w!=padre[v]) low[v]=min(low[v],prof[w]);
    }
}
int main()
{
    scanf("%d%d",&N,&M);
    int a,b;
    for (int i=0; i<M; i++){
        scanf("%d%d",&a,&b);
        adj[a].push_back(b); adj[b].push_back(a);
    }
    fill(padre,padre+N,-1);
    articulationPoints(0);
    for (int i=0; i<N; i++)
        if (ap[i])printf("%d\n",i);
    return 0;
}