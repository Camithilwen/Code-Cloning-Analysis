#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main() {
  string a;
  cin>>a;
  if(a.at(0)!='A'){
    cout<<"WA"<<endl;
    return 0;
  }
  for(ll i=2;i<a.size()-1;i++){
    if(a.at(i)=='C'){
      a.at(i)='z';
      break;
    }
    if(i==a.size()-2){
      cout<<"WA"<<endl;
      return 0;
    }
  }
  for(ll i=1;i<a.size();i++){
    if(a.at(i)<'a'||a.at(i)>'z'){
      cout<<"WA"<<endl;
      return 0;
    }
  }
  cout<<"AC"<<endl;
  
  return 0;
}
