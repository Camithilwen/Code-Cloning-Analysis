#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int N=2e5+10;
int n,m;
int col[N];
vector <int> g[N];
int cnt[4];
bool flag=0;
void dfs(int x,int c){
    col[x]=c;cnt[c]++;
    for(int i=0;i<g[x].size();i++){
        if(!col[g[x][i]]) dfs(g[x][i],3-c);
        if(col[g[x][i]]==col[x]) flag=1; 
    }
}
int main(){ 
    scanf("%d%d",&n,&m);
    for(int i=1,x,y;i<=m;i++){
        scanf("%d%d",&x,&y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for(int i=1;i<=n;i++)
        if(!col[i]) dfs(i,1);
    if(flag) printf("%lld\n",(long long)n*(n-1)/2-m);
    else {
        printf("%lld\n",(long long)cnt[1]*cnt[2]-m);
    }
    return 0;
}