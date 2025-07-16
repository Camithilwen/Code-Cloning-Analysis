#include <bits/stdc++.h>
using namespace std;
int main()
  {int N, i{}; cin >> N;
  while ((i + 1) * (i + 1) <= N) ++i;
  cout << i * i;}