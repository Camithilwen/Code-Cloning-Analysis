#include<bits/stdc++.h>
using namespace std;

int main() {
  using LL = long long;

  int N;
  cin >> N;
  vector<LL> A(N);
  for(auto& i: A) cin >> i;

  const LL NG = -1e18;
  vector<map<int, LL>> memo(N);
  function<LL(int,int)> dfs = [&](int i, int n) {
    if(n == 0) return 0ll;
    if(N <= i) return NG;
    if(N < i+2*n-1) return NG;
    if(memo[i][n]) return memo[i][n];
    return memo[i][n] = max(dfs(i+1, n), A[i]+dfs(i+2, n-1));
  };

  cout << dfs(0, N/2) << endl;
}
