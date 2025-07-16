#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,K;
  int A=1;
    cin>>N>>K;
  for(int i=0;i<N;i++) {
    if (A<K) 
      A*=2;
    else 
      A+=K;
  	}
  cout<<A<<endl;
  }