#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

int main() {
  vector<int> a(3);
  rep(i,0,3) cin >>a[i];
  sort(a.begin(),a.end());
  int K; cin >>K;
  a[2]*=pow(2,K);
  cout <<accumulate(a.begin(),a.end(),0) <<endl;
  return 0;
}
