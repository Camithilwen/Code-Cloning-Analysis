#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define Graph vector< vector<int> >
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1000000007;


Graph G(100010);
vector<bool> seen(100010, false);
vector<int> prenum(100010), parent(100010), lowest(100010);

int id;

void dfs(int now, int prev){
    prenum[now] = lowest[now] = id;
    id++;
    seen[now] = true;

    rep(i, G[now].size()){
        int next = G[now][i];
        if(!seen[next]){
            parent[next] = now;
            dfs(next, now);
            lowest[now] = min(lowest[next], lowest[now]);
        }
        else if(next != prev){
            lowest[now] = min(lowest[now], prenum[next]);
        }
    }
}

int main(){
    int N, M;
    cin >> N >> M;
    rep(i, M){
        int s, t;
        cin >> s >> t;
        G[s].push_back(t);
        G[t].push_back(s);
    }

    id = 1;
    dfs(0, -1);

    set<int> ans;
    int root_p = 0;
    for(int i = 1; i < N; i++){
        int p = parent[i];
        if(p == 0) root_p++;
        else if(prenum[p] <= lowest[i]) ans.insert(p);
    }

    if(root_p >= 2) ans.insert(0);

    for(set<int>::iterator it = ans.begin(); it != ans.end(); it++){
        cout << *it << endl;
    }
}
