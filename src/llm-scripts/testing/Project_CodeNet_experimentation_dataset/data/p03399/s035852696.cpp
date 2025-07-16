#include<bits/stdc++.h>
using namespace std;
int main(){
int A,B,C,D;
  cin>>A>>B>>C>>D;
  if(A<=B){
  if(C<=D)
    cout<<A+C<<endl;
    else
      cout<<A+D<<endl;
  }else{
    if(C<=D)
      cout<<B+C<<endl;
    else
      cout<<B+D<<endl;
  
  }
   return 0;
}