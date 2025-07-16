#include<iostream>
using namespace std;
int main(){
  string s;
  cin>>s;
  int r=0;
  for(int i=0;i<3;i++){
    if(s[i]=='R')
        r=1;
  }
  for(int i=0;i<2;i++){
    if(s[i]=='R'){
        if(s[i]==s[i+1])
            r++;
    }
  }
  cout<<r<<"\n";
}
