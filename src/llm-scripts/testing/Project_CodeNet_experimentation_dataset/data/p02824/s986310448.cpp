#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;

void ins() {}
template<class T,class... Rest>void ins(T& v,Rest&... rest){cin>>v;ins(rest...);}
#define _overload3(_1,_2,_3,name,...) name
#define _rep2(i,n) for(int i=0,_i=(n);i<_i;++i)
#define _rep3(i,a,b) for(int i=(a),_i=(b),_ii=(b)>(a)?1:-1;abs(_i-i)>0;i+=_ii)
#define rep(...) _overload3(__VA_ARGS__,_rep3,_rep2)(__VA_ARGS__)
#define all(f,c,...) (([&](decltype((c)) cccc) { return (f)(begin(cccc), end(cccc), ## __VA_ARGS__); })(c))

signed main() {
  ll N, M, V, P;
  ins(N, M, V, P);

  vector<ll> A(N);
  rep(i, N)
    cin >> A[i];
  all(sort, A); all(reverse, A);

  int ok = -1, ng = N;
  auto f = [&](int mid) {
    if (mid < P) return true;
    if (A[P-1] > A[mid]+M) return false;

    ll tmp = 1LL * ((N-mid)+P-1) * M;
    rep(i, P-1, mid)
      tmp += min(1LL*M, max(0LL, A[mid]+M-A[i]));
    return tmp >= M*V;
  };
  while (abs(ok - ng) > 1) {
    int mid = ok + (ng-ok) / 2;
    (f(mid) ? ok : ng) = mid;
  }
  cout << ok+1 << endl;
  return 0;
}
