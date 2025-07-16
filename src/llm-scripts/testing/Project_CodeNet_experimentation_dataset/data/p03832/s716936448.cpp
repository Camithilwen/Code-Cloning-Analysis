#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 2005;
const int mod = 1e9+7;
int fac[N],combi[N][N];

int add(int x,int y) {
   int ret = ((x+y)%mod + mod)%mod;
   return ret;
}
int mul(int x,int y) {
   ll ret = (ll)x*y;
   ret%=mod;
   return ret;
}


int num[2];
int group[2];
int dp[N][N];
int inv[N];

int invFac[N];

int solveDp(int x,int rem) {
   if(rem==0) {
      return 1;
   }
   if(x>num[1]) {
      return 0;
   }
   int &ret = dp[x][rem];
   if(ret != -1) {
      return ret;
   }
   ret = solveDp(x+1,rem);
   int cur = 1;
   for(int j = 0;j<group[0];++j) {
      cur = mul(cur, invFac[x]);
   }
   for(int f = group[0];f<=group[1] && f*x<=rem;++f) {
      int tot = f*x;
      int m = fac[tot];
      int t = cur;
      t = mul(t, invFac[f]);
      m = mul(t,m);
      m = mul(combi[rem][tot],m);
      ret = add(ret, mul(m,solveDp(x+1,rem-tot)));
      cur = mul(cur,invFac[x]);
   }
   return ret;
}

int myPow(int x,int c) {
   int ret = 1;
   while(c>0) {
      if(c&1) {
         ret = mul(ret,x);
      }
      x = mul(x,x);
      c/=2;
   }
   return ret;
}
void solve() {
   int n;
   memset(dp,-1,sizeof(dp));
   scanf("%d",&n);
   for(int i=0;i<2;++i) {
      scanf("%d",&num[i]);
   }
   for(int i=0;i<2;++i) {
      scanf("%d",&group[i]);
   }
   fac[0] = 1;
   inv[0] = 1;
   invFac[0] = 1;
   for(int i=1;i<N;++i) {
      fac[i] = mul(fac[i-1],i);
      inv[i] = myPow(i,mod-2);
      invFac[i] = myPow(fac[i],mod-2);
   }
   for(int i=0;i<N;++i) {
      combi[i][i] = combi[i][0] = 1;
      for(int j = 1;j<i;++j) {
         combi[i][j] = add(combi[i-1][j],combi[i-1][j-1]);
      }
   }
   printf("%d\n", solveDp(num[0],n));
}

int main()
{
   //freopen("input.txt","r",stdin);
   solve();
}