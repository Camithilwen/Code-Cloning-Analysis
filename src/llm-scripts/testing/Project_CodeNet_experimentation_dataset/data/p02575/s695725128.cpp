#include<stdio.h>
#include<string.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
static inline int Min(int a,int b){return a<b?a:b;}
const int N=2e5+1,M=(N<<2),oo=(~0u>>2);
int n,m,mn[M],z[M],t[M],g[M],ql,qr,qx;
static inline void pu(int x){z[x]=z[x*2];t[x]=t[x*2+1];mn[x]=Min(mn[x*2],mn[x*2+1]);}
static inline void build(int x,int l,int r){if(l==r){z[x]=l;t[x]=l;return;}int m=(l+r)/2;build(x*2,l,m);build(x*2+1,m+1,r);pu(x);}
static inline void pt(int x,int w,int r){g[x]=w;t[x]=w;z[x]=w;if(w<=m){mn[x]=w-r;}else{mn[x]=oo;}}
static inline void upd(int x,int l,int r)
{
  if(z[x]>qr||t[x]<ql){return;}if(z[x]>=ql&&t[x]<=qr){pt(x,qr+1,r);return;}
  int m=(l+r)/2;if(g[x]){pt(x*2,g[x],m);pt(x*2+1,g[x],r);g[x]=0;}upd(x*2,l,m);upd(x*2+1,m+1,r);pu(x);
}
int main()
{
  n=IN(),m=IN();build(1,1,m);
  for(int i=0;i<n;i++){ql=IN(),qr=IN();upd(1,1,m);if(mn[1]>m){puts(""),puts("-1");}else{OUT(mn[1]+i+1);}}
}