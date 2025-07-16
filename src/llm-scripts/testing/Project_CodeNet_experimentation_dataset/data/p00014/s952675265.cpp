#include <iostream>
using namespace std;

int main(){
  int a,s;
  while(cin>>a){//EOF?????§
    s=0;
    for(int i=a;i<600;i+=a){
      s+=i*i*a;
    }
    cout<<s<<endl;
  }
  return 0;
}
  