#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
const int MOD = 1000000007;
const int INF = 1e15;
using Graph = vector<vector<int>>;

signed main() {
  int N, K;
  cin >> N >> K;

  vector<int> V(N);
  for( int i = 0; i < N; i++ ) cin >> V.at(i);


  int ans = 0;
  for( int l = 0; l <= min(N, K); l++){
    for( int r = 0; l+r <= min(N, K); r++ ){
      priority_queue<int, vector<int>, greater<int>> pq;
      int total = 0;
      for( int i = 1; i <= l; i++ ){ //左の宝石を詰める
        pq.push(V.at(i-1));
        total += V.at(i-1);
      }
      for( int i = 1; i <= r; i++ ){ //右の宝石を詰める
        pq.push(V.at(N-i));
        total += V.at(N-i);
      }
      for( int i = 0; i < max(0LL, K-(l+r)); i++ ){
        if( pq.empty() ) break;
        if( pq.top() < 0 ){
          total -= pq.top();
          pq.pop();
        }
      }
      ans = max(ans, total);
    }
  }
  cout << ans << endl;
}
