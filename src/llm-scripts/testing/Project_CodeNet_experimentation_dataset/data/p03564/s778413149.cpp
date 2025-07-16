#include <bits/stdc++.h>
using namespace std;
int main()
  {int N, K, n{1}; cin >> N >> K;
  while (N--) n += min(n, K);
  cout << n;}