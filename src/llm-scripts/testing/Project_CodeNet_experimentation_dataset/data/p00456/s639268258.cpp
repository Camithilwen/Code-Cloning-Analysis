#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  vector<int> w, k;
  int w_max = 0;
  int k_max = 0;

  for(int i = 0; i < 10; i++) {
    int W;
    cin >> W;
    w.push_back(W);
  }

  for(int i = 0; i < 10; i++) {
    int K;
    cin >> K;
    k.push_back(K);
  }

  sort(w.begin(), w.end(), greater<int>());
  sort(k.begin(), k.end(), greater<int>());

  for(int i = 0; i < 3; i++) {
    w_max += w[i];
    k_max += k[i];
  }

  cout << w_max	<< ' ' << k_max << endl;

  return 0;
}

