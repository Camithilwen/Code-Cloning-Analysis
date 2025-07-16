#include <bits/stdc++.h>
using namespace std;

int main() {
  string N;
  cin >> N;

  if (N.size() == 3) reverse(N.begin(), N.end());
  cout << N << endl;
}