#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < n; ++i)

int main() {
  int n;
  cin >> n;
  queue<int> que;
  rep(i, n) {
    int p;
    cin >> p;
    if(i == 0) que.push(p);
    else {
      if(que.back() > p) que.push(p);
    }
  }
  cout << que.size() << endl;
}
