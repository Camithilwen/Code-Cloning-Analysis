#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef long double ld;
const int inf=1e9+7;
const ll longinf=1LL<<60;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define F first
#define S second

const int mx=1000010;
const ll mod=1e9+7;


int main(){
  int n;
  string s;
  cin >> n >> s;
  int q;
  cin >> q;
while(q--){
  int k; cin >> k;
  ll ans = 0;
  ll dcnt = 0;
  ll mcnt = 0;
  ll cnt = 0;
  rep(i,n){
    if(i-k>=0){
      if(s[i-k]=='D'){
        dcnt--;
        cnt-=mcnt;
      }
      if(s[i-k]=='M'){
        mcnt--;
      }
    }
    if(s[i]=='C'){ 
      ans+=cnt; continue; 
    }
    if(s[i]=='M'){
      cnt+=dcnt;
      mcnt++;
      continue;
    }
    if(s[i]=='D'){
      dcnt++;
      continue;
    }
  }
  cout << ans << endl;
}

  return 0;
}