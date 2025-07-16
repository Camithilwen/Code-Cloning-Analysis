#include<bits/stdc++.h>
using namespace std;

signed main(){

  string s,t;
  cin>>s;
  t = s;
  vector<int> alp(26);
  for(auto c:s)alp[c-'a']++;

  string ans = "zzzzzzzzzzzzzzzzzzzzzzzzzzz";
  auto chmin = [](auto& a,auto b){if(a>b)a=b;};
  while(1){
    for(int i=0;i<26;++i)if(alp[i]==0){
      string tmp = s;
      tmp += ('a'+i);
      if(t<tmp){
        chmin(ans,tmp);
      }
    }
    if(s.empty())break;
    alp[s.back()-'a']--;
    s.pop_back();
  }
  cout<<(ans=="zzzzzzzzzzzzzzzzzzzzzzzzzzz"?"-1":ans)<<endl;
  
}