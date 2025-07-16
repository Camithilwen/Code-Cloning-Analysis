#include<bits/stdc++.h>
using namespace std;
int main(){
string str;
  cin>>str;
  if(str.size()==2){
    cout<<str<<endl;
  }
  else{
   cout<<str.at(2)<<str.at(1)<<str.at(0)<<endl;
  }
  return 0;
}