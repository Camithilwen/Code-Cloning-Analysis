#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  if(s.size()%2==1){
    cout<<"No"<<endl;
    return 0;
  }
  for(int i=0;i<s.size();i++){
    if(s.at(i)!=(i%2==0?'h':'i')){
      cout<<"No"<<endl;
      return 0;
    }
  }
  cout<<"Yes"<<endl;
}