#include <bits/stdc++.h>
#include<algorithm>
#define int long long
using namespace std;
typedef pair<int,int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 1000000000000

int MOD=1000000007;
int modpow(int a,int x){
  if(a<0)a+=MOD;
  int ans=1;
  while(x>0){
    if(x&1) ans=ans*a%MOD;
      a=a*a%MOD;
      x>>=1;
  }
  return ans;
}
int gyaku(int n){
    return modpow(n,MOD-2);
}
signed main() {
  int n;
  int ans=0;
  cin>>n;
  vector<int>a(n);
  rep(i,n)cin>>a[i];
  vector<int>ball(n);
  for(int i=n-1;i>=0;i--){
    int p=i+1;
    int count=0;
    while(p<=n){
      if(ball[p-1])count++;
      p+=i+1;
    }
    ball[i]=abs((count%2)-a[i]);
    if(ball[i]) ans++;
  }
  cout<<ans<<endl;
  rep(i,n){
    if(ball[i])cout<<i+1<<endl;
  }
}
