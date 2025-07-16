#include <bits/stdc++.h>
using namespace std;

int main(){
  int A,B,K;
  cin>>A>>B>>K;
  int temp=1;
  for(int i=0;i<K;i++){
    if(temp==1){
      if(A%2 == 1){
        A--;
      }
        B+=A/2;
        A=A/2;
      temp=temp*(-1);
      continue;
    }
    if(temp==(-1)){
      if(B%2 == 1){
        B--;
      }
        A+=B/2;
        B=B/2;

      temp=temp*(-1);
    }
  }
  cout<<A<<" "<<B<<endl;
  return 0;
}
