#include <bits/stdc++.h>
using namespace std;

#define LIMIT 100001

int N, Q, K;
vector<map<long long, long long>> nodeDis(LIMIT);
vector<long long> kToNode(LIMIT);
vector<bool> check(LIMIT);
vector<unordered_set<int>> vg(LIMIT);

void makeDistance(int k, long long dis){
  check[k] = true;
  kToNode[k] = dis;
  for(auto x: vg[k]){
    if(check[x]){
      continue;
    }
    makeDistance(x, dis + nodeDis[k].at(x));
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;
  cin >> N;
  for(int i = 0; i < N-1; i++){
    long long a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    nodeDis[a][b] = c;
    nodeDis[b][a] = c;
    vg[a].insert(b);
    vg[b].insert(a);
  }
  cin >> Q >> K;
  K--;
  makeDistance(K, 0);
  /*
  for(int i = 0; i < N; i++){
    cout << i << " " << kToNode[i] <<endl;
  }
  //*/
  for(int i = 0; i < Q; i++){
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    cout << kToNode[a] + kToNode[b] <<endl;
  }
}
