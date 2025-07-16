#include <bits/stdc++.h>
using namespace std; 
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)

int main(){
  int N; cin >> N;
  int h,w; cin >> h >> w;
  int r = (N-h+1) * (N-w+1);
  cout << r << "\n";
  
}