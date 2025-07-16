#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,m;
  cin>>n>>m;
  vector<pair<int,char>> vec;
  for(int i=0;i<m;i++){
    int s;
    char c;
    cin>>s>>c;
    vec.push_back(make_pair(s,c));
  }
  for(int i=0;i<1000;i++){
    string s=to_string(i);
    if(s.size()!=n)continue;
    bool ok=true;
    for(auto x:vec){
      int p=x.first;
      char moji=x.second;
      p--;
      if(s[p]!=moji)ok=false;
      if(n>1 && p==0 && moji=='0'){
        cout<<-1<<endl;
        return 0;
      }
    }
    if(ok){
      cout<<s<<endl;
      return 0;
    }
  }
  cout<<-1<<endl;
  return 0;
}