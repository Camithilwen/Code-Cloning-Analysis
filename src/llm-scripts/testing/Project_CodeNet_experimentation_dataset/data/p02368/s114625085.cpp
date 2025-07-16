#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void dfs1(vector<vector<pair<int,int>>> &graph, vector<int> &num, vector<int> &used, int node, int &con){
        
        if(used[node]) return ;
        
        used[node] = true;
        
        for(pair<int,int> next : graph[node]){
                dfs1(graph, num, used, next.first, con);
        }
        
        num[con++] = node;
}

void dfs2(vector<vector<pair<int,int>>> &graph, vector<int> &scc, vector<int> &used, int node, int same){
        
        if(used[node]) return ;
        
        used[node] = true;
        
        for(pair<int,int> next : graph[node]){
                dfs2(graph, scc, used, next.first, same);
        }
        
        scc[node] = same;
}

void Strongly_Connected_Components(vector<vector<pair<int,int>>> &graph, vector<int> &scc){
        vector<int>  used(graph.size()), num(graph.size());
        vector<vector<pair<int,int>>> graph2(graph.size());
        int con = 0;
        
        scc.resize(graph.size());
        
        for(int i = 0; i < graph.size(); i++){
                dfs1(graph, num, used, i, con);
        }
        
        for(int i = 0; i < graph.size(); i++){
                for(int j = 0; j < graph[i].size(); j++){
                        graph2[graph[i][j].first].push_back(make_pair(i, graph[i][j].second));
                }
        }
        
        used.clear();
        used.resize(graph.size());
        
        for(int i = (int)graph.size()-1, same = 0; i >= 0; i--){
                if(!used[num[i]]){
                        dfs2(graph2, scc, used, num[i], same);
                        same++;
                }
        }
        
}

signed main(){
        int V, E;
        int Q;
        vector<int> scc;
        vector<vector<pair<int,int>>> graph;
        
        cin>>V>>E;
        
        graph.resize(V);
        
        for(int i = 0; i < E; i++){
                int s, t;
                
                cin>>s>>t;
                
                graph[s].push_back(make_pair(t,0));
        }
        
        Strongly_Connected_Components(graph, scc);
        
        cin>>Q;
        
        for(int i = 0; i < Q; i++){
                int u, v;
                
                cin>>u>>v;
                
                cout<<(scc[u] == scc[v])<<endl;
        }
        
        return 0;
}


