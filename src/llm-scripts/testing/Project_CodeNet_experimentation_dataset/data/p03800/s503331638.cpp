#include <bits/stdc++.h>
#define rep(i,n)for(long long i=0;i<(long long)(n);i++)
#define all(a) a.begin(), a.end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
 
const ll MOD=1e9+7;
const ll INF=1e18;
const int MAX=510000;
const double pi=acos(-1);
int dx[8] = {1,0,-1,0,1,1,-1,-1};
int dy[8] = {0,1,0,-1,-1,1,1,-1};
int d[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};



int main(){
  cin.tie(0);
  ios::sync_with_stdio(false); 
  
  int n;
  cin >> n;
  string s;
  cin >> s;
  rep(j,4){
    vector<char>ans(n,'.');
    if(j==0){
      ans[0]='S';
      ans[1]='S';
    }
    if(j==1){
      ans[0]='S';
      ans[1]='W';
    }
    if(j==2){
      ans[0]='W';
      ans[1]='S';
    }
    if(j==3){
      ans[0]='W';
      ans[1]='W';
    }
    bool ok = true;
    rep(i,n){
      if(s[i]=='o' && s[(i+1)%n]=='o'){
        if(ans[i]=='S' && ans[(i+1)%n]=='S'){
          if(ans[(i+2)%n]=='W')ok=false;
          ans[(i+2)%n]='S';
        }
        if(ans[i]=='S' && ans[(i+1)%n]=='W'){
          if(ans[(i+2)%n]=='S')ok=false;
          ans[(i+2)%n]='W';
        }
        if(ans[i]=='W' && ans[(i+1)%n]=='S'){
          if(ans[(i+2)%n]=='S')ok=false;
          ans[(i+2)%n]='W';
        }
        if(ans[i]=='W' && ans[(i+1)%n]=='W'){
          if(ans[(i+2)%n]=='W')ok=false;
          ans[(i+2)%n]='S';
        }
      }
      if(s[i]=='o' && s[(i+1)%n]=='x'){
        if(ans[i]=='S' && ans[(i+1)%n]=='S'){
          if(ans[(i+2)%n]=='S')ok=false;
          ans[(i+2)%n]='W';
        }
        if(ans[i]=='S' && ans[(i+1)%n]=='W'){
          if(ans[(i+2)%n]=='W')ok=false;
          ans[(i+2)%n]='S';
        }
        if(ans[i]=='W' && ans[(i+1)%n]=='S'){
          if(ans[(i+2)%n]=='W')ok=false;
          ans[(i+2)%n]='S';
        }
        if(ans[i]=='W' && ans[(i+1)%n]=='W'){
          if(ans[(i+2)%n]=='S')ok=false;
          ans[(i+2)%n]='W';
        }
      }
      if(s[i]=='x' && s[(i+1)%n]=='o'){
        if(ans[i]=='S' && ans[(i+1)%n]=='S'){
          if(ans[(i+2)%n]=='W')ok=false;
          ans[(i+2)%n]='S';
        }
        if(ans[i]=='S' && ans[(i+1)%n]=='W'){
          if(ans[(i+2)%n]=='S')ok=false;
          ans[(i+2)%n]='W';
        }
        if(ans[i]=='W' && ans[(i+1)%n]=='S'){
          if(ans[(i+2)%n]=='S')ok=false;
          ans[(i+2)%n]='W';
        }
        if(ans[i]=='W' && ans[(i+1)%n]=='W'){
          if(ans[(i+2)%n]=='W')ok=false;
          ans[(i+2)%n]='S';
        }
      }
      
      if(s[i]=='x' && s[(i+1)%n]=='x'){
        if(ans[i]=='S' && ans[(i+1)%n]=='S'){
          if(ans[(i+2)%n]=='S')ok=false;
          ans[(i+2)%n]='W';
        }
        if(ans[i]=='S' && ans[(i+1)%n]=='W'){
          if(ans[(i+2)%n]=='W')ok=false;
          ans[(i+2)%n]='S';
        }
        if(ans[i]=='W' && ans[(i+1)%n]=='S'){
          if(ans[(i+2)%n]=='W')ok=false;
          ans[(i+2)%n]='S';
        }
        if(ans[i]=='W' && ans[(i+1)%n]=='W'){
          if(ans[(i+2)%n]=='S')ok=false;
          ans[(i+2)%n]='W';
        }
      }
    }
    if(ok){
      rep(i,n)cout << ans[i];
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
