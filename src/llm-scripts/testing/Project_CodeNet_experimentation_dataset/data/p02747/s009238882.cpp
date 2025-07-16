#include <bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  vector<string> a;
  string hoge="hi";
  a.push_back(hoge);
  for(int i=0;i<4;i++){
    hoge=hoge+"hi";
    a.push_back(hoge);
  }
  for(int i=0;i<5;i++){
    if(a[i]==s){
      cout<<"Yes"<<endl;
      return 0;
    }
  }
  cout<<"No"<<endl;
  return 0;
}
