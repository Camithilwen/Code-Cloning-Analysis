#include <bits/stdc++.h>

using ll = long long;
using namespace std;
const int INFint = 2e9+1;
const ll INFll = 2e18+1;
ll MOD=1e9+7;


int H,W,T;
string s[10];

int main(){
  int N,M;
  cin>>N>>M;
  vector<int> A(M);
  for(int i(0);i<M;i++){
    cin>>A[i];
  }
  sort(A.rbegin(),A.rend());
  int num[10] = {0,2,5,5,4,5,6,3,7,6};
  map<int,int> ma;
  set<int> honsuu;
  for(int i(0);i<M;i++){
    ma[num[A[i]]] = max(ma[num[A[i]]],A[i]);
    honsuu.insert(num[A[i]]);
  }
  int dp[10001] = {0}; //iを作るのに必要な最大個数
  for(auto m:honsuu){
    dp[m] = 1;
  }
  for(int i(0);i<=N;i++){
    for(auto m:honsuu){
      if(i-m >= 0 && dp[i-m] != 0){
        if(dp[i-m] + 1 >= dp[i]){
          dp[i] = dp[i-m] + 1;
        }
      }
    }
  }

  vector<int> ans;
  int now = N;
  while(dp[now] != 1){
    for(int i(0);i<M;i++){
      if(dp[now] - dp[now-num[A[i]]] == 1){
        ans.push_back(A[i]);
        now = now - num[A[i]];
        break;
      } 
    }
  }
  ans.push_back(ma[now]);

  sort(ans.rbegin(),ans.rend());
  for(int i(0);i<int(ans.size());i++){
    cout << ans[i];
  }
  cout << endl;
  return 0;
}
