#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin>>s;
  bool ans=true;
  int cnt=0;
  for(int i=0;i<s.size();i++){
    if(isupper(s[i])) cnt++;
  }
  if(cnt!=2) ans=false;
  cnt=0;
  if(s[0]!='A') ans=false;
  for(int i=2;i<s.size()-1;i++){
    if(s[i]=='C') cnt++;
  }
  if(cnt!=1) ans=false;
  if(ans) cout<<"AC"<<endl;
  else cout<<"WA"<<endl;
}
