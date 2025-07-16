#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define SIZE 200005
#define INF 1000000005LL
#define MOD 1000000007

using namespace std;
typedef long long int ll;
typedef pair <string,string> P;

int n;
string s;
map<P,ll> a,b;

int main(){
  cin >> n >> s;
  rep(U,0,1<<n){
    string t,w;
    rep(i,0,n){
      if(U>>i & 1) t.push_back(s[i]);
      else w.push_back(s[i]);
    }
    a[P(t,w)]++;
  }
  rep(U,0,1<<n){
    string t,w;
    rep(i,0,n){
      if(U>>i & 1) t.push_back(s[n*2-i-1]);
      else w.push_back(s[n*2-i-1]);
    }
    b[P(t,w)]++;
  }
  ll ans = 0;
  for(auto i : a){
    ans += i.second * b[i.first];
  }
  cout << ans << endl;
  return 0;
}
