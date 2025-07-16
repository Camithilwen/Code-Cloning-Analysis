#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin>>S;
  int M=S.size();
  int N=0,A=0,B=0;
  for(int i=0;i<M;i++){
    if(S[i]=='S'){
      B++;
    }
    else{
      A++;
    }
    N=max(N,A-B);
  }
  cout<<N*2<<endl;
      
}