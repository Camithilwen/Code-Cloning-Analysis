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
const int INF=0x3f3f3f3f;
int M,seg[800002],tag[800002];
static inline void upt(int x){seg[x]=Min(seg[x<<1],seg[x<<1|1]);}
static inline void nodeCover(int x,int l,int val){seg[x]=l-val;tag[x]=val;}
static inline void dnt(int x,int l,int r)
{
  if(tag[x])
  {
    int mid=(l+r)/2;
    nodeCover(x<<1,l,tag[x]);nodeCover(x<<1|1,mid+1,tag[x]);
    tag[x]=0;
  }
}
static inline void segCover(int u,int v,int t,int x=1,int l=1,int r=M)
{
  if(u<=l&&r<=v){nodeCover(x,l,t);return;}
  dnt(x,l,r);int mid=(l+r)/2;
  if(u<=mid){segCover(u,v,t,x<<1,l,mid);}
  if(v>mid){segCover(u,v,t,x<<1|1,mid+1,r);}
  upt(x);
}
static inline int segQuery(int p,int x=1,int l=1,int r=M)
{
  if(l==r){return p-seg[x];}dnt(x,l,r);int mid=(l+r)/2;
  return p<=mid?segQuery(p,x<<1,l,mid):segQuery(p,x<<1|1,mid+1,r);
}
int main()
{
  int N=IN()+1,count=0,cur=1,left,right;M=IN();
  while(N--)
  {
    left=IN(),right=IN();count++;
    if(cur>=left&&cur<=right)segCover(cur,right,-INF),cur=right+1;
    else if(cur<left)segCover(left,right,segQuery(left-1));
    if(cur>M){puts("");while(N--){puts("-1");}return 0;}
    OUT(seg[1]+count);if(N==1){return 0;}
  }
}