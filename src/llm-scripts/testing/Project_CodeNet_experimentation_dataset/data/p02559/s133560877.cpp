#include <bits/stdc++.h>
#include <atcoder/fenwicktree>
using namespace std;

int main(){
  int n, q;
  cin >> n >> q;
  vector<int> A(n);
  copy_n(istream_iterator<int>(cin), n, A.begin());
  
  atcoder::fenwick_tree<int64_t> fw(n);
  for (int i = 0; i < n; i++)
    fw.add(i, A[i]);
  for (int i = 0; i < q; i++){
  	int a, l, r;
    cin >> a >> l >> r;
    if (a == 0)
      fw.add(l, r);
    else
      cout << fw.sum(l, r) << endl;
  }

}