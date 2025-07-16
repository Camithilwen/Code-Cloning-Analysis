#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
const int mod = 1000000007;

int main() {
  int n, q;
  cin >> n >> q;
  vector<tuple<int, int, int>> a(n);
  rep(i, n) {
    int s, t, x;
    cin >> s >> t >> x;
    s -=x;
    t -= x;
    a[i] = tie(x, s, t);
  }
  sort(a.begin(), a.end());

  set<P> st;
  rep(i, q) {
    int d;
    cin >> d;
    st.insert(P(d, i));
  }
  vector<int> ans(q, -1);
  rep(i, n) {
    int s, t, x;
    tie(x, s, t) = a[i];
    auto it = st.lower_bound(P(s, -1));
    while(it != st.end()) {
      if(it->first >= t) break;
      ans[it->second] = x;
      st.erase(it++);
    }
  }
  rep(i, q) {
    cout << ans[i] << endl;
  }
  
}