#include<iostream>
#include<algorithm>
#include<climits>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<string>
#include<cstring>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<bitset>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<long long, int> ll_i;

#define PI 3.141592653589793238462643383279
#define mod 1000000007LL
#define rep(i, n) for(i = 0;i < n;++i)
#define rep1(i, n) for(i = 1;i < n;++i)
#define per(i, n) for(i = n - 1;i > -1;--i)
#define int(x) int x; scanf("%d",&x)
#define int2(x, y) int x, y; scanf("%d%d",&x, &y)
#define int3(x, y, z) int x, y, z; scanf("%d%d%d",&x, &y, &z)
#define int4(v, x, y, z) int v, x, y, z; scanf("%d%d%d%d", &v, &x, &y, &z)
#define int5(v, w, x, y, z) int v, w, x, y, z; scanf("%d%d%d%d%d", &v, &w, &x, &y, &z)
#define pri(x) cout << (x) << "\n"
#define pri2(x, y) cout << (x) << " " << (y) << "\n"
#define pri3(x, y, z) cout << (x) << " " << (y) << " " << (z) << "\n"
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(),(a).end()
#define kabe puts("---------------------------")
#define kara puts("")
#define debug(x) cout << " --- " << (x) << "\n"
#define debug2(x, y) cout << " --- " << (x) << " " << (y) << "\n"
#define debug3(x, y, z) cout << " --- " << (x) << " " << (y) << " " << (z) << "\n"
#define X first
#define Y second
#define eps 0.0001
#define prid(x) printf("%.15lf\n", x)

pair<int, i_i> tab[100];

bool xsort(pair<int, i_i> qwe, pair<int, i_i> rty){
  return qwe.X > rty.X;
}
bool ysort(pair<int, i_i> qwe, pair<int, i_i> rty){
  return qwe.Y.X < rty.Y.X;
}

signed main(void){
  int i, j;
  for(int testcase = 0;testcase >= 0;testcase++){
    int(n);
    rep(i, n)tab[i] = mp(0, mp(i, 0));
    rep(i, n * (n - 1) / 2){
      int4(a, b, c, d);
      --a; --b;
      if(c == d){
        ++tab[a].X;
        ++tab[b].X;
      }else if(c > d){
        tab[a].X += 3;
      }else{
        tab[b].X += 3;
      }
    }
    sort(tab, tab + n, xsort);
    tab[0].Y.Y = 1;
    rep1(i, n){
      if(tab[i - 1].X == tab[i].X)tab[i].Y.Y = tab[i - 1].Y.Y;
      else tab[i].Y.Y = i + 1;
    }
    sort(tab, tab + n, ysort);
    rep(i, n)pri(tab[i].Y.Y);



/*/

//*/ break;
  }
  return 0;
}