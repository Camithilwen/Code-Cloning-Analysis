
//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1144&lang=jp

#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<cmath>
#include<climits>
#include<ctime>
#include<cstring>
#include<numeric>

#define ALL(v) (v).begin(),(v).end()
#define REP(i,p,n) for(int i=p;i<(int)(n);++i)
#define rep(i,n) REP(i,0,n)
#define dump(a) (cerr << #a << "=" << (a) << endl)
#define DUMP(list) cout << "{ "; for(auto nth : list){ cout << nth << " "; } cout << "}" << endl;

using namespace std;

int W,H;
const int NONE=0, BLOCK=1, START=2, GOAL=3;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
int ans;
vector<vector<int>> field;

bool out_range(int x, int y){
	return x < 0 || y < 0 || x >= W || y >= H; 
}

void dfs(int x, int y, int depth)
{
	if(depth + 1 >= ans){ return; }
	
	REP( d, 0, 4 )
	{
		int nx = x + dx[d];
		int ny = y + dy[d];
		//次に移動する場所がBLOCKではなく、範囲内である。
		if(!out_range(nx,ny) && field[ny][nx] != BLOCK)
		{
			//エリア外に出るまで移動する
			while(!out_range(nx,ny))
			{
				//GOALならば、答えを更新する
				if(field[ny][nx] == GOAL)
				{
					ans = min(ans,depth+1);
					return;
				}

				//BLOCKならば、次の移動を行う
				if(field[ny][nx] == BLOCK)
				{
					field[ny][nx] = NONE;
					dfs(nx-dx[d], ny-dy[d], depth+1);
					field[ny][nx] = BLOCK;
					break;
				}

				nx = nx + dx[d];
				ny = ny + dy[d];
			}
		}
	}
	
	return;
}

int main()
{
	while(cin >> W >> H && W)
	{
		int sx,sy;
		field.assign(H,vector<int>(W));
		rep(y,H){
			rep(x,W){
				cin >> field[y][x];	
				if(field[y][x] == START){
					sx = x; 
					sy = y;
					field[y][x] = NONE;
				}
			}
		}
		ans = 11;
		dfs(sx,sy,0);	
		cout << ((ans <= 10) ? ans : -1) << endl;
	}
	return 0;
}