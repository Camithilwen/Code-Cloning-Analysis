#include<cstdio>

#include<vector>
#include<map>
using namespace std;

vector<int> G[20000];
vector<int> rG[20000];
int id[20000];
int rid[20000];
int cid[20000];
void enume(int s, int &n) {
    if(id[s]) return;
    id[s] = -1;
    for(int t : G[s])
        enume(t, n);
    id[s] = ++n;
    rid[n] = s;
}
void dfs(int s, int n) {
    if(cid[s]) return;
    cid[s] = n;
    for(int t : rG[s])
        dfs(t, n);
}

int main(void) {
    int m,n;
    scanf("%d%d",&m,&n);
    for(int i=0; i<n; i++) {
        int s,t;
        scanf("%d%d",&s,&t);
        G[s].push_back(t);
        rG[t].push_back(s);
    }

    int k=0;
    for(int i=0; i<m; i++)
        enume(i, k);

    for(int i=m; i; i--)
        dfs(rid[i], i);

    int q;
    scanf("%d",&q);
    for(int i=0; i<q; i++) {
        int u,v;
        scanf("%d%d",&u,&v);
        printf("%d\n",cid[u] == cid[v]);
    }
    return 0;
}