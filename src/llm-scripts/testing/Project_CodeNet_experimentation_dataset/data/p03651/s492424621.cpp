#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,K,A,Z;
  cin>>N>>K>>A;
  Z=A;
  for(int i=1;i<N;i++){
    int b;
    cin>>b;
    A=gcd(A,b);
    Z=max(Z,b);
  }
  if(K<=Z&&K%A==0){
    cout<<"POSSIBLE"<<endl;
  }
  else{
    cout<<"IMPOSSIBLE"<<endl;
  }

}
