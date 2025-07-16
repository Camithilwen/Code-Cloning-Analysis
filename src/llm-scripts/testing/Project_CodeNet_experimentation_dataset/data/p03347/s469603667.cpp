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
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
using ll = long long;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;


    
int main(){
  int n; cin >> n; ll a[n];
  rep(i, n){
    cin >> a[i];
  }
  if(a[0]!=0){
    cout << -1 << endl; return 0;
  }
  rep(i, n-1){
    if(a[i+1]>a[i]+1){
      cout << -1 << endl; return 0;
    }
  }
  ll ans = 0;
  for(int i=1; i<n; i++){
    if(a[i]==a[i-1]+1) ans++;
    else ans+=a[i];
  }
  cout << ans << endl; 
}