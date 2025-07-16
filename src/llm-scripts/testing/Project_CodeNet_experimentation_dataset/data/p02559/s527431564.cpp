#include <bits/stdc++.h>
#include <atcoder/fenwicktree>
using namespace std;
using namespace atcoder;
int main(){
  int N, Q;
  cin >> N >> Q;
  fenwick_tree<long long> a(N);
  for (int i = 0; i < N; i++){
    int x;
    cin >> x;
    a.add(i, x);
  }
  for (int i = 0; i < Q; i++){
    int t;
    cin >> t;
    if (t == 0){
      int p, x;
      cin >> p >> x;
      a.add(p, x);
    }
    if (t == 1){
      int l, r;
      cin >> l >> r;
      cout << a.sum(l, r) << endl;
    }
  }
}