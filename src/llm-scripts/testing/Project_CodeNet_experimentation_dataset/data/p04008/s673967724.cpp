#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> P;

vector<int> G[100000];
int depth[100000];
bool ok[100000];
P depth_pair[100000];

void dfs_depth(int v, int d){
    depth[v] = d;
    for(int i = 0; i < G[v].size(); i++){
        if(depth[G[v][i]] == -1) dfs_depth(G[v][i], d+1);
    }
}

void dfs_ok(int v){
    ok[v] = true;
    for(int i = 0; i < G[v].size(); i++){
        if(depth[G[v][i]] > depth[v] && !ok[G[v][i]]) dfs_ok(G[v][i]);
    }
}

int main(){
    int N, K;
    cin >> N >> K;
    int ans = 0;
    for(int i = 0; i < N; i++){
        depth[i] = -1;
        int a;
        cin >> a;
        a--;
        if(i == 0){
            if(a != 0) ans++;
        }else{
            G[a].push_back(i);
            G[i].push_back(a);
        }
    }
    //cout << ans << endl;
    dfs_depth(0, 0);
    for(int i = 0; i < N; i++) depth_pair[i] = P(depth[i], i);
    sort(depth_pair, depth_pair+N, greater<P>());
    for(int i = 0; i < N; i++){
        if(depth_pair[i].first <= K) break;
        if(!ok[depth_pair[i].second]){
            ans++;
            int cur = depth_pair[i].second;
            //cout << depth_pair[i].second << endl;
            //K-1個上まで
            for(int j = 0; j < K-1; j++){
                for(int k = 0; k < G[cur].size(); k++){
                    if(depth[G[cur][k]] < depth[cur]){
                        cur = G[cur][k];
                        break;
                    }
                }
            }
            dfs_ok(cur);
        }
    }
    cout << ans << endl;
}