#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi=vector<int>;
using vvi=vector<vi>;
using vl=vector<ll>;
using vvl=vector<vl>;
using vb=vector<bool>;
using vvb=vector<vb>;
using pii = pair<int,int>;
using pli = pair<ll,int>;
using pll = pair<ll,ll>;
using vpii = vector<pii>;
using vpli = vector<pli>;
using vpll = vector<pll>;

#define rep(i, n) for(int i=0;i<(int)n;i++)
#define rep2(i, s, n) for(int i=(s);i<(int)n;i++)
int INF=1e9+7;

int main() {
  int A,B,M;
  cin >> A >> B >> M;
  vi a(A),b(B),x(M),y(M),c(M);
  int mina=INF,minb=INF;
  rep(i,A) {
    cin >> a[i];
    mina=min(mina,a[i]);
  }
  rep(i,B) {
    cin >> b[i];
    minb=min(minb,b[i]);
  }
  rep(i,M) {
    cin >> x[i] >> y[i] >> c[i];
    x[i]--;y[i]--;
  }
  
  int ans=mina+minb;
  rep(i,M)
    ans=min(ans,a[x[i]]+b[y[i]]-c[i]);
  
  cout << ans << endl;
}