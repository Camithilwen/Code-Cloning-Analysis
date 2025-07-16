#include <bits/stdc++.h>
#define rep(i,n)for(long long i=0;i<(long long)(n);++i)
#define all(a) a.begin(), a.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
 
const int MOD=1e9+7;
const ll INF=1e18;
const int MAX=510000;
const double pi=acos(-1);
int dx[8] = {1,0,-1,0,1,1,-1,-1};
int dy[8] = {0,1,0,-1,-1,1,1,-1};

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false); 
  
  int n,q;
  cin >> n >> q;
  vector<tuple<int,int,int>> stx(n);
  rep(i,n){
    cin >> get<1>(stx[i]) >> get<2>(stx[i]) >> get<0>(stx[i]);
  }
  sort(stx.begin(),stx.end());
  
  set<P> st;
  rep(i,q){
    int x;
    cin >> x;
    st.emplace(x,i);
  }
  
  vector<int> ans(q,-1);
  rep(i,n){
    int s = get<1>(stx[i]);
    int t = get<2>(stx[i]);
    int x = get<0>(stx[i]);
    //xの昇順で考えてぶつかったら，その人をerase
    auto first = st.lower_bound(P(s-x,0));//引っかかる人
    auto end = st.upper_bound(P(t-x-1,q));//引っかからない人
    
    for(auto it = first; it !=end; ++it) ans[it->second] = x;
    
    st.erase(first,end);
  }
  
  rep(i,q) cout << ans[i] << endl;
  return 0;
}
