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

int main() {
  int h, w;
  fscanf(stdin, "%d%d ", &h, &w);
  multiset<int> hd; // horizontal distance between from start to current position
  map<int, int> hdmap; // (current column, start column) to obtain the answer in log(n)
  REP(i,w) {
    hdmap[i] = i;
    hd.insert(0);
  }
  REP(i,h) {
    int l, r;
    fscanf(stdin, "%d%d ", &l, &r);
    --l; // semiopen interval [l-1, r) based on 0-index
    auto it = hdmap.lower_bound(l);
    int re = -1;
    while (it != hdmap.end() && it->first <= r) {
      re = max(re, it->second);
      hd.erase(hd.find(it->first - it->second));
      hdmap.erase(it++);
    }
    // the only optimal start point in [l-1, r) remains
    if (re != -1 && r < w) {
      hd.insert(r-re);
      hdmap[r] = re;
    }
    int res = -1;
    if (hd.size()) res = *hd.begin() + (i+1);
    fprintf(stdout, "%d\n", res);
  }
  return 0;
}
