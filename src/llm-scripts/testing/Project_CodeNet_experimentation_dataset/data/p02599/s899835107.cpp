#include <bits/stdc++.h>
 
const double pi = 3.141592653589793238462643383279;
using namespace std;
//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<long long, long long> PLL;
typedef pair<int, PII> TIII;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<LL> VLL;
typedef vector<VLL> VVLL;
 
 
//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define SQ(a) ((a)*(a))
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
 
 
//repetition
//------------------------------------------
#define FOR(i,s,n) for(int i=s;i<(int)n;++i)
#define REP(i,n) FOR(i,0,n)
#define MOD 1000000007
 
 
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
 
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)

#define EPS 1e-10
//ここから編集

struct Mo
{
  vector<int> left, right, order;
  vector<bool> v;
  int width;
  int nl, nr, ptr;

  Mo(int n, int q) : width(sqrt(n)), nl(0), nr(0), ptr(0), v(n), left(q), right(q){}

  void insert(int l, int r)
  {
    left[ptr] = l;
    right[ptr] = r;
    ptr++;
  }

  void build()
  {
    ptr =  0;
    order.resize(left.size());
    iota(all(order), 0);
    sort(all(order), [&](int a, int b)
    {
      if(left[a] / width != left[b] / width) return left[a] < left[b];
      else{
        if ((left[a] / width) % 2 == 0) return right[a] < right[b];
        else return right[a] > right[b];
      }
    });
  }

  inline int process()
  {
    const auto id = order[ptr];
    while(nl > left[id]) distribute(--nl);
    while(nr < right[id]) distribute(nr++);
    while(nl < left[id]) distribute(nl++);
    while(nr > right[id]) distribute(--nr);
    return order[ptr++];
  }

  inline void distribute(int idx)
  {
    v[idx].flip();
    if(v[idx])add(idx);
    else del(idx);
  }

  inline void add(int idx);

  inline void del(int idx);
};

int N, A[501010], Q;
int ans[501010];
int cnt[1010101], sum;

inline void Mo::add(int idx)
{
  if(cnt[A[idx]]++ == 0) ++ sum;
}

inline void Mo::del(int idx) 
{
  if(--cnt[A[idx]] == 0) --sum;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(6);

  scanf("%d %d", &N, &Q);
  for(int i=0; i<N; i++) scanf("%d", &A[i]);

  Mo mo(N,Q);
  for(int i=0; i<Q; i++){
    int a, b; scanf("%d %d", &a, &b);
    mo.insert(--a, b);
  }

  mo.build();
  for(int i=0; i<Q; i++){
    int idx = mo.process();
    ans[idx] = sum;
  }
  for(int i=0; i<Q; i++){
    printf("%d\n", ans[i]);
  }
  return 0;
}
