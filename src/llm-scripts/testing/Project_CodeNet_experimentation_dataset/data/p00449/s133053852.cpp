#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <climits>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <vector>
#include <queue>
#include <bitset>
#include <string>
using namespace std;

#define REP(i,n) for(int i=0; i<n; i++)
#define RPA(i,s,e) for(int i=s; i<=e; i++)
#define RPD(i,s,e) for(int i=s; i>=e; i--)
#define PB(a) push_back(a)
#define MP(i,s) make_pair(i,s)
#define ALL(a) (a).begin(), (a).end()
#define PRT(a) cout << (a) << endl

typedef pair<int,int> P;

const int INF = 1000000009;
const int MAX_V = 101;
struct edge { int to, cost; };
vector<edge> G[MAX_V];

int N,K,L;
int f,t,c;
int dist[MAX_V];

void add_edge(int from, int to, int cost) {
	edge e1 = { to, cost };
	edge e2 = { from, cost };
	G[from].PB(e1);
	G[to].PB(e2);
}

int dijkstra(int from, int to) {
	fill(dist, dist+MAX_V, INF);
	priority_queue<P, vector<P>, greater<P> > que;
	dist[from] = 0;
	que.push(MP(0, from));
	while(!que.empty()) {
		P p = que.top();
		que.pop();

		int v = p.second;
		if(dist[v] < p.first) continue;

		REP(i,G[v].size()) {
			edge& e = G[v][i];
			if(dist[e.to] > dist[v] + e.cost) {
				dist[e.to] = dist[v] + e.cost;
				que.push(MP(dist[e.to], e.to));
			}
		}
	}

	return dist[to] == INF ? -1 : dist[to];
}

void coding() {
	while(scanf("%d%d", &N, &K) != EOF) {
		REP(i,N) G[i].clear();
		REP(i,K) {
			scanf("%d", &L);
			if(L == 0) {
				scanf("%d%d", &f, &t);
				f--; t--;
				printf("%d\n", dijkstra(f, t));
			} else if(L == 1) {
				scanf("%d%d%d", &f, &t, &c);
				f--; t--;
				add_edge(f, t, c);
			} else {
				PRT("unknown");
			}
		}
	}
}

// #define _LOCAL_TEST

int main() {
#ifdef _LOCAL_TEST
	clock_t startTime = clock();
	freopen("a.in", "r", stdin);
#endif

	coding();

#ifdef _LOCAL_TEST
	clock_t elapsedTime = clock() - startTime;
	cout << endl;
	cout << (elapsedTime / 1000.0) << " sec elapsed." << endl;
	cout << "This is local test" << endl;
	cout << "Do not forget to comment out _LOCAL_TEST" << endl << endl;
#endif
}