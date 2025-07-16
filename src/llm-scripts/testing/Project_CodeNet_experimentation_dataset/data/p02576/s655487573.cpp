#include <bits/stdc++.h>
using namespace std;

int main() {
  int ans=0,N,X,T;
  cin >> N >> X >> T;

  if(N%X){
    ans = (N/X+1)*T;
  }else{
    ans = (N/X)*T;
  }
  cout << ans << endl;
  return 0;
}