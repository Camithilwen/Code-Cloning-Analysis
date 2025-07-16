#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int INF = 1<<30;
const ll mod = 1000000007LL;

int main() {
  string S;
  cin>>S;
  reverse(S.begin(),S.end());
  int l = S.size();
  int ans = 0;
  int over = 0;
  for(int i = 0; i < l; i++){
    int t = S[i]-'0';
    t+=over;
    over = 0;
    if(t>=10) {
      t-=10;
      over = 1;
    }
    if(t<=4) ans += t;
    if(t==5){
      int s;
      if(i!=l-1) s = S[i+1]-'0';
      if(i==l-1||s<=4) ans+=t;
      else if(s>=5) {
        ans+=(10-t);
        over=1;
      }
    }
    if(t>=6) {
      ans += (10-t);
      over = 1;
    }
    if(i==l-1&&over!=0) ans+=over;
  }
  cout<<ans<<endl;
}