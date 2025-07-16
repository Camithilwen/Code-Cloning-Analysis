#include <bits/stdc++.h>
using namespace std;
#define REP(i, init, n) for(int i = (int)(init); i < (int)(n); i++)

#define vi vector<int>
#define vl vector<long>
#define vvi vector<vector<int>>
#define vvl vector<vector<long>>
#define pint pair<int, int>
#define plong pair<long, long>
int INF = (1 << 29);

int main() {
    int N, M;
    cin>> N >> M;
    vvi G(N);
    REP(i, 0, M){
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].emplace_back(b);
    }
    int shortest = N + 1;
    vi ans;
    REP(i, 0, N){
        vi dist(N, -1), prev(N, -1);
        queue<int> que;
        que.push(i);
        dist[i] = 0;
        while(!que.empty()){
           auto cur = que.front(); que.pop();
           for(int x: G[cur]){
               if(dist[x] == -1){
                   dist[x] = dist[cur] + 1;
                   prev[x] = cur;
                   que.push(x);

               }
            }
        }
        REP(j, 0, N){
            if(j == i || dist[j] == -1) continue;
            for(auto nj: G[j]){
                if(nj == i){
                    vi tmp({i+1});
                    int cur = j;
                    while(cur != i) tmp.push_back(cur+1), cur = prev[cur];
                    if(shortest > tmp.size()){
                        shortest = tmp.size();
                        ans = tmp;
                    }
                }
            }
        }
    }
    if(shortest == N+1) cout << -1 << endl;
    else{
        cout << ans.size() << endl;
        for(auto v: ans) cout << v << endl;
    }    
}   