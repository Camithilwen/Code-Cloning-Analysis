#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


#define SIZE 1005


ll N,M;
int min_dist[SIZE],pre_node[SIZE];
vector<int> G[SIZE];

vector<int> bfs(int start){

	vector<int> ret(N+1);

	for(int i = 0; i < N; i++){

		min_dist[i] = BIG_NUM;
		pre_node[i] = -1;
	}
	min_dist[start] = 0;

	queue<int> Q;
	Q.push(start);

	while(!Q.empty()){

		int node_id = Q.front();
		Q.pop();

		for(int i = 0; i < G[node_id].size(); i++){

			int next = G[node_id][i];
			if(min_dist[next] != BIG_NUM)continue;

			min_dist[next] = min_dist[node_id]+1;
			pre_node[next] = node_id;
			Q.push(next);
		}
	}

	int minimum = BIG_NUM,last_node = -1;

	for(int i = 0; i < N; i++){
		if(i == start)continue;

		for(int k = 0; k < G[i].size(); k++){
			if(G[i][k] == start){
				if(minimum > min_dist[i]){
					minimum = min_dist[i];
					last_node = i;
				}
			}
		}
	}

	if(last_node == -1)return ret;

	int tmp = last_node;
	ret.clear();

	while(tmp != -1){
		ret.push_back(tmp);
		tmp = pre_node[tmp];
	}

	return ret;
}


int main(){

	scanf("%lld %lld",&N,&M);


	int from,to;

	for(ll i = 0; i < M; i++){

		scanf("%d %d",&from,&to);
		from--;
		to--;

		G[from].push_back(to);
	}

	vector<int> ans(N+1);

	for(ll start = 0; start < N; start++){

		vector<int> work = bfs(start);

		if(work.size() < ans.size()){

			ans = work;
		}
	}

	if(ans.size() == N+1){

		printf("-1\n");
		return 0;

	}else{

		printf("%lld\n",ans.size());
		for(int i = 0; i < ans.size(); i++){

			printf("%d\n",ans[i]+1);
		}
	}

	return 0;
}
