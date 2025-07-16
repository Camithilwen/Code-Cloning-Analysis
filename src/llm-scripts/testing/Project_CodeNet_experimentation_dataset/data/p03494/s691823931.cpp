#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,A,s,r=999;
  cin>>N;
  for(int i=0;i<N;i++){
    cin>>A;
    s=0;
    while(A%2==0){
      s++;
      A/=2;
    }
    if(s<r)r=s;
  }
  cout<<r<<endl;
}