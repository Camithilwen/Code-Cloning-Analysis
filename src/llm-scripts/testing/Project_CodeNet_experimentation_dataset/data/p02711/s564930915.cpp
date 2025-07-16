#include<bits/stdc++.h>
using namespace std;

int main(){
  string n;
  cin>>n;
  bool a=true;
  for(int i=0;i<3;i++){
    if(n.at(i)=='7'){
      a=false;
    }
  }
  if(a){
    cout<<"No"<<endl;
  }
  else{
    cout<<"Yes"<<endl;
  }
}
  