#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

using ll=long long;

int main() {
  int N; cin >>N;
  vector<int> a(N);
  rep(i,0,N) {
    cin >>a[i];
  }
  int b=accumulate(a.begin(),a.end(),0);
  int ans=0;
  int c=INT_MAX;
  rep(i,0,N) {
    int d=abs(N*a[i]-b);
    if (d<c) {
      c=d;
      ans=i;
    }
  }
  cout <<ans <<endl;
  return 0;
}
