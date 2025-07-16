#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)


int main() {
  string s;
  cin >> s;
  long n=s.size();
  vector<int>a(26);
  rep(i,n){
    a.at(s.at(i)-'a')++;
  }
  long ans=0;
  rep(i,n){
    ans+=n-a.at(s.at(i)-'a');
  }
  
    cout<<ans/2+1<<endl;
}