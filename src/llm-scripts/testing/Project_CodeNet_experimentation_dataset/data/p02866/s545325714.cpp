#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}
int main(){
  const ll mod=998244353;
  int n,d[100010];
  cin >> n;
  int i,ma=0;
  for(i=0;i<n;i++){
    cin >> d[i];
    ma=max(ma,d[i]);
  }
  if(d[0]!=0){
    cout << 0 << endl;
    return 0;
  }
  vector<int> x(100010,0);
  for(i=0;i<n;i++){
    x[d[i]]++;
  }
  if(x[0]!=1){
    cout << 0 << endl;
    return 0;
  }
  for(i=0;i<=ma;i++){
    if(x[i]==0){
      cout << 0 << endl;
      return 0;
    }
  }
  ll ans=1;
  for(i=1;i<=ma-1;i++){
    ans*=modpow(x[i],x[i+1],998244353);
    ans=ans%mod;
  }
  cout << ans << endl;
}