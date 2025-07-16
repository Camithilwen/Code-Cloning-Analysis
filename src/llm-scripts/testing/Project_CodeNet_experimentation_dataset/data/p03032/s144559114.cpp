#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int n, K; scanf("%d %d", &n, &K);
  vector<int> a(n);
  for(int i = 0; i < n; i++) scanf("%d", &a[i]);

  int ans = 0;
  for(int left = 0; left <= K; left++){
    for(int right = 0; right <= K; right++){
      if(left + right > min(n, K)) continue;
      vector<int> data;
      int ans1 = 0;
      for(int i = 0; i < left; i++) data.push_back(a[i]), ans1 += a[i];
      for(int i = n - 1; i > n - 1 - right; i--) data.push_back(a[i]), ans1 += a[i];
      sort(data.begin(), data.end());
      for(int i = 0; i < min(K - left - right, left + right); i++) if(data[i] < 0) ans1 -= data[i];
      ans = max(ans, ans1);
    }
  }
  printf("%d\n", ans);
}