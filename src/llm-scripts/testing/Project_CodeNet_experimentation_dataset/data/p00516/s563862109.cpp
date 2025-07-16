#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
  int N, M; cin >> N >> M;
  vector<int> cost(N);
  for(int i = 0; i < N; ++i)
    cin >> cost[i];
  vector<int> score(N, 0);
  while(M--) {
    int x; cin >> x;
    for(int i = 0; i < N; ++i) {
      if(cost[i] <= x) {
        score[i]++;
        break;
      }
    }
  }
  int argmax = find(score.begin(), score.end(), *max_element(score.begin(), score.end())) - score.begin();
  cout << argmax + 1 << endl;
}