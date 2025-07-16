#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin>>s;
  bool at=true;
  if(s.size()%2!=0){
    cout<<"No"<<endl;
    return 0;
  }
  for(int i=0;i<s.size()-1;i+=2){
    if(s[i]!='h'||s[i+1]!='i'){
      at=false;
      break;
    }
  }
  if(at==true) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}

