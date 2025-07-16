#include <bits/stdc++.h>
using namespace std;
#include <math.h>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int64_t INF = 1LL << 60;

int main() {
  int N;
  cin>>N;
  string s;
  string t;
  cin>>s>>t;
  string d;
  if(s==t){cout<<s.size()<<endl;return 0;}
  else{
	  int ans=s.size()+t.size();
   for(int i=0;i<N;i++){
	  if(s.substr(i)==t.substr(0,N-i)){
       d=s.substr(0,i)+t;
	   int a=d.size();
	   ans=min(ans,a);
	  }
  }
   cout<<ans<<endl;return 0;
  }
  return 0;
}
