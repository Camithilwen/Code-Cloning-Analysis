#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

#define x first
#define y second
typedef pair<int,int> pii;
typedef long long ll;
const int MAXN=100005;

int n,m;
int co[MAXN];
bool vis[MAXN];
vector<int> E[MAXN];

bool dfs(int u){
    bool tag=1;
    vis[u]=1;
    for(int i=0;i<(int)E[u].size();i++){
        int v=E[u][i];
        if(vis[v]) tag&=(co[v]!=co[u]);
        else{
            co[v]=co[u]^1;
            tag&=dfs(v);
        }
    }
    return tag;
}

int main(){
    //freopen("squared.in","r",stdin);
    //freopen("squared.out","w",stdout);

    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        E[u].push_back(v);
        E[v].push_back(u);
    }
    int cnt=0,p=0,q=0;
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        if(!E[i].size()) cnt++;
        else{
            if(dfs(i)) q++;
            else p++;
        }
    }
    printf("%lld\n",(ll)cnt*cnt+2ll*cnt*(n-cnt)+p*p+2ll*p*q+2ll*q*q);

    fclose(stdin);
    fclose(stdout);
}
