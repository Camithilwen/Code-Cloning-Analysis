#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>

int main() {
  int N;
  cin>>N;
  string s,t;
  cin>>s>>t;
  reverse(s.begin(),s.end());
  for(int i=N;i<=2*N;i++){
    string S=s.substr(0,2*N-i);
    reverse(S.begin(),S.end());
    if(S==t.substr(0,2*N-i)){cout<<i<<endl;return 0;}
  }
  return 0;
}