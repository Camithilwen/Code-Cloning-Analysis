#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 200010, INF = 1ll << 45;
int n,q,a,b,que[N];
struct node {
  pair<int,int> lmn,rmn;
  int l,r,tag;
} t[N << 2];
void puttag(int x,int val) {
  t[x].tag += val;
  t[x].lmn.first += val;
  t[x].rmn.first += val;
}
void push_down(int x) {
  puttag(x<<1,t[x].tag);
  puttag(x<<1|1,t[x].tag);
  t[x].tag = 0;
}
void push_up(int x) {
  if (t[x].tag) push_down(x);
  t[x].lmn = min(t[x<<1].lmn,t[x<<1|1].lmn);
  t[x].rmn = min(t[x<<1].rmn,t[x<<1|1].rmn);
}
void build(int l,int r,int x) {
  t[x].l = l, t[x].r = r;
  if (l == r) {
    t[x].lmn = make_pair(l,l);
    t[x].rmn = make_pair(n-l+1,l);
    return;
  }
  int mid = (l + r) >> 1;
  build(l,mid,x<<1);
  build(mid+1,r,x<<1|1);
  push_up(x);
}
int query(int p,int x) {
  if (t[x].l == t[x].r)
    return t[x].lmn.first - t[x].l;
  if (t[x].tag) push_down(x);
  int mid = (t[x].l + t[x].r) >> 1;
  if (p <= mid) return query(p,x<<1);
  else return query(p,x<<1|1);
}
void modify(int l,int r,int x,int val) {
  if (l > t[x].r || r < t[x].l) return;
  if (t[x].l >= l && t[x].r <= r) {
    t[x].lmn.first += val;
    t[x].rmn.first += val;
    t[x].tag += val;
    return;
  }
  if (t[x].tag) push_down(x);
  modify(l,r,x<<1,val);
  modify(l,r,x<<1|1,val);
  push_up(x);
}
pair<int,int> askl(int l,int r,int x) {
  if (l > t[x].r || r < t[x].l) return make_pair(INF,0);
  if (t[x].l >= l && t[x].r <= r)
    return t[x].lmn;
  if (t[x].tag) push_down(x);
  return min(askl(l,r,x<<1),askl(l,r,x<<1|1));
}
pair<int,int> askr(int l,int r,int x) {
  if (l > t[x].r || r < t[x].l) return make_pair(INF,0);
  if (t[x].l >= l && t[x].r <= r)
    return t[x].rmn;
  if (t[x].tag) push_down(x);
  return min(askr(l,r,x<<1),askr(l,r,x<<1|1));
}
void setval(int p,int x,int val) {
  if (t[x].l == t[x].r) {
    t[x].lmn.first = val + t[x].l;
    t[x].rmn.first = val + n - t[x].l + 1;
    return;
  }
  int mid = (t[x].l + t[x].r) >> 1;
  if (t[x].tag) push_down(x);
  if (p <= mid) setval(p,x<<1,val);
  else setval(p,x<<1|1,val);
  push_up(x);
}
signed main() {
  int tmp,t;
  scanf("%lld%lld%lld%lld",&n,&q,&a,&b);
  que[0] = a;
  build(1,n,1);
  for (int i = 1 ; i <= n ; ++ i)
    setval(i,1,abs(i-b));
  for (int i = 1 ; i <= q ; ++ i) {
    scanf("%lld",&que[i]);
    tmp = askl(que[i],n,1).first - que[i];
    t = askr(1,que[i],1).first - n + que[i] - 1;
    tmp = min(tmp,t);
    modify(1,n,1,abs(que[i-1] - que[i]));
    t = query(que[i-1],1);
    tmp = min(tmp,t);
    setval(que[i-1],1,tmp);
  }
  int ans = INF;
  for (int i = 1 ; i <= n ; ++ i)
    ans = min(ans,query(i,1));
  printf("%lld\n",ans);
  return 0;
}