#include <bits/stdc++.h>
using namespace std;

vector<bool> visited, exhausted;
stack<int> cycle;
int closing_point;

void DFS(const vector<vector<int>> &graph, int v, int previous_v){
    visited[v] = true;
    cycle.push(v);

    for(auto next_v : graph[v]){
        if(next_v == previous_v) continue;

        if(exhausted[next_v] == false){
            if(visited[next_v] == true)  closing_point = next_v;
            if(visited[next_v] == false) DFS(graph, next_v, v);

            if(closing_point != -1) return;
        }
    }

    // if
    // 1. no next_v (dead-end) or
    // 2. all next_v lead to dead-end
    cycle.pop();
    exhausted[v] = true;
}

int main(){
    int V, E;
    cin >> V >> E;

    vector<vector<int>> graph(V);
    for(int i=0; i<E; i++){
        int s, t;
        cin >> s >> t;
        s -= 1;
        t -= 1;
        graph[s].push_back(t);
        // graph[t].push_back(s);
    }

    for(int i=0; i<V; i++){
        visited.assign(V, false);
        exhausted.assign(V, false);
        while(cycle.empty() == false){
            cycle.pop();
        }
        closing_point = -1;
        DFS(graph, i, -1);

        vector<int> prov_ans;
        while(cycle.empty() == false){
            int t = cycle.top(); cycle.pop();
            prov_ans.push_back(t);
            if(t == closing_point) break;
        }

        int nvc = prov_ans.size();// number of vertices in the cycle
        if(nvc != 0){
            reverse(prov_ans.begin(),prov_ans.end());
            map<int, int> vc;
            for(int j=0; j<nvc; j++){
                vc[prov_ans[j]] = j;
            }

            bool flag = false;
            int start = 0, end = nvc-1;
            for(int j=1; j<nvc; j++){
                for(auto adjacent_v : graph[prov_ans[j]]){
                    // since directed
                    if(j <  nvc - 1 && adjacent_v == prov_ans[j+1]) continue;
                    if(j == nvc - 1 && adjacent_v == prov_ans[0])   continue;

                    if(vc.count(adjacent_v)){
                        //cout << prov_ans[j] << " -- " << adjacent_v << endl;
                        flag = true;
                        end = j;
                        start = max(start, vc[adjacent_v]);
                    }
                }
                if(flag == true){
                    cout << end - start + 1 << endl;
                    for(int k=start; k<=end; k++){
                        cout << prov_ans[k] + 1 << endl;
                    }
                    return 0;
                }
            }
            cout << end - start + 1 << endl;
            for(int k=start; k<=end; k++){
                cout << prov_ans[k] + 1 << endl;
            }
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}