#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
//#include "MyMath.h"
//#include "MyDisjointset.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
#include <stdio.h>
using namespace std;
typedef pair<int, int> P;
const int INF = 1000000000;
struct edge {
	int from, to, cost;
};
int main() {
	int v, e, r; cin >> v >> e >> r;
	vector <edge> ed;
	for (int i = 0; i < e; i++) {
		int s, t, co; cin >> s >> t >> co;
		edge e1; e1.from = s; e1.to = t; e1.cost = co;
		ed.push_back(e1);
	}
	int *d = new int[v];
	fill(d, d + v, INF);
	d[r] = 0;
	while (true) {
		bool  update = false;
		for (int i = 0; i < ed.size(); i++) {
			edge ex = ed[i];
			if (d[ed[i].from] != INF && d[ed[i].to] > d[ed[i].from] + ex.cost) {
				d[ed[i].to] = d[ed[i].from] + ex.cost;
				//cout << "from " << d[ed[i].from] << " to " << d[ed[i].to] << " cost " << ex.cost << endl;
				update = true;
			}
		}
		if (!update)  break; 
	}
	for (int i = 0; i < v; i++) {
		if (d[i] == INF) cout << "INF" << endl;
		else  cout << d[i] << endl;
	}
	delete[] d;
	return 0;
}