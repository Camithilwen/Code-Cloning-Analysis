#include<iostream>

using namespace std;

int main(){
  int n, i;
  while(cin >> n && n != 0) {
    int dp[n+1] = {};
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    for(i = 4; i <= n; i++) {
      dp[i] = dp[i-3] + dp[i-2] + dp[i-1];
    }

    i = 0;
    
    while(dp[n] > 0) {
      dp[n]-=3650;
      i++;
    }
    
    cout <<  i  << endl;
  }
  
  return 0;
}