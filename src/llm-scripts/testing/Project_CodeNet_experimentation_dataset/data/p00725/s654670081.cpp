//include
//------------------------------------------
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <climits>
#include <queue>

using namespace std;

//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;

//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())

//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

//constant
//--------------------------------------------
const double EPS = 1e-10;
const double PI  = acos(-1.0);

int tab[30][30];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};
int W, H;
int Gx, Gy;

bool out(int x, int y){
  return !(0 <= x && x < W && 0 <= y && y < H);
}

int dfs(int x, int y, int d){
  if(d > 10) return d;

  int res = 11;
  REP(i,4){
	int tx = x+dx[i], ty = y+dy[i];
	if(out(tx,ty) || tab[ty][tx] != 0)
	  continue;
	
	while(!out(tx,ty) && tab[ty][tx] == 0){
	  if(tx == Gx && ty == Gy)
		return d+1;
	  tx += dx[i], ty += dy[i];
	}
	if(out(tx,ty)) continue;

	tab[ty][tx] = 0;
	res = min(res, dfs(tx-dx[i], ty-dy[i], d+1));
	tab[ty][tx] = 1;
  }
  return res;
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  while(cin>>W>>H,W){
	fill((int*)tab,(int*)tab+30*30,0);
	int sx, sy;
	REP(y,H) REP(x,W){
	  cin >> tab[y][x];
	  if(tab[y][x] == 2)
		sx = x, sy = y, tab[y][x] = 0;
	  if(tab[y][x] == 3)
		Gx = x, Gy = y, tab[y][x] = 0;
	}
	int ans = dfs(sx, sy, 0);
	if(ans > 10) cout << -1 << endl;
	else cout << ans << endl;
  }
  
  return 0;
}