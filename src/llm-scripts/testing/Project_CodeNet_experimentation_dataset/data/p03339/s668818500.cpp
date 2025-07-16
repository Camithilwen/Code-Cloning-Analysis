#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (n);i++)
using ll = long long;
const ll MOD=1000000007;



int main() 
{
  ll N; cin>>N;
  string S; cin>>S;
  ll hitomi=0;
  ll max_hitomi=0;
  rep(i,N)
  {
    if(i==0) {continue;}
    if(S.at(i)=='W') {hitomi++;}
  }
  rep(i,N)
  {
    if(i==0) {max_hitomi=hitomi; /*cout<<hitomi<<" "<<max_hitomi<<endl;*/ continue;}
    if(S.at(i-1)=='E') {hitomi++;}
    if(S.at(i)=='W') {hitomi--;}
    max_hitomi=max(max_hitomi,hitomi);
    //cout<<hitomi<<" "<<max_hitomi<<endl;
  }
  cout<<N-1-max_hitomi<<endl;
  return 0;
}