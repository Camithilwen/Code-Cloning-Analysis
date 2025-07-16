#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int mod=1000000007;
const int INF=1001001001;

int main() {
  int N;
  cin>>N;
  string s,t;
  cin>>s>>t;
  for(int i=N;i>=0;i--){
    string v=s;
    reverse(v.begin(),v.end());
    string r=v.substr(0,i);
    reverse(r.begin(),r.end());
    if(r==t.substr(0,i)){cout<<2*N-i<<endl;return 0;}
  }
  cout<<2*N<<endl;
  
  return 0;  
}