#include<iostream>
#include<vector>
#include<queue>
using namespace std;

#define INF (1LL << 63)
struct edge{
    size_t to;
    size_t weight;
};

vector<size_t> dijkstra(vector<vector<edge>>& Graph, int& startPoint, int& vertexNum){
    vector<size_t> minimumWeight(vertexNum,INF);
    priority_queue<vector<pair<size_t,size_t>>, vector<pair<size_t,size_t>>, greater<pair<size_t,size_t>>> priorityQueue;
    priorityQueue.push({0,startPoint});
    minimumWeight[startPoint] = 0;
    while(!priorityQueue.empty()){
        pair<size_t,size_t> tmp = priorityQueue.top();
        edge Edge;
        Edge.to = tmp.second;
        Edge.weight = tmp.first;
        priorityQueue.pop();
        if(minimumWeight[Edge.to] < Edge.weight) continue;
        for(edge& edge : Graph[Edge.to]){
            if(minimumWeight[edge.to] < minimumWeight[Edge.to] + edge.weight) continue;
            minimumWeight[edge.to] = minimumWeight[Edge.to] + edge.weight;
            priorityQueue.push({minimumWeight[edge.to],edge.to});
        }
    }
    return minimumWeight;
}


int main(){
    int N,M;
    while(cin >> N >> M, N&&M){
        vector<vector<edge>> costGraph(M);
        vector<vector<edge>> timeGraph(M);

        for(int i = 0;i < N; i++){
            size_t a,b,c,t;
            cin >> a >> b >> c >> t;
            a--,b--;

            costGraph[a].push_back({b,c});
            costGraph[b].push_back({a,c});

            timeGraph[a].push_back({b,t});
            timeGraph[b].push_back({a,t});
        }

        int k;
        cin >> k;
        for(int j=0;j<k;j++){
            int p,q,r;
            cin >> p >> q >> r;
            p--, q--;
            vector<size_t> res;
            if(r == 0) res = dijkstra(costGraph, p, M);
            else res = dijkstra(timeGraph, p, M);   

            cout << res[q] << endl;        
        }
    }
}
