#include<bits/stdc++.h>
using namespace std;
using i64 = long;
struct BitVector
{
  vector<uint64_t> v;
  vector<int> r;
  BitVector(){}
  void build(){
    r.assign((int)v.size() + 1, 0);
    for(int i = 0; i < (int)v.size(); ++i)
      r[i + 1] = r[i] + __builtin_popcountll(v[i]);
  }
  bool access(int x){
    return (v[x >> 6] >> (x & 63)) & 1;
  }
  // [0, x)の1の出現回数
  int rank(int x){
    return r[x >> 6] + __builtin_popcountll(v[x >> 6] & ((1uLL << (x & 63)) - 1));
  }
  int rank(int x, bool fl){
    return fl ? rank(x) : x - rank(x);
  }
};
template <typename T, int W>
struct WaveletMatrix
{

  array<BitVector, W> bv;
  array<int, W> zero_cnt;

  WaveletMatrix(vector<T>& a){
    int n = a.size();
    vector<T> v(a);
    for(int i = W - 1; i >= 0; --i){
      vector<uint64_t> b((n >> 6) + 1, 0);
      vector<T> v1, v2;
      for(int j = 0; j < n; ++j){
        ((v[j] >> i) & 1 ? v2 : v1).push_back(v[j]);
        b[j >> 6] |= uint64_t((v[j] >> i) & 1) << (j & 63);
      }
      for(int j = 0; j < (int)v.size(); ++j)
        v[j] = (j < (int)v1.size() ? v1[j] : v2[j - (int)v1.size()]);
      bv[i].v = move(b);
      bv[i].build();
      zero_cnt[i] = bv[i].rank(n, 0);
    }
  }

  // [l, r)内のxの数
  int count(int l, int r, T x){
    for(int i = W - 1; i >= 0; --i){
      bool fl = (x >> i) & 1;
      int st = bv[i].rank(l, fl);
      int en = bv[i].rank(r, fl);
      l = (fl ? zero_cnt[i] : 0) + st;
      r = (fl ? zero_cnt[i] : 0) + en;
    }
    return r - l;
  }

  // [l, r)内で[0, x)を満たす値の数
  int count_lower(int l, int r, T x){
    int cnt = 0;
    for(int i = W - 1; i >= 0; --i){
      bool fl = (x >> i) & 1;
      int st = bv[i].rank(l, fl);
      int en = bv[i].rank(r, fl);
      if(fl){
        st += zero_cnt[i];
        en += zero_cnt[i];
        cnt += (bv[i].rank(r, 0) - bv[i].rank(l, 0));
      }
      l = st, r = en;
    }
    return cnt;
  }

  // [l, r)内で[x, y)を満たす値の数
  int count_range(int l, int r, T x, T y){
    return count_lower(l, r, y) - count_lower(l, r, x);
  }

  // 0-indexedでk番目に小さいものを返す
  T kth_min(int l, int r, int k){
    T ans = 0;
    for(int i = W - 1; i >= 0; --i){
      int st = bv[i].rank(l, 0);
      int en = bv[i].rank(r, 0);
      if(en - st <= k){
        k -= en - st;
        l = zero_cnt[i] + bv[i].rank(l, 1);
        r = zero_cnt[i] + bv[i].rank(r, 1);
        ans |= (1uLL << i);
      }
      else{
        l = st, r = en;
      }
    }
    return ans;
  }

  // [l, r)でのx以上最小値
  pair<T, bool> predecessor(int l, int r, T x){
    int idx = count_lower(l, r, x);
    if(idx == r - l){
      return make_pair((1uLL << W) - 1, false);
    }
    return make_pair(kth_min(l, r, idx), true);
  }

  // [l, r)でのx以下最大値
  pair<T, bool> successor(int l, int r, T x){
    int idx = count_lower(l, r, x + 1);
    if(idx == 0)
      return make_pair(0, false);
    return make_pair(kth_min(l, r, idx - 1), true);
  }
};
#define rep(i,N) for(int i=0;i<(int)N;i++)
static inline void PUT(char c)
{
  static char buf[1<<15],*ptr=buf;
  if(ptr==buf+strlen(buf)||c==0){fwrite(buf,1,ptr-buf,stdout),ptr=buf;}*ptr++=c;
}
static inline int IN(void)
{
  int x=0,f=0,c=getchar();while(c<48||c>57){f^=c==45,c=getchar();}
  while(c>47&&c<58){x=x*10+c-48,c=getchar();}return f?-x:x;
}
static inline void OUT(int a)
{
  if(a<0)PUT('-'),a=-a;
  int d[40],i=0;do{d[i++]=a%10;}while(a/=10);
  while(i--){PUT(d[i]+48);}PUT('\n');
}
int main()
{
  int N=IN(),Q=IN(),mn=N,mx=0,C[N],temp[N];
  vector<int>direction(N);
  rep(i,N){C[i]=IN();mn=mn<C[i]?mn:C[i];mx=mx>C[i]?mx:C[i];temp[i]=N;}
  rep(i,N){direction[N-1-i]=temp[C[N-1-i]-1];temp[C[N-1-i]-1]=N-1-i;}
  WaveletMatrix<int,20> wm(direction);
  while(Q--){int l=IN()-1,r=IN();OUT(wm.count_range(l,r,r,N+1));}
}