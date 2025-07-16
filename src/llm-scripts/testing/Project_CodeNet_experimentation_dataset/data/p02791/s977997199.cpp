#include<bits/stdc++.h>
using namespace std;

#define FOR(i,s,e) for(int i=(s);(i)<(int)(e);++(i))
#define REP(i,e) FOR(i,0,e)
#define each(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define all(o) (o).begin(), (o).end()
#define psb(x) push_back(x)
#define ppb(x) pop_back(x)
#define mp make_pair
#define mt make_tuple
#define t0(t) get<0>((t))
#define t1(t) get<1>((t))
#define t2(t) get<2>((t))

typedef long long ll;
const int N = 200000;
int n;
int p[N];

int main() {
  fscanf(stdin, "%d ", &n);
  int res = 0, m = N;
  REP(i,n) {
    fscanf(stdin, "%d ", p+i);
    m = min(m, p[i]);
    if (p[i] <= m) res++;
  }
  fprintf(stdout, "%d\n", res); 
  return 0;
}
