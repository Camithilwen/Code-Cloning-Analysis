#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int long long
using P = pair<int, int>;

#define LOG(variable) cerr << #variable":\t" << (variable) << "\n"
#define LOGCON(i, container) for(int (i) = 0; (i) < (container).size(); ++(i)) cerr << (i) << ":\t" << (container)[(i)] << "\n"
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(i, r, n) for (int i = (r); i < (n); ++i)
#define REPR(i, n) for(int i = (n); i >= 0; --i) // from n to 0
#define REPRS(i, n, r) for(int i = (n); i >= (r); --i) // from n to r
#define REPOBJ(itr, obj) for(auto itr = (obj).begin(); itr != (obj).end() ; ++itr)
#define REPROBJ(itr, obj) for(auto itr = (obj).rbegin(), e = (obj).rend(); itr != e; ++itr)
#define COUTB(x) cout << (x) << "\n"
#define COUTS(x) cout << (x) << " "
#define PB push_back
#define SORT(obj) sort((obj).begin(), (obj).end())
#define SORTR(obj) sort((obj).begin(), (obj).end(), greater<>())
#define ALL(obj) (obj).begin(), (obj).end()
#define MOD 1000000007
#define PI (acos(-1))
template<typename T = int>
T in() {T a; cin >> a; return a;}
/***** MAIN *****/
int lowerbound(vector<int> &v, int num) {
  int left = 0, right = v.size()-1;
  while(right-left > 0) {
    int mid = (left + right) / 2;
    if(v[mid] >= num) right = mid;
    else left = mid + 1;
  }
  if(v[left] >= num) return left;
  else return v.size();
}

int upperbound(vector<int> &v, int num) {
  int left = 0, right = v.size()-1;
  while(right-left > 0) {
    int mid = (left + right) / 2;
    if(v[mid] > num) right = mid;
    else left = mid + 1;
  }
  if(v[left] > num) return left;
  else return v.size();
}
signed main() {
  int n; cin >> n;
  vector<int> a(n), b(n), c(n);
  REP(i,n) cin >> a[i];
  REP(i,n) cin >> b[i];
  REP(i,n) cin >> c[i];
  SORT(a); SORT(b); SORT(c);
  int ans = 0;
  REP(i,n) {
    int upper_count = lowerbound(a, b[i]);
    int lower_count = n - upperbound(c, b[i]);
    ans += upper_count * lower_count;
  }
  cout << ans;
  cout << "\n";
  return 0;
}
/***** MAIN *****/