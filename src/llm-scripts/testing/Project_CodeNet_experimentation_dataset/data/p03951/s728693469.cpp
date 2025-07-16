#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define intll int long long
const int INF = 1e9;
const int MOD = 1e9 + 7;

int main() {
  int n ; 
  cin >> n ;
  string s , t  ;
  cin >> s >> t ;
  deque<char> S , T ;
  rep(i,n){
    S.push_back(s.at(i)) ;
    T.push_back(t.at(i));
  }
  if(s == t ) {
    cout << s.size() <<endl ; 
    return 0 ;
  }
  
  int ans = 2 * n ;
  
  rep(i,n){
    S.pop_front();
    T.pop_back();
    
    if( S == T){
      ans = S.size() + 2*(i+1) ;
      cout <<  ans <<endl ;
      return 0 ;
    }
  }
    
  
}
