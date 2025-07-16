#include <bits/stdc++.h>
using namespace std;

double dp[305][305][305];

int main(){
  int n, a;
  cin >> n;
  vector<int> sushi(3);
  for(int i=0; i<n; ++i){
    cin >> a;
    ++sushi[a-1];
  }
  int sum1 = sushi[2];
  int sum2 = sushi[1] + sushi[2];
  int sum3 = sushi[0] + sushi[1] + sushi[2];
  for(int k=0; k <= sum1; ++k) for(int j=0; j+k <= sum2; ++j) for(int i=0; i+j+k <=sum3; ++i){
    if(i>0) dp[i][j][k] += (dp[i-1][j][k] +(double)n/(i+j+k)) *i /(i+j+k);
    if(j>0) dp[i][j][k] += (dp[i+1][j-1][k] +(double)n/(i+j+k)) *j /(i+j+k);
    if(k>0) dp[i][j][k] += (dp[i][j+1][k-1] +(double)n/(i+j+k)) *k /(i+j+k);
  }
  printf("%.15f\n",dp[sushi[0]][sushi[1]][sushi[2]]);
}