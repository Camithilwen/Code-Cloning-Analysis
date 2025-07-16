#include<iostream>
#include<string>
#include<cstring>
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
const ll mod=1e9+7 ;
#define PI 3.141592653589793



int main(){
  string S; cin >> S;
  int N = S.size(); bool acan=true, bcan=true;
  if(N%2==1){
    cout << "No" << endl; return 0;
  }
  rep(i, N){
    if(i%2==1 && S[i]!='h') acan=false;
    if(i%2==0 && S[i]!='i') acan=false;
  }
  rep(i, N){
    if(i%2==0 && S[i]!='h') bcan=false;
    if(i%2==1 && S[i]!='i') bcan=false;
  }
  if(acan || bcan) cout << "Yes" << endl;
  else cout << "No" << endl;
}
