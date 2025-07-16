#include <bits/stdc++.h>
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define rrep(i,a,b) for(int i=int(a);i>int(b);--i)
using namespace std;
using ll = long long;

int p[2][200010];
map<int, int> mp[200010];

void init(int t, int n){
  rep(i,n) p[t][i]=i;
}

int root(int t, int x){
  if(p[t][x]==x) return x;
  else return p[t][x]=root(t,p[t][x]);
}

bool same(int t, int x, int y){
  return root(t,x)==root(t,y);
}

void unite(int t, int x, int y){
  x = root(t,x);
  y = root(t,y);
  if(x==y) return;

  p[t][x] = y;
}

int main()
{
  int N,K,L;
  cin >> N >> K >> L;

  init(0,N);
  init(1,N);

  int p,q;
  rep(i,K){
    cin >> p >> q;
    unite(0,p-1,q-1);
  }
  rep(i,L){
    cin >> p >> q;
    unite(1,p-1,q-1);
  }

  rep(i,N) mp[root(0,i)][root(1,i)]++;
  rep(i,N) cout << mp[root(0,i)][root(1,i)] << ((i==N-1)?"\n":" ");
}
