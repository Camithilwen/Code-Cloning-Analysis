#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  string s;
  cin>>s;
  if(s.size()!=26){
    map<char,int> mp;
    rep(i,s.size()){
      mp[s[i]]=1;
    }
    rep(i,26){
      if(mp['a'+i]!=1){
        s+=('a'+i);
        break;
      }
    }
    cout<<s<<endl;
  }else{
    if(s=="zyxwvutsrqponmlkjihgfedcba"){
      cout<<-1<<endl;
      return 0;
    }
    vector<char> tmp;
    tmp.push_back(s[25]);
    for(int i=24; i>=0; i--){
      char ch='{';
      for(auto x : tmp){
        if(x > s[i]){
          ch=min(ch,x);
        }
      }
      if(ch!='{'){
        s = s.substr(0,i);
        s+=ch;
        break;
      }
      tmp.push_back(s[i]);
    }
    cout<<s<<endl;
  }
}
