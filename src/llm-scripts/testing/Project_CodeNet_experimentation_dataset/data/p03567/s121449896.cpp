#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;cin>>s;
  int r=0;
  for(int i=1;i<s.size();++i){
    if(s[i]=='C'&&s[i-1]=='A'){r=1;break;}
  }
  cout<<(r?"Yes":"No");
}