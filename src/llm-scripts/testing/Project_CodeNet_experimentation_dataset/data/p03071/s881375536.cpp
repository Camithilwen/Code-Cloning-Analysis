#include <bits/stdc++.h>
using namespace std;

int main(){
  int A,B;
  int ans=0;
  cin >> A >> B;
  for(int i=0;i<2;i++){
    ans+=max(A,B);
    if(max(A,B)==A){
      A--;
    }
    else{
      B--;
    }
  }
  cout << ans << endl;
}