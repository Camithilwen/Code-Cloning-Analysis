#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
int main() {
  ios::sync_with_stdio(0); 
  cin.tie(0); 
  
  int n, k;
  cin >> n >> k;

  priority_queue<int, vector<int>, greater<int>> pq;

  for (int i = 0; i < n; ++i) {
    int x; cin >> x;

    if (pq.size() < k) pq.push(x);
    else if (pq.size() >= k && x > pq.top()) {
      pq.pop();
      pq.push(x);
    }
  }

  int res = 0;
  while (!pq.empty()) {
    res += pq.top(); pq.pop();
  }

  cout << res << "\n";
}
