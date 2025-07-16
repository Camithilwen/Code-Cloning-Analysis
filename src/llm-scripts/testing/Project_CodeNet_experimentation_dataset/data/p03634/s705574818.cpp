#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



#define SIZE 100005

struct Edge{
	Edge(int arg_to,ll arg_dist){
		to = arg_to;
		dist = arg_dist;
	}
	int to;
	ll dist;
};

vector<Edge> G[SIZE]; //グラフの隣接リスト表現
int N; //ノードの個数
int root; //根ノードの番号
int MAX_LOG_V = 17;
int POW[18];

int parent[18][SIZE];
int depth[SIZE];
ll DIST[SIZE];


//parentとdepthを再帰的に設定
void dfs(int node_id,int parent_id,int d){
	parent[0][node_id] = parent_id;
	depth[node_id] = d;
	for(int i = 0; i < G[node_id].size(); i++){
		if(G[node_id][i].to != parent_id){
			DIST[G[node_id][i].to] = DIST[node_id]+G[node_id][i].dist;
			dfs(G[node_id][i].to,node_id,d+1);
		}
	}
}

//初期化
void init(){
	//parent[0]とdepthを初期化する
	dfs(root,-1,0);
	//parentを初期化する
	for(int k = 0; k + 1 < MAX_LOG_V; k++){
		for(int node_id = 0; node_id < N; node_id++){
			if(parent[k][node_id] < 0)parent[k+1][node_id] = -1; //node_idの2^k上のノードがルートノードより上なら、2^(k+1)上も同様とする
			else{
				parent[k+1][node_id] = parent[k][parent[k][node_id]];
			}
		}
	}
}

//leftとrightのLCAを求める
int lca(int left,int right){
	//leftとrightの深さが同じになるまで親を辿る
	if(depth[left] > depth[right])swap(left,right); //rightの方が深い所にいる

	for(int k = MAX_LOG_V-1; k >= 0; k--){
		if(depth[right]-depth[left] >= POW[k]){ //たとえば深さの差が39なら、32+4+2+1のように、ノードを上方に移動させる
			right = parent[k][right];
		}
	}

	if(left == right)return left;

	for(int k = MAX_LOG_V-1; k >= 0; k--){
		if(parent[k][left] == parent[k][right]){
			//Do nothing
		}else{
			left = parent[k][left];
			right = parent[k][right];
		}
	}
	return parent[0][left]; //最後は、leftの親とrightの親が必ず一致している
}

ll calc_dist(int a,int b){

	return DIST[a]+DIST[b]-2*DIST[lca(a,b)];
}

int main(){

	POW[0] = 1;
	for(int i = 1; i <= 17; i++){

		POW[i] = POW[i-1]*2;
	}

	scanf("%d",&N);

	int from,to;
	ll dist;

	for(int i = 0; i < N-1; i++){
		scanf("%d %d %lld",&from,&to,&dist);
		from--;
		to--;
		G[from].push_back(Edge(to,dist));
		G[to].push_back(Edge(from,dist));
	}

	root = 0;
	DIST[root] = 0;
	init();

	int num_query,K;
	int x,y;

	scanf("%d %d",&num_query,&K);
	K--;

	for(int loop = 0; loop < num_query; loop++){

		scanf("%d %d",&x,&y);
		x--,y--;
		printf("%lld\n",calc_dist(x,K)+calc_dist(K,y));
	}

	return 0;
}
