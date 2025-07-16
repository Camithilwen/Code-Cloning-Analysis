#include <bits/stdc++.h>
using namespace std;
int main()
  {int N, K; cin >> N >> K;
  int L[N]; for (int &l : L) cin >> l; sort(L, L + N);
  cout << accumulate(L + N - K, L + N, 0);}