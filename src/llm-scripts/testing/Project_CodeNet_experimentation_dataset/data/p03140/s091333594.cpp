#include <bits/stdc++.h>
using namespace std;
int main()
  {int i, c{}; string A, B, C; cin >> i >> A >> B >> C;
  while (i--) c += set<char>{A[i], B[i], C[i]}.size() - 1;
  cout << c;}