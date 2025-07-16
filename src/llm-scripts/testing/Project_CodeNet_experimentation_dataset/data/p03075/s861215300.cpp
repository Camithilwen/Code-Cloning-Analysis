#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> V(5);
  for (int i=0; i<5; i++) {
    cin >> V[i];
  }
  int k;
  cin >> k;
  if (V[4]-V[0]>k) {
    cout << ":(" << endl;
  }
  else {
    cout << "Yay!" << endl;
  }
}
