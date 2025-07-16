#include<bits/stdc++.h>
using namespace std;

int main(){
  
  long long x;
  cin>>x;

  if(x/11==0){
    if(x>6){
      cout<<2<<endl;
    }else{
      cout<<1<<endl;
    }
    return 0;
  }else{
    
    if(x%11==0){
      cout<<x/11*2<<endl;
    }else if((x-x/11*11)>6){
      cout<<x/11*2+2<<endl;
    }else{
      cout<<x/11*2+1<<endl;
    }
  }
  return 0;
}