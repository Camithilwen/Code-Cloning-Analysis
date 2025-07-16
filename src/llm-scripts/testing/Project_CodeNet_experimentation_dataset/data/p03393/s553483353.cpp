#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (n);i++)
using ll = long long;
const ll MOD=1000000007;
const double pi=acos(-1);





int main() 
{
  string S; cin>>S;
  vector<int> word(S.size());
  set<int> ch;
  rep(i,S.size())
  {
    word.at(i)=S.at(i)-'a';
    ch.insert(S.at(i)-'a');
  }
  if(S.size()<26)
  {
    rep(i,26)
    {
      if(!(ch.count(i))) 
      {
        cout<<S<<(char)(i+'a')<<endl;
        return 0;
      }
    }
  }
  if(S=="zyxwvutsrqponmlkjihgfedcba") {cout<<-1<<endl; return 0;}
  
  set<int> list;
  int last;
  char p=S.at(25);
  for(int i=25;i>=0;i--)
  {
    if(S.at(i-1)-'a'>S.at(i)-'a')
    {
      list.insert(S.at(i)-'a');
      S.pop_back();
      continue;
    }  
    list.insert(S.at(i)-'a');
    S.pop_back();
    last=S.at(i-1)-'a';
    list.insert(S.at(i-1)-'a');
    S.pop_back();
    break;
  }  
  for(int i=last+1;i<26;i++)
  {
    if(list.count(i))
    {
      cout<<S<<(char)(i+'a')<<endl;
      return 0;
    }
  }  
  
  /*
  rep(i,26)
  {
    if(i==0) {continue;}
    if(S.at(i)>S.at(i-1)) {}
  */
  /*
  next_permutation(word.begin(),word.end());
  string ans="";
  bool judge=false;
  for(int i=25;i>=0;i--)
  {
  	if(word.at(i)!=i) {judge=true;}
    if(judge) {ans+=(char)(word.at(i)+'a');}
  }
  reverse(ans.begin(),ans.end());
  cout<<ans<<endl;
  */
  return 0;
}
