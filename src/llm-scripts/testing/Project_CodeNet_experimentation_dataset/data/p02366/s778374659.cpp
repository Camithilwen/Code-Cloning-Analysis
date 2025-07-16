#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
vector< vector<int> > G(100002);
int n_v, n_e;
int prenum[100001], parent[100001], lowest[100001], n_child[100001];
bool is_cut[100001];


void dfs(int u, int f, int t_stamp){
    prenum[u] = t_stamp;
    parent[u] = f;
    lowest[u] = t_stamp;
    int v;
    for(int i=0; i<G[u].size(); i++){
        v = G[u][i];
        if(prenum[v]!=0){
            //this edge is a backedge
            lowest[u] = min(lowest[u], prenum[v]);
        }else{
            n_child[u] += 1;
            dfs(v, u, t_stamp+1);
            lowest[u] = min(lowest[u], lowest[v]);
        }
    }
    return;
}


int main(){
    
    scanf("%d %d", &n_v, &n_e);
    int u, v;
    for(int i=0; i<n_e; i++){
        scanf("%d %d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    memset(prenum, 0, sizeof(prenum));
    memset(parent, 255, sizeof(parent));
    memset(n_child, 0, sizeof(n_child));

    for(int i=0; i<n_v; i++){
        if(parent[i]==-1){
            dfs(i, -1, 1);
        }
    }

    memset(is_cut, 0, sizeof(is_cut));
    for(int i=0; i<n_v; i++){
        if(parent[i]==-1 && n_child[i]>=2)
            is_cut[i] = true;
        else if(prenum[parent[i]] <= lowest[i]){
            if(parent[parent[i]] == -1 && n_child[parent[i]]>=2){
                //the parent is a root
                is_cut[parent[i]] = true;
            }else if(parent[parent[i]] != -1){
                //the parent is not a root
                is_cut[parent[i]] = true;
            }
        }
    }
    
    for(int i=0; i<n_v; i++)
        if(is_cut[i])
            printf("%d\n", i);
    
    return 0;
}
