#include<iostream>
#include<iomanip>
#include<queue>
#include<string>
#include<stack>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<cassert>
#include<ctime>
#include<algorithm>
#include<utility>
#include<map>
#include<set>
#include<vector>
#include<functional>

using namespace std;

#ifdef DEBUG
#define dprintf      printf
#define dout(x)      cout<<#x" = "<<(x)<<endl
#define darray(x,n)    {int i;rep(i,n)cout<<#x"["<<i<<"] = "<<*((x)+i)<<endl;}
#define dloop(i,s,g) for((i)=(s);(i)<(g);(i)++)
#define drep(i,n)    for((i)=0;(i)<(n);(i)++)
#define dstop()      scanf("%*c")
#else
#define dprintf      (1)?0:printf
#define dout(x)
#define darray(x,n)
#define dloop(i,s,g) if(1){}else
#define drep(i,n)    if(1){}else
#define dstop()      if(1){}else
#endif

#define F    first
#define S    second
#define pb   push_back
#define mp   make_pair

#define loop(i,s,g) for((i)=(s);(i)<(g);(i)++)
#define rep(i,n)    for((i)=0;(i)<(n);(i)++)
#define all(x)      (x.begin(),x.end())
#define in(T,...) T __VA_ARGS__; impl(__VA_ARGS__);
#define array(T,id,n) T id[n]; rep(i,n)cin>>id[i];

//#define int long long;
#ifndef int
#define INF  (0x7fffffff)
#else
#define LINF (0x7fffffffffffffff)
#endif

typedef  long long           ll;
typedef  unsigned            ui;
typedef  unsigned long long  ull;
typedef  pair<int,int>       i_i;
typedef  pair<ll,int>        ll_i;
typedef  pair<ll,ll>         ll_ll;
typedef  pair<double,int>    d_i;
typedef  pair<double,double> d_d;

void impl(){};
template <typename T,typename... TS >
void impl(T &head,TS &... tail)
{
  cin>>head;
  impl(tail ...);
}
#define UNION_FIND_MAX_N (112345)
int union_find_par[UNION_FIND_MAX_N];
int union_find_rank[UNION_FIND_MAX_N];

void init(int n)
{
  int i;
  for(i=0;i<n;i++)
    {
      union_find_par[i]=i;
      union_find_rank[i]=0;
    }
}

int find(int x)
{
  if(union_find_par[x]==x)
    return x;
  else
    return union_find_par[x]=find(union_find_par[x]);
}

void unite(int x,int y)
{
  x=find(x);
  y=find(y);
  if(x==y)
    return;
  if(union_find_rank[x]<union_find_rank[y])
    union_find_par[x]=y;
  else
    union_find_par[y]=x;
  if(union_find_rank[x]==union_find_rank[y])
    union_find_rank[x]++;
}

int nsame(int x,int y)
{
  return find(x)!=find(y);
}

typedef struct edge
{
  int u;
  int v;
  int cost;
  bool operator>(const edge&right)const
  {
    return cost>right.cost;
  }
  bool operator<(const edge&right)const
  {
    return cost<right.cost;
  }
}Edge;

signed main(void)
{
  int n;
  Edge edge[112345]={};
  int i,j,k=0;
  int sum=0;
  cin>>n;
  init(n);
  rep(i,n)rep(j,n)
    {
      cin>>edge[k].cost;
      edge[k].u=i;
      edge[k].v=j;
      k++;
    }
  sort(edge,edge+k);
  rep(i,k)
    if(edge[i].cost!=-1)
      if(nsame(edge[i].u,edge[i].v))
	unite(edge[i].u,edge[i].v),sum+=edge[i].cost;
  
  cout<<sum<<endl;    
  return 0;
}