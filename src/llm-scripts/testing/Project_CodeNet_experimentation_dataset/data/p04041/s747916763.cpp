#include<bits/stdc++.h>
using namespace std;

const int md = 1e9+7;
int n, x, y, z, sm, g;
long long a[2][1<<20] = {1}, ans;

int main(){
  scanf("%d%d%d%d", &n, &x, &y, &z);
  sm = x + y + z;
  g = (((1<<y)+1)<<z)+1;
  for(int i = 0; i <= n; i++){
    (ans *= 10) %= md;
    for(int j = 0; j < 1<<sm; j++){
      if((j & g) == g) (ans += a[i&1][j]) %= md;
      else for(int k = 1; k <= 10; k++) (a[i&1^1][(j+(1<<sm))>>k] += a[i&1][j]) %= md;
      a[i&1][j] = 0;
    }
  }
  printf("%lld\n", ans);
}