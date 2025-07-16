#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
  int n,m,q;
  ll res;
  vector<ll> v;
  while(true) {
    cin >> n >> m;
    if(n == 0) break;
    v.clear();
    res = 0;
    for(int i = 0; i < n; i++){
      cin >> q;
      v.push_back(q);
    }
    sort(v.begin(), v.end(), greater<int>());
    for(int i=0; i < n; i++) {
      if(i % m != m - 1)
        res += v[i];
    }
    cout << res << endl;
  }
  
  return 0;
}