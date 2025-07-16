#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  int N,Q;
  cin >> N >> Q;
  ll S[N],T[N],X[N];
  vector<ll> vect;
  vect.push_back(-Mod * 1000LL);
  vect.push_back(Mod * 1000LL);
  for (int i = 0; i < N; i++) {
    cin >> S[i] >> T[i] >> X[i];
    vect.push_back(S[i]-X[i]);
    vect.push_back(T[i]-X[i]);
  }
  sort(vect.begin(),vect.end());
  vector<ll> vec;
  for (int i = 1; i < (int)vect.size(); i++) {
    if (vect[i-1] != vect[i]) {
      vec.push_back(vect[i-1]);
    }
  }
  vec.push_back(Mod * 1000LL);
  int sz = vec.size();
  vector<ll> ans(sz);
  vector<ll> L[sz];
  vector<ll> R[sz];
  for (int i = 0; i < N; i++) {
    int l = lower_bound(vec.begin(),vec.end(),S[i]-X[i]) - vec.begin();
    int r = lower_bound(vec.begin(),vec.end(),T[i]-X[i]) - vec.begin();
    L[l].push_back(i);
    R[r].push_back(i);
  }
  multiset<ll> Set;
  for (int i = 0; i < sz; i++) {
    for (int j = 0; j < (int)L[i].size(); j++) {
      Set.insert(X[L[i][j]]);
    }
    for (int j = 0; j < (int)R[i].size(); j++) {
      auto itr = Set.lower_bound(X[R[i][j]]);
      Set.erase(itr);
    }
    if (Set.empty()) {
      ans[i] = -1;
    } else {
      auto itr = Set.begin();
      ans[i] = *itr;
    }
  }

  for (int i = 0; i < Q; i++) {
    ll D;
    cin >> D;
    int w = lower_bound(vec.begin(),vec.end(),D) - vec.begin();
    if (vec[w] != D) {
      w--;
    }
    cout << ans[w] << endl;
  }
  return 0;
}