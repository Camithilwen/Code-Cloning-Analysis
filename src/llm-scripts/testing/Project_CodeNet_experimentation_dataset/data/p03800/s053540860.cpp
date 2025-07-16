#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>
#include <map>
#include <queue>
#include <functional>

using namespace std; using ll=long long; using P=pair<ll,ll>; const int INF=1e9; const ll LNF=1e18;

int main(){
  int n; cin>>n;
  string s; cin>>s;
  
  bool ok = false; int ans[n];
  for(int i=0;i<4;i++) {
    fill(ans, ans+n, -1);
    ans[0]=i/2, ans[1]=i%2;

    for(int j=2;j<n;j++) {
      ans[j] = ans[j-2] ^ (s[j-1]=='x') ^ (ans[j-1]==1);
      // ひつじさんが「o」→同じひと
    }

    bool o1 = (ans[n-1] ^ (s[0]=='x') ^ (ans[0]==1)) == ans[1];
    bool o2 = (ans[n-2] ^ (s[n-1]=='x') ^ (ans[n-1]==1)) == ans[0];
    if (o1 && o2) {ok=true; break;}
  }
  if (ok) {
    for(int i=0;i<n;i++) {
      if (ans[i]==0) cout<<"S";
      else cout<<"W";
    }cout<<endl;
  } else {  
    cout<<-1<<endl;
  }
}