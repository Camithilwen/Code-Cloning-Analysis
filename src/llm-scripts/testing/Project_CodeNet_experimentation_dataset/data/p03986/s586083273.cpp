#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
const int INF=1001001001;

int main() {
  string s;
  cin>>s;
  int n=s.size();
  stack<char>k;
  for(int i=0;i<n;i++){
    if(k.empty()){k.push(s[i]);}
    else if(s[i]=='S'){k.push(s[i]);}
    else if(s[i]=='T'){
      if(k.top()=='T'){k.push('T');}
      else if(k.top()=='S'){k.pop();}
    }
    //cout<<k.top()<<endl;
  }
  cout<<k.size()<<endl;
  return 0;
}