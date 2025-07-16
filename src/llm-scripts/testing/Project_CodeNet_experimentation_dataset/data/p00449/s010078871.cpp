#include<iostream>
#include<queue>
#include<vector>
#include<functional>
using namespace std;
typedef pair<int,int> P;	//現在コスト、島の番号

int n,k;
int cost[101][101];
int Dijkstra(int left,int get){
	int done[101] = {0};	//確定後のコストを格納
	int mincost[101];
	for(int i = 0;i < 101;i++)
		mincost[i] = 500000000;
	priority_queue<P,vector<P>,greater<P> >que;
	P edge;
	que.push(P(0,left));
	while(done[get] == 0 && !que.empty()){
		edge.first = que.top().first;
		edge.second = que.top().second;
		que.pop();
		//何度も同じ頂点にコストが更新される(pushされる)ことがあるので、確定後に残りのケースが作動しないようにする。
		if(done[edge.second])
			continue;
		//確定後のコスト
		done[edge.second] = edge.first;
		//確定した頂点から枝を伸ばす(今までの最小を記録することで重複探索を減らす)
		for(int i = 1;i <= n;i++){
			if(cost[edge.second][i] > 0 && done[i] == 0 && mincost[i] > edge.first+cost[edge.second][i]){
				mincost[i] = edge.first+cost[edge.second][i];
				que.push(P(edge.first+cost[edge.second][i],i));
			}
		}
	}
	if(done[get])
		return done[get];
	return -1;
}
int mincost[50000],mcor = 0;
int main(){
	int i,j,a,b,c,d;
	while(true){
		cin >> n >> k;
		if(n == 0 && k == 0)
			break;
		for(i = 0;i < 101;i++){
			for(j = 0;j < 101;j++){
				cost[i][j] = 0;
			}
		}
		for(i = 0;i < k;i++){
			cin >> a;
			if(a == 0){
				cin >> b >> c;
				mincost[mcor] = Dijkstra(b,c);
				mcor++;
			}
			else{
				cin >> b >> c >> d;
				if(cost[b][c] == 0 || cost[b][c] > d)
					cost[b][c] = d;
				if(cost[c][b] == 0 || cost[c][b] > d)
					cost[c][b] = d;
			}
		}
	}
	for(i = 0;i < mcor;i++){
		cout << mincost[i] << endl;
	}
	return 0;
}