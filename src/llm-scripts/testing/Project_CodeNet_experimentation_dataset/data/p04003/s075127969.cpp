#include <bits/stdc++.h>
using namespace std;

int n, m;
int sol[100001];

vector <pair <int, int> > v[100001];
unordered_map <int, int> used[100001];

queue <int> q;

void dfs(int nod, int cul, int val){
    if(nod == n){
        printf("%d", sol[n]);
        exit(0);
    }

    for(auto it : v[nod]){
        if(it.second == cul){
            if(sol[it.first] < val - 1) continue ;
            if(used[it.first].count(cul)) continue ;

            used[it.first][cul] = 1;

            if(sol[it.first] > val){
                sol[it.first] = val;
                q.push(it.first);
            }
            dfs(it.first, cul, val);
        }
    }
}

void dijkstra(){
    memset(sol, 0x3f, sizeof(sol));

    q.push(1);
    sol[1] = 0;

    int ind = 0;
    while(!q.empty()){
        int nod = q.front();
        q.pop();

        for(auto it : v[nod]){
            if(sol[it.first] < sol[nod]) continue ;
            if(used[it.first].count(it.second)) continue ;

            used[it.first][it.second] = 1;
            used[nod][it.second] = 1;
            if(sol[it.first] > sol[nod] + 1){
                sol[it.first] = sol[nod] + 1;
                q.push(it.first);
            }
            dfs(it.first, it.second, sol[nod] + 1);
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m);

    int x, y, c;
    for(int i = 1; i <= m ; ++i){
        scanf("%d%d%d", &x, &y, &c);
        v[x].push_back({y, c});
        v[y].push_back({x, c});
    }

    dijkstra();

    printf("-1");
    return 0;
}
