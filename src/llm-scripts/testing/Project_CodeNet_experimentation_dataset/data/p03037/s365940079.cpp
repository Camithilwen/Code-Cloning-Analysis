#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(I, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;

int main() {
  int n,m;
  cin >> n >> m;
  
  vector<int> l(m,0);
  vector<int> r(m,0);
  vector<bool> can(n,true);
  
  REP(i,m)  cin >> l[i] >> r[i];
  
  sort(l.begin(), l.end());
  sort(r.begin(), r.end());
    
  REP(i,n){
    if(i < (l[m-1]-1) || (r[0]-1) < i){
      can[i] = false;
    }
  }
 
  
  
  int ans = 0;
  REP(i,n){
    if(can[i] == true){
      ans++;
    }
  }
  
  cout << ans << endl;
  
}