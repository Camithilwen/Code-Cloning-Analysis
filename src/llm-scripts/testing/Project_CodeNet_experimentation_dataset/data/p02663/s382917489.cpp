//
//  nomura_a.cpp
//  learningCplusplus
//
//  Created by Tran Duc Chinh on 2020/04/04.
//  Copyright © 2020 Tran Duc Chinh. All rights reserved.
//

#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
#include <math.h>
using namespace std;
typedef long long ll;
ll mod = 998244353;
ll INF = 1000000007;
#define PI 3.14159265

pair<int, int> dijsktra(int x, char des, int n, vector<pair<int, char> > *adj) {
  priority_queue<pair<pair<int, char>, int> >  q; // (-d, x) current distance to node x is d, using -d to find minimum distance
  bool processed[n];
  pair<int, char> distance[n];
  for (int i=0; i<n; i++) {
    distance[i].first = INF;
    distance[i].second = '0';
    processed[i] = false;
  }
  // find from x
  distance[x] = make_pair(0, '0');
  q.push({distance[x], x});

  while (!q.empty()) {
    int a = q.top().second;
    q.pop();
    if (processed[a]) continue;;
    processed[a] = true;
    for (auto u: adj[a]) {
      int b = u.first; // node b
      char label = u.second;
      int w = 1; // distance from a to b is w
      if (distance[b].first > distance[a].first + w) {
        distance[b] = make_pair(distance[a].first + w, label);
        q.push({{-distance[b].first, label}, b});
      }
    }
  }

  int l = INF;
  int end = 0;
  // std::cout << "distance from " << x << std::endl;
  for (int i = 0; i < n; i++) {
    if (distance[i].first==INF) continue;
    if (distance[i].second == des && distance[i].first < l) {
      l = distance[i].first;
      end = i;
    }
    // std::cout << " distance to " << i << ": " << distance[i] << std::endl;
  }

  return make_pair(l, end);
}


int main() {
  int h1, m1, h2, m2, k;
  cin >> h1 >> m1 >> h2 >> m2 >> k;

  std::cout << h2*60+m2 - (h1*60+m1) - k << std::endl;

  return 0;
}