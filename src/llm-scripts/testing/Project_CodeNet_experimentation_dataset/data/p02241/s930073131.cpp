#include <algorithm>
#include <iostream>
using namespace std;

int P[10010];
void init(int N){
  for (int i=0; i<N; i++) P[i] = i;
}
int root (int a){
  if (P[a] == a) return a;
  else {
    P[a] = root(P[a]);
    return P[a];
  }
}
bool is_same_set(int a, int b){
  return root(a) == root(b);
}
void unite(int a, int b){
  P[root(a)] = root(b);
}

int main(){
  int N;
  cin >> N;
  pair <int, int> edge[10010];
  for (int i=0; i<N; i++){
    for (int j=0; j<N; j++){
      cin >> edge[i*N+j].first;
      edge[i*N+j].second = i*N+j;
    }
  }
  sort(edge, edge+N*N);
  init(N);
  int ans = 0;
  int b = 0;
  for (int k=0; k<N*N; k++){
    while(edge[k].first < 0) k++;
    int i = edge[k].second / N;
    int j = edge[k].second % N;
    if (is_same_set(i,j)){}
    else{
      unite(i,j);
      ans += edge[k].first;
    }
  }
  cout << ans << endl;
}