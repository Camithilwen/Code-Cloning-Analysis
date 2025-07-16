#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  string S;
  cin>>S;
  
  int ans=100000;
  
  
  for(int i=0;i<=S.size()-3;i++){
    string res;
    res[0]=S[i];
    res[1]=S[i+1];
    res[2]=S[i+2];
    
    int X=stoi(res);
    
    ans=min(abs(X-753),ans);
  }
  
  cout<<ans<<endl;
}