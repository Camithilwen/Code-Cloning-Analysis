#include <bits/stdc++.h>
#define PI 3.1415926535897932
#define _GLIBCXX_DEBUG
using namespace std;
long long GCD(long long A,long long B){
  if(B==0){
    return A;
  }
  else{
    return GCD(B,A%B);
  }
}
int main() {
  
  string A,B,C;
  cin>>A>>B>>C;
  
  deque<char> X;
  for(int i=0;i<A.size();i++){
    X.push_back(A[i]);
  }
  
  deque<char> Y;
  for(int i=0;i<B.size();i++){
    Y.push_back(B[i]);
  }
  
  deque<char> Z;
  for(int i=0;i<C.size();i++){
    Z.push_back(C[i]);
  }
  
  int check=1;
  
  string ans;
  
  
  while(true){
    if(check==1){
      if(X.empty()){
       ans="A";
       break;
      }
      if(X.front()=='a'){
        check=1;
        X.pop_front();
      }
      else if(X.front()=='b'){
        check=2;
        X.pop_front();
      }
      else if(X.front()=='c'){
        check=3;
        X.pop_front();
      }
    }
    else if(check==2){
            if(Y.empty()){
        ans="B";
        break;
    }
      if(Y.front()=='a'){
        check=1;
        Y.pop_front();
      }
      else if(Y.front()=='b'){
        check=2;
        Y.pop_front();
      }
      else if(Y.front()=='c'){
        check=3;
        Y.pop_front();
      }
    }
    else if(check==3){
       if(Z.empty()){
        ans="C";
        break;
      }
      if(Z.front()=='a'){
        check=1;
        Z.pop_front();
      }
      else if(Z.front()=='b'){
        check=2;
        Z.pop_front();
      }
      else if(Z.front()=='c'){
        check=3;
        Z.pop_front();
      }
    }
    }
  cout<<ans<<endl;
}