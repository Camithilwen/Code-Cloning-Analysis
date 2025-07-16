#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> V(5);
  for (int i = 0; i < 5; i++)
    cin >> V.at(i);
  sort(V.begin(),V.end());
  int K;
  cin >> K;
  if (V.at(4) - V.at(0) > K)
    cout << ":(" << endl;
  else 
    cout << "Yay!" << endl;
}