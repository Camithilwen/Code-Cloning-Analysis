#include<iostream>
#include<string>
using namespace std;
int main(){

  string S;
  cin>>S;
  char check='a';
  bool flag=0;
  for(check='a';check<='z';check++){
  
    flag=1;
    for(size_t i=0;i<=S.length()-1;i++){
    
      if(S[i]==check){
      
        flag=0;
        break;
      }
    }
    if(flag==1){
    
      cout<<check;
      return 0;
    }
  }
  cout<<"None";
  return 0;
}