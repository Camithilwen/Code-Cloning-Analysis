#include <stdio.h>

const int bias = 10;
long long dp[bias*2+1][2],nxt[bias*2+1][2];

void mx(long long &a, long long b)
{
	if (a < b) a = b;
}

int main()
{
  for (int i=0;i<=bias*2;i++) dp[i][0] = dp[i][1] = -1e18; dp[bias][0] = 0;
  
  int n; scanf ("%d",&n);
  for (int k=0;k<n;k++){
	int x; scanf ("%d",&x);
  for (int i=0;i<=bias*2;i++) nxt[i][0] = nxt[i][1] = -1e18;
    for (int i=0;i<=bias*2;i++){
mx(nxt[i][0],dp[i][0]);
mx(nxt[i][0],dp[i][1]);
mx(nxt[i+2][1],dp[i][0]+x);
    }
  for (int i=1;i<=bias*2;i++){
    dp[i-1][0] = nxt[i][0];
    dp[i-1][1] = nxt[i][1];
  }
    dp[bias*2][0] = dp[bias*2][1] = -1e18;
  }
  
  int last = (n / 2) * 2 - n + bias;
  long long ans = -1e18;
  mx(ans,dp[last][0]);
  mx(ans,dp[last][1]);
  printf ("%lld\n",ans);
return 0;
}
