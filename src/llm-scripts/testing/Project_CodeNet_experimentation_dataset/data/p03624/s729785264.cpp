#include<bits/stdc++.h>
using ll=long long;
using namespace std;
#define rep(i, n) for(ll i=0; i<n; i++)
#define Rep(i, j, n) for(ll i=j; i<n; i++)
#define all(vec) vec.begin(), vec.end()
template<class T> inline bool chmin(T& a, T b) {if(a > b) {a = b; return true;} return false;}
template<class T> inline bool chmax(T& a, T b) {if(a < b) {a = b; return true;} return false;}
int dh[4] = {-1, 0, 0, 1};
int dw[4] = {0, -1, 1, 0}; 
using P = pair<int, int>;
const double pi = acos(-1.0);

int main(){
  string s;
  cin>>s;
  vector<bool>ch(26);
  string ans="abcdefghijklmnopqrstuvwxyz";
  rep(i,s.size()){
    ch[s[i]-'a']=true;
  }
  rep(i,26){
    if(!ch[i]){cout<<ans[i]<<endl;return 0;}
  }

  cout<<"None"<<endl;
    
  return 0;
}
