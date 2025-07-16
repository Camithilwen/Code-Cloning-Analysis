#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin>>s;
  
  bool b=true;
  int cnt=0,x;
  if(s[0]!='A') b=false;
  for(int i=2;i<s.size()-1;i++){
    if(s[i]=='C'){
      cnt++;
      x=i;
    }
  }
  if(cnt!=1) b=false;
  for(int i=1;i<s.size();i++){
    if(i==x) continue;
    if(s[i]<'a' || s[i]>'z') b=false;
  }
  if(b) cout<<"AC"<<endl;
  else cout<<"WA"<<endl;

  return 0;
}