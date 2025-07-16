#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
#define ENDL "\n"
typedef long long int llint;
int intinput()
{
  int x;
  scanf("%d", &x);
  return x;
}

llint dp[300][300 * 300 + 1];

void code()
{
  llint MOD = 998244353;
  int N = intinput();
  vector<int> a(N);
  for (int i = 0; i < N; i++)
  {
    a[i] = intinput();
  }
  llint S = 0;
  for (int i = 0; i < N; i++)
  {
    S += a[i];
  }
  // すべての配置パターン
  llint ans = 1;
  for (int i = 0; i < N; i++)
  {
    ans *= 3;
    ans %= MOD;
  }
  // R, G, Bの長さがS/2を超えるパターンを除外
  // dp[i個目まで使う][Rの長さ] = パターン数
  dp[0][0] = 2; //Gに使うかBに使うか
  dp[0][a[0]] = 1;
  for (int i = 1; i < N; i++)
  {
    for (int s = 0; s <= S; s++)
    {
      dp[i][s] = 2 * dp[i - 1][s] + (s - a[i] >= 0 ? dp[i - 1][s - a[i]] : 0);
      dp[i][s] %= MOD;
    }
  }
  for (int s = (S + 1) / 2; s <= S; s++)
  {
    ans -= dp[N - 1][s] * 3;
    while (ans < 0)
    {
      ans += MOD;
    }
  }
  // R==G==S/2の場合が引かれすぎている
  // dp[i個目まで使う][Rの長さ] = パターン数　・・・今度はRとGのみに使い、R==G==S/2のパターン数を計算する
  if((S&1)==0){ //合計が偶数でないと起こり得ない
    for (int s = 0; s <= S/2; s++){
      dp[0][s] = 0; //リセット
    }
    //
    dp[0][0] = 1; //Gに使う(Bには使えないので1)
    dp[0][a[0]] = 1;  //Rに使う
    for (int i = 1; i < N; i++)
    {
      for (int s = 0; s <= S/2; s++){
        dp[i][s] = dp[i-1][s] + (s-a[i] >= 0 ? dp[i-1][s-a[i]] : 0);
        dp[i][s] %= MOD;
      }
    }
    ans += dp[N-1][S/2] * 3;
    ans %= MOD;
  }
  //
  ans %= MOD;
  cout << ans << ENDL;
}

int main()
{
  code();
  return 0;
}
