#include <iostream>
#include <vector>

using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  int mod = 1000000007;
  long long sum = 0;
  for(int i = 0; i < n; i++){
    cin >> a[i];
    sum += a[i];
    sum %= mod;
  }

  long ans = 0;

  for(int j = 0; j < n; j++){
    sum -= a[j];
    if(sum < 0) sum += mod;
    ans += a[j] * sum;
    ans %= mod;
  }

  cout << ans << endl;

  return 0;
}
