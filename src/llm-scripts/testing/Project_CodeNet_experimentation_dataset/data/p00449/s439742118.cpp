#include <cstdio>
#include <utility>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;

const int INF = 1000000000;
int n, k;
vector<P> way[128];

int query(int a, int b);

int main()
{
	while (scanf("%d %d", &n, &k), n != 0){
		for (int i = 1; i <= n; i++) way[i].clear();
		while (k-- > 0){
			int mode;
			scanf("%d", &mode);
			
			if (mode == 0){
				int a, b;
				scanf("%d %d", &a, &b);
				int cost = query(a, b);
				if (cost == INF) puts("-1");
				else printf("%d\n", cost);
			}
			else {
				int c, d, e;
				scanf("%d %d %d", &c, &d, &e);
				way[c].push_back(P(e, d));
				way[d].push_back(P(e, c));
			}
		}
	}
	
	return 0;
}

int query(int a, int b)
{
	static int mini[128];
	for (int i = 1; i <= n; i++) mini[i] = INF;
	
	priority_queue<P> q;
	q.push(P(0, a));
	mini[a] = 0;
	while (!q.empty()){
		P p = q.top(); q.pop();
		
		if (mini[p.second] < p.first) continue;
		for (int i = 0; i < way[p.second].size(); i++){
			P tmp = way[p.second][i];
			
			if (mini[tmp.second] > mini[p.second] + tmp.first){
				mini[tmp.second] = mini[p.second] + tmp.first;
				q.push(tmp);
			}
		}
	}
	
	return mini[b];
}