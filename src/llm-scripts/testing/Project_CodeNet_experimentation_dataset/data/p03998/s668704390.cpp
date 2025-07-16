#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(obj) (obj).begin(), (obj).end()
#define bit(n) (1LL << (n))

using namespace std;

typedef long long ll;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false); 
  
  string A;
  string B;
  string C;
  
  rep(i,3) {
    string s; cin>>s;
    
    if (i==0) A=s;
    if (i==1) B=s;
    if (i==2) C=s;
  }
  
  char next = 'a';
  
  while(true) {
    if(next == 'a') {      
      if (A.length() == 0) {
        cout<<"A";
        return 0;
      }
      next = A[0];
      A.erase(0,1);
    } else if(next == 'b') {
      if (B.length() == 0) {
        cout<<"B";
        return 0;
      }
      next = B[0];
      B.erase(0,1);
    } else if(next == 'c') {
      if (C.length() == 0) {
        cout<<"C"; 
        return 0;
      }
      next = C[0];
      C.erase(0,1);
    } 
  }
  
  return 0;
}