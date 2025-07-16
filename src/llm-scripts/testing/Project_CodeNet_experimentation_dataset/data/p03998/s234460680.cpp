#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  string sa,sb,sc;
  cin>>sa>>sb>>sc;
  reverse(sa.begin(),sa.end());
  reverse(sb.begin(),sb.end());
  reverse(sc.begin(),sc.end());
  queue<char> card;
  card.push(sa[sa.size()-1]);
  sa.pop_back();
  char ans;
  while(true){
    char now=card.front();
    card.pop();
    if(now=='a'){
      if(sa.empty()) {ans='A'; break;}
      card.push(sa[sa.size()-1]);
      sa.pop_back();
    }
    if(now=='b'){
      if(sb.empty()) {ans='B'; break;}
      card.push(sb[sb.size()-1]);
      sb.pop_back();
    }
    if(now=='c'){
      if(sc.empty()) {ans='C'; break;}
      card.push(sc[sc.size()-1]);
      sc.pop_back();
    }
  }
  cout<<ans<<endl;
}

