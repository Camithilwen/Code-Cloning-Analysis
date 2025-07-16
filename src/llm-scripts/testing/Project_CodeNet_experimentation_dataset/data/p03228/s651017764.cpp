#include <bits/stdc++.h>
using namespace std;

int main(){
  int A,B,K;
  cin>>A>>B>>K;
  for(int i=0;i<K;i++){
    if(i%2==0){
      A -= A%2;
      B += A/2;
      A /= 2;
    }
    else{
      B-=B%2;
      A+=B/2;
      B/=2;
    }
  }
  cout << A <<" "<< B << endl;
}
