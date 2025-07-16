#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  string S,T;
  cin >> N >> S >> T;
  bool a=false;
  for(int i=0;i<N;i++){
    if(S.substr(i,N-i)==T.substr(0,N-i)){
      a=true;
      cout << N+i << endl;
      break;
    }
  }
  if(!a){
    cout << 2*N << endl;
  }
} 