#include <bits/stdc++.h>
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
 
#define bit(n,k) ((n>>k)&1) //*n no k bit me 1 or 0*/

const int mx=100010;
const ll mod=1e9+7;

int main(){
  int n,q;
  cin >> n >> q;
  vector<pair<ll,pair<int,ll>>> a;
  rep(i,n){
    int s,t,x; cin >> s >> t >> x;
    a.push_back({s-x,{-1,x}});
    a.push_back({t-x,{0,x}});
  }
  rep(i,q){
    int d; cin >> d;
    a.push_back({d,{1,i}});
  }
  sort(a.begin(),a.end());

  vector<ll> res(q,-1);
  multiset<int> st;
  for(auto it:a){
    if(it.S.F == -1){
      st.insert(it.S.S);  
    } else if(it.S.F == 0){
//      st.erase(it.S.S);   //同じ数字を全部消してしまう
      st.erase(st.lower_bound(it.S.S)); //1つだけ消したい
    } else {
      if(!st.empty()) res[it.S.S] = *st.begin();
    }
  }

  for(auto ans:res){
    cout << ans << endl;
  }
  return 0;
}