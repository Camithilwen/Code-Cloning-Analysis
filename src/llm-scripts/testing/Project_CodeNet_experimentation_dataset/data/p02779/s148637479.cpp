#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(I, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<int> a(n,0);  
  REP(i,n) cin >> a[i];
  
  sort(a.begin(), a.end());
  
  bool ok = true;
  REP(i,n){
    if(i != n-1){
      if(a[i] == a[i+1]){
        ok = false;
      }
    }
  }
  
  
  if(ok) cout << "YES" << endl;
  else cout << "NO" << endl;
  


}