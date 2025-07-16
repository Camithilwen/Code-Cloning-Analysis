#include <bits/stdc++.h>
using namespace std;

int main(){
  int64_t A,B;
  int K;
  cin >> A >> B >> K;
  while(K>0){
    A/=2;
    B+=A;
    K--;
    if(K==0){
      break;
    }
    B/=2;
    A+=B;
    K--;
  }
  cout << A << " " << B << endl;
  return 0;
}
