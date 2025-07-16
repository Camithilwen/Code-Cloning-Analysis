#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(){
  string S;
  cin >> S;
  reverse(S.begin(), S.end());
  int N = S.length();
  const long long INF = 1e18;
  vector<long long> dp(2,INF);
  dp[0] = 0;
  for(auto c : S){
    vector<long long> dp_(2,INF);
    for(int i = 0; i < 2; ++i){
      int d = c-'0'+i;
      dp_[1] = min(dp_[1],dp[i]+10-d);
      dp_[d/10] = min(dp_[d/10],dp[i]+d%10);
    }
    swap(dp,dp_);
  }
  ++dp[1];
  cout << min(dp[0],dp[1]) << endl;
}
