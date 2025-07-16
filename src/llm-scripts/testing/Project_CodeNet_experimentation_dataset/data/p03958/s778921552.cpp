#include <bits/stdc++.h>
using namespace std;

int main(){
  int k, t;  cin >> k >> t;
  vector<int> a(t);
  for(int i=0; i<t; i++)  cin >> a[i];
  sort(a.begin(), a.end());

  int sum = 0, ans = 1e9;
  for(int i=0; i<t; i++){
    sum += a[i];
    ans = min(ans, abs(k-sum-sum));
  }

  cout << max(0, ans - 1) << endl;

  return 0;
}
