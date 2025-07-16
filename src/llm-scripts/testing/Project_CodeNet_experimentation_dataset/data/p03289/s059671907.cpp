#include<iostream>
#include<string>
using namespace std;
int main(){

  string S;
  cin>>S;
  if(S[0]!='A'){
  
    cout<<"WA";
    return 0;
  }
  bool Cflag=0;
  if('a'<=S[1]&&S[1]<='z'){
  }
  else{
  
    cout<<"WA";
    return 0;
  }
  for(size_t i=2;i<=S.length()-2;i++){
  
    if(S[i]=='C'){
    
      if(Cflag==1){
      
        cout<<"WA";
        return 0;
      }
      Cflag=1;
    }
    else if('a'<=S[i]&&S[i]<='z'){
    }
    else{
    
      cout<<"WA";
      return 0;
    }
  }
  if('a'<=S[S.length()-1]&&S[S.length()-1]<='z'&&Cflag==1){
  
  }
  else{
    cout<<"WA";
    return 0;
  }
  cout<<"AC";
  return 0;
}