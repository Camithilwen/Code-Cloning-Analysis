#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <iterator>
#include <iomanip>
using namespace std;


int n;
vector < vector<int> > g;
vector<int> gi;
vector<int> cl;
vector<int> p;
vector<long long> cycle;

bool dfs (int v) {
	if(cl[v] == 2) return false;
  if(cl[v] == 1){
    while(cycle.back() != v){
      p.push_back(cycle.back());
      cycle.pop_back();
    }
    p.push_back(v);
    reverse(p.begin(), p.end());
    return true;
  }
  cl[v] = 1;
  cycle.push_back(v);
  long long u = -1;
  for(int i = 0; i < g[v].size(); ++i){
    long long to = g[v][i];
    if(cl[to] == 1){
      if(u == -1 || gi[to] > gi[u]) u = to;
    }
  }
  if(u != -1){
    dfs(u);
    return true;
  }

  for (int i = 0; i < g[v].size(); i++) {
      int y = g[v][i];
      if (!cl[y]) {
          gi[y] = gi[v] + 1;
          if (dfs(y)) return true;
      }
  }
  cycle.pop_back();
	cl[v] = 2;
	return false;
}

int main() {
	long long m, in, ot;
  cin >> n >> m;
  g.resize(n);
  gi.resize(n);
  for(int i = 0; i < m; ++i){
    cin >> in >> ot;
    in--, ot--;
    g[in].push_back(ot);
  }
	cl.resize(n);
	for (int i = 0; i < n; ++i)
		if (dfs (i))
			break;

	if (p.size() == 0){
		cout << -1;
    return 0;
  }

  vector<long long> q(n, -1);
  for(int i = 0; i < p.size(); ++i)
      q[p[i]] = i;
  
  long long v = p[0];
  vector<long long> res;
  while(true){
    res.push_back(v);
    long long vv = v;
    for(long long a: g[v])
        if(q[a] > q[vv]) vv = a;
    if(vv == v) break;
    v = vv;
  }
  cout << res.size() << endl;
  for(int i = 0; i < res.size(); ++i) cout << res[i] + 1 << endl;
}