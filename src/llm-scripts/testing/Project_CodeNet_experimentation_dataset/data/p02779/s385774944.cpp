#include <bits/stdc++.h>
#include <cstdlib>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  string ans="YES";
  map<int, int> hoge;
  
  rep(i,N) {
    cin >> A[i];
    if(hoge[A[i]] == 1) ans="NO";
    else hoge[A[i]] = 1;
  }
  
  cout << ans << endl;
   
  return 0;
}