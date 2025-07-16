#define _USE_MATH_DEFINES
#define INF 100000000

#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <stack>
#include <limits>
#include <map>
#include <string>
#include <cstring>
#include <set>
#include <deque>
#include <bitset>
#include <list>
#include <cctype>
#include <utility>

using namespace std;

typedef long long ll;
typedef pair <int,int> P;


static const double EPS = 1e-8;

char stage[20][20];

int tx[] = {-1,0,1,0};
int ty[] = {0,1,0,-1};

class Data{
public:
	char dx;
	char dy;
	char stage[20][20];
	Data(char dx,char dy,char stage[20][20]){
		this->dx = dx;
		this->dy = dy;
		memcpy(this->stage,stage,sizeof(char)*(20*20));
	}
};


typedef pair <int,Data> PP;

int main(){

	int w,h;
	char sx,sy,gx,gy;
	while(~scanf("%d %d",&w,&h)){
		if(w==h && h==0) break;

		for(int y=0;y<h;y++){
			for(int x=0;x<w;x++){
				int n;
				scanf("%d",&n);
				stage[y][x] = n;

				if(stage[y][x]==2){
					sx=x;
					sy=y;
				}
				else if(stage[y][x]==3){
					gx=x;
					gy=y;
				}
			}
		}

		queue<PP> que;

		que.push(PP(0,Data(sx,sy,stage)));

		int res = 11;
		while(!que.empty()){
			int c = que.front().first;

			int qx = que.front().second.dx;
			int qy = que.front().second.dy;

			char tmpStage[20][20];
			memcpy(tmpStage,que.front().second.stage,sizeof(char)*(20*20));

			que.pop();

			for(int i=0;i<4;i++){
				for(int d=1;d<=max(w,h);d++){
					int dx = qx + tx[i]*d;
					int dy = qy + ty[i]*d;
					if(dx < 0 || dx >= w || dy < 0 || dy >= h) break;
					if(d==1 && tmpStage[dy][dx] == 1) break;

					if(tmpStage[dy][dx] == 1){
						
						char mx = dx - tx[i];
						char my = dy - ty[i];

						if(c+1 <= 10){
							//cost[my][mx] = c+1;
							tmpStage[dy][dx] = 0;
							que.push(PP(c+1,Data(mx,my,tmpStage)));	
							//cout << mx << " " << my << endl;
							tmpStage[dy][dx] = 1;
						}
						
						break;
					}
					else if(tmpStage[dy][dx] == 3){
						if(c+1 <= 10){
							res = min(res,c+1);
						}
						break;
					}
				}

			}
		}

		printf("%d\n", res > 10 ? -1 : res);
	}
}