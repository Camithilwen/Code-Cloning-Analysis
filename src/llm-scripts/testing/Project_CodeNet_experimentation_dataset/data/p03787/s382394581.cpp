#include<bits/stdc++.h>
#define Fst first
#define Snd second
#define RG register
#define mp make_pair
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
typedef long long LL;
typedef long double LD;
typedef unsigned int UI;
typedef unsigned long long ULL;
template<typename T> inline void read(T& x) {
	char c = getchar();
	bool f = false;
	for (x = 0; !isdigit(c); c = getchar()) {
		if (c == '-') {
			f = true;
		}
	}
	for (; isdigit(c); c = getchar()) {
		x = x * 10 + c - '0';
	}
	if (f) {
		x = -x;
	}
}
template<typename T, typename... U> inline void read(T& x, U& ... y) {
	read(x), read(y...);
}
const int N=1e5+10;
int n,m,p;
int head[N],vis[N],In[N];
bool Flag;
struct Edge {
  int to,last;
  Edge () {}
  Edge (int a,int b) :to(a),last(b) {}
}edge[N<<2];
void ADD(int a,int b) {
  edge[++p]=Edge(b,head[a]); head[a]=p;
  edge[++p]=Edge(a,head[b]); head[b]=p;
}
void DFS(int u,int c) {
  if(vis[u]) {
    if(vis[u]!=c) Flag=true;
    return;
  }
  vis[u]=c;
  for(int i=head[u];i;i=edge[i].last) {
    int v=edge[i].to;
    DFS(v,c^1);
  }
}
//#define rua
int main() {
//	ios::sync_with_stdio(false);
#ifdef rua
	freopen("GG.in","r",stdin);
#endif
  read(n,m);
  for(int i=1;i<=m;++i) {
    int u,v; read(u,v);
    ADD(u,v);
    ++In[u]; ++In[v];
  }
  LL A=0,B=0,C=0;
  for(int i=1;i<=n;++i) if(!vis[i]) {
    if(!In[i]) ++A;
    else {
      Flag=false;
      DFS(i,2);
      if(Flag) ++C;
      else ++B;
    }
  }
  printf("%lld\n",A*n+A*(n-A)+B*B*2+C*C+C*B*2);
  return 0;
}
