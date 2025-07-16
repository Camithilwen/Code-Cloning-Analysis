#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(ll N, ll A, ll B, ll C, ll D, ll E) {
  ll bn = min({A, B, C, D, E}); // bottle neck
  cout << ((N - 1) / bn + 5) << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll N, A, B, C, D, E;
  cin >> N >> A >> B >> C >> D >> E;

  solve(N, A, B, C, D, E);

  return 0;
}
