#include<iostream>

const int INF = 1 << 24, MAX_N = 101;
int n, cost[MAX_N][MAX_N], d[MAX_N], used[MAX_N];

int dijkstra(int s, int g){
	for(int i=1;i<=n;i++){
		d[i] = INF;
		used[i] = false;
	}
	d[s] = 0;

	while(true){
		int v = -1;
		for(int i=1;i<=n;i++){
			if(!used[i] && (v == -1 || d[i] < d[v])){
				v = i;
			}
		}

		if(v == -1)break;
		used[v] = 1;

		for(int i=1;i<=n;i++){
			d[i] = std::min(d[i], d[v] + cost[v][i]);
		}
	}

	return d[g];
}

int main(){
	int k;
	while(std::cin >> n >> k, n){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cost[i][j] = INF;
			}
		}

		while(k--){
			int f, c, d, e;
			std::cin >> f;
			if(f == 0){//注文が入りましたよー
				std::cin >> c >> d;
				int res = dijkstra(c, d);
				if(res == INF){
					std::cout << -1 << std::endl;
				}else{
					std::cout << dijkstra(c, d) << std::endl;
				}
			}else{//運行情報
				std::cin >> c >> d >> e;
				cost[c][d] = std::min(cost[c][d], e);
				cost[d][c] = cost[c][d];
			}
		}
	}
}