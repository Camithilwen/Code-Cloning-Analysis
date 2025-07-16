#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>

#define INF (1e+9)
#define LLINF (1e+18)
#define LL long long

#define MAX_V 100

using namespace std;

typedef struct edge{
	int to;
	int cost;
	edge(){

	}
	edge(int _to,int _cost){
		to = _to;
		cost = _cost;
	}
	bool operator<(const edge &a)const{
		if(cost == a.cost) return to > a.to;
		return cost > a.cost;	//for asc
	}
}edge;


int cost[MAX_V + 1];
vector<edge> G[MAX_V + 1];
priority_queue<edge> pque;


int V;
int K;


void solve(int s){
	for(int i = 1;i <= V;i++){
		cost[i] = INF;
	}

	pque.push(edge(s,0));

	while(!pque.empty()){
		edge e = pque.top();pque.pop();
		if(cost[e.to] != INF) continue;
		cost[e.to] = e.cost;
		for(int i = 0;i < G[e.to].size();i++){
			int _to = G[e.to][i].to;
			int _cost = e.cost + G[e.to][i].cost;
			pque.push(edge(_to,_cost));
		}
	}

	return ;
}

int main (void){

	while(true){
		scanf("%d%d",&V,&K);
		if(V == 0 && K == 0) break;
		int query;
		int _u,_v,_cost;
		for(int i = 0;i < K;i++){
			scanf("%d",&query);
			if(query){
				scanf("%d%d%d",&_u,&_v,&_cost);
				G[_u].push_back(edge(_v,_cost));
				G[_v].push_back(edge(_u,_cost));
			}
			else {
				scanf("%d%d",&_u,&_v);
				solve(_u);
				if(cost[_v] == INF)puts("-1");
				else printf("%d\n",cost[_v]);
			}
		}
		for(int i = 1;i <= V;i++) G[i].clear();
	}

	return 0;
}