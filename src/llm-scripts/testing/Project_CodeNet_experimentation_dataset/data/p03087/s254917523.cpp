#include<bits/stdc++.h>
using namespace std;
int main(){
  int N,Q;string S;cin>>N>>Q>>S;
  vector<int>V(N);
  int U=0;
  for(int X=0;X<N;X++){
    if(X!=0&&S[X]=='C'&&S[X-1]=='A'){
      U++;
    }
    V[X]=U;
  }
  for(int X=0;X<Q;X++){
    int A,B;cin>>A>>B;
    if(A!=1&&V[A-2]!=V[A-1]){
      cout<<V[B-1]-V[A-1]<<endl;
    }
    else{
      cout<<V[B-1]-V[A-1]<<endl;
    }
  }
}
