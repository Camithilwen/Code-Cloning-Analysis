#include <iostream>
using namespace std;

#define Q 1000000007

int main(void){
  int n;
  int a[200010];
  long long acc[200010], ans;
  
  cin >> n;
  acc[0] = 0;
  for (int i=1; i<=n; i++){
    cin >> a[i];
    acc[i] = acc[i-1] + a[i];
    acc[i] %= Q;
  }
  ans = 0;
  for (int i=1; i<=n-1; i++){
    ans += (a[i]*((acc[n]-acc[i]+Q)%Q)) % Q;
    ans %= Q;
  }
  cout << ans << endl;
  return 0;
}