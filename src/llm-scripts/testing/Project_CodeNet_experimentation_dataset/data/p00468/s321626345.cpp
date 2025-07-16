#include <cstdio>
#include <vector>

using namespace std;

class Edge{
public:
	int from,to,cost;
	Edge(int f,int t,int c){
		from = f;
		to = t;
		cost = c;
	}
	void swap(){
		int a = from;
		from = to;
		to = a;
	}
};

vector<Edge> edge;

int n,m;
const int INF = 999999999;


int solve(int s){
	int* d = new int[n + 1];
	for(int i=0;i<=n;i++){
		d[i] = INF;
	}
	d[s] = 0;
	
	while(1){
		bool f = true;
		vector<Edge>::iterator it;
		for(it = edge.begin();it<edge.end();it++){
			if(d[it->from] != INF){
				if(d[it->to] > d[it->from] + it->cost){
					d[it->to] = d[it->from] + it->cost;
					f = false;
				} 
			}
		}
		if(f){
			break;
		}
	}
	int ans = 0;
	for(int i=2;i<=n;i++){
		if(d[i] <= 2){
			ans += 1;
		}
	}
	delete[] d;
	return ans;
}

int main(){
	int a,b;
	while(scanf("%d %d",&n,&m) && (n || m)){
		edge.clear();
		for(int i=0;i<m;i++){
			scanf("%d %d",&a,&b);
			edge.push_back( Edge(a,b,1) );
			edge.push_back( Edge(b,a,1) );
		}
		printf("%d\n",solve(1));
	}
}