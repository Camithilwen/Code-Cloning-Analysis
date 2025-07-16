#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll=long long;


int main(){
  int K;
  string S;
  
   cin >> K >> S;
  
  if(S.size()<=K) {
    cout << S << endl;
    return 0; 
  }
  else{
    rep(i,K){
     cout << S.at(i);
    }
     cout << "..."<< endl;
     return 0;
  }
  
}
    
  
