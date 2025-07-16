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
#include<bitset>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;

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
#define ll2(x, y) ll x, y; cin >> x >> y;
#define scn(n, a) rep(i, n)cin >> a[i]
#define sc2n(n, a, b) rep(i, n)cin >> a[i] >> b[i]
#define pri(x) cout << (x) << "\n"
#define pri2(x, y) cout << (x) << " " << (y) << "\n"
#define pri3(x, y, z) cout << (x) << " " << (y) << " " << (z) << "\n"
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(),(a).end()
#define endl "\n"
#define kabe puts("---------------------------")
#define kara puts("")
#define debug(x) cout << " --- " << (x) << "\n"
#define debug2(x, y) cout << " --- " << (x) << " " << (y) << "\n"
#define debug3(x, y, z) cout << " --- " << (x) << " " << (y) << " " << (z) << "\n"
#define X first
#define Y second
#define eps 0.0001
#define prid(x) printf("%.15lf\n", x)

string s;
int res = 0;
int cnt[3] = {0};

signed main(void){
  int i, j;
  for(int testcase = 0;testcase >= 0;testcase++){
    cin >> s;
    s += 'J';
    int mode = 1;

    rep(i, s.size()){
      if(mode == 1){
        if(s[i] == 'J')++cnt[0];
        else if(s[i] == 'O'){
          mode = 2; ++cnt[1];
        }else cnt[0] = 0;
      }else if(mode == 2){
        if(s[i] == 'J'){
          mode = 1;
          rep(j, 2)cnt[j] = 0;
          ++cnt[0];
        }else if(s[i] == 'O')++cnt[1];
        else{
          mode = 3; ++cnt[2];
        }
      }else{
        if(s[i] == 'J'){
          if(cnt[0] >= cnt[1] && cnt[1] <= cnt[2])res = max(res, cnt[1]);
          mode = 1;
          rep(j, 3)cnt[j] = 0;
          ++cnt[0];
        }else if(s[i] == 'O'){
          if(cnt[0] >= cnt[1] && cnt[1] <= cnt[2])res = max(res, cnt[1]);
          mode = 1;
          rep(j, 3)cnt[j] = 0;
        }else ++cnt[2];
      }
      //printf("%d %d %d %d %d\n", i, mode, cnt[0], cnt[1], cnt[2]);
    }
    pri(res);


/*/

//*/ break;
  }
  return 0;
}