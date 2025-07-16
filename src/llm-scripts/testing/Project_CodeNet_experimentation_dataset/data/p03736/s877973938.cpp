#include<bits/stdc++.h>
#define FL "a"
using namespace std;
typedef long long ll;
const int mod=1e9+7;
const int N=2e5+10;
const ll INF=1ll<<60;
inline ll read(){
  ll d=0,w=1;char ch=getchar();
  while(ch!='-'&&(ch<'0'||ch>'9'))ch=getchar();
  if(ch=='-')w=-1,ch=getchar();
  while(ch<='9'&&ch>='0')d=d*10+ch-48,ch=getchar();
  return d*w;
}
inline void file(){
  freopen(FL".in","r",stdin);
  freopen(FL".out","w",stdout);
}

int n,q,x[N];
ll mnv[2][N<<2],lz[N<<2],ans=INF;//0:+ 1:-
#define ls (i<<1)
#define rs (i<<1|1)
#define mid ((l+r)>>1)
inline void update(int i){
  mnv[0][i]=min(mnv[0][ls],mnv[0][rs]);mnv[1][i]=min(mnv[1][ls],mnv[1][rs]);
}
inline void cover(int i,ll v){lz[i]+=v;mnv[0][i]+=v;mnv[1][i]+=v;}
inline void pushdown(int i){
  if(lz[i])cover(ls,lz[i]),cover(rs,lz[i]),lz[i]=0;
}
void build(int i,int l,int r){
  mnv[0][i]=mnv[1][i]=INF;if(l==r)return;build(ls,l,mid);build(rs,mid+1,r);
}
inline void insert(int i,int l,int r,int p,ll v){
  if(l==r){mnv[0][i]=min(mnv[0][i],v+p);mnv[1][i]=min(mnv[1][i],v-p);return;}
  pushdown(i);p<=mid?insert(ls,l,mid,p,v):insert(rs,mid+1,r,p,v);update(i);
}
inline ll query(int i,int l,int r,int x,int y,int p){
  if(x<=l&&r<=y)return mnv[p][i];pushdown(i);ll s=INF;
  if(x<=mid)s=query(ls,l,mid,x,y,p);
  if(mid<y)s=min(s,query(rs,mid+1,r,x,y,p));return s;
}

int main()
{
  n=read();q=read();x[0]=read();
  build(1,1,n);insert(1,1,n,read(),0);
  for(int i=1;i<=q;i++)x[i]=read();
  for(int i=1;i<=q;i++){
    ll ql=query(1,1,n,1,x[i],1)+x[i],qr=query(1,1,n,x[i],n,0)-x[i];
    cover(1,abs(x[i]-x[i-1]));insert(1,1,n,x[i-1],min(ql,qr));
  }
  for(int i=1;i<=n;i++)ans=min(ans,query(1,1,n,i,i,0)-i);
  printf("%lld\n",ans);return 0;
}
