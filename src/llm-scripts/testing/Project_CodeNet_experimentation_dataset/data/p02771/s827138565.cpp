#include <iostream>
using namespace std;
int main(void){
  int one;
  int two;
  int three;
  cin>>one>>two>>three;
  if(one==two){
     if(one!=three||two!=three){
     cout<<"Yes";
     }
    else{
    cout<<"No";
    }
  }
  else if(one ==three){
       if(one!=two||three!=two){
    cout<<"Yes";
    }
    else{
    cout<<"No";
    }
  }
  else if(two==three){
    if(two!=one||three!=one){
    cout<<"Yes";
    }
    else{
    cout<<"No";
    }
  }
  else{
  cout<<"No";
  }
return 0;
}