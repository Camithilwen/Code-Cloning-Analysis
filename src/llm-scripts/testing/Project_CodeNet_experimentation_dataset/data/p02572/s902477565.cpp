#include<iostream>
#include<vector>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  long long all = 0;
  long long p = 1000000007;
  for(int i = 0; i < n; i++){
    all += a[i];
    all = all % p;
  }
  long long ans = 0;
  for(int i = 0; i < n; i++){
    all -= a[i];
    if(all < 0) all += p;
    ans += a[i] * all;
    ans %= p;
  }
  cout << ans << endl;
}