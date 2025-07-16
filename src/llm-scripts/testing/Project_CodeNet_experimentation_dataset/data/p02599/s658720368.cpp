#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define rep(i,N) for(int i=0;i<(int)N;i++)
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
int N=0;
static inline void Add(int *fwt,int i,int v){while(i<N){fwt[i]+=v;i|=i+1;}}
static inline int Sum(int *fwt,int i){int v=0;while(i>=0){v+=fwt[i];i=(i&(i+1))-1;}return v;}
int main()
{
  N=IN();int Q=IN(),after[500001],dat[500000],fenwick[500000],id[500001],left[500001],pos[500000],result[500000];
  rep(i,N){dat[i]=IN()-1;}
  rep(i,Q){left[i+1]=IN()-1;int r=IN()-1;after[i+1]=id[r];id[r]=i+1;}
  for(int r=0;r<N;r++)
  {
    if(pos[dat[r]]){Add(fenwick,pos[dat[r]]-1,-1);}
    Add(fenwick,r,1);
    for(int i=id[r];i;i=after[i]){result[i-1]=Sum(fenwick,r)-Sum(fenwick,left[i]-1);}
    pos[dat[r]]=r+1;
  }
  rep(i,Q){OUT(result[i]);}
}