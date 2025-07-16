#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
const int MOD = 1000000007;
const int INF = 1e18;
using Graph = vector<vector<int>>;

signed main() {
  int N, T;
  cin >> N >> T;
  vector<pair<int, int>> dish(N);
  for( int i = 0; i < N; i++ ){
    int A, B;
    cin >> A >> B;
    dish[i] = make_pair(A, B);
  }

  sort(dish.begin(), dish.end());


  vector<int> dp(10000);
  dp[0] = 0;
  for( int i = 0; i < N; i++ ){
    for( int j = T-1; j >= 0;  j-- ){
      int A = dish[i].first;
      int B = dish[i].second;
      dp[j+A] = max(dp[j+A], dp[j]+B);
    }
  }

  int ans = 0;
  for( int i = 0; i < 10000; i++ ){
    ans = max(ans, dp[i]);
  }
  cout << ans << endl;


}
