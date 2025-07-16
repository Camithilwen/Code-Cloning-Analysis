#include <iostream>
#include <string.h>
using namespace std;

const int dx[] = {1,0,-1,0};
const int dy[] = {0,1,0,-1};

int field[101][101];

int xs,ys,xg,yg;

void SetBlock(int c,int d,int x,int y)
{
	if(d==0){//横なが
		for(int ay=0;ay<2;++ay){
			for(int ax=0;ax<4;++ax){
				field[y+ay][x+ax] = c;
			}
		}
	}
	if(d==1){//縦なが
		for(int ay=0;ay<4;++ay){
			for(int ax=0;ax<2;++ax){
				field[y+ay][x+ax] = c;
			}
		}
	}
}

bool dfs(int x,int y)
{
	int c = field[y][x];
	field[y][x] = 0;
	if(x == xg && y == yg) return true;
	for(int i=0;i<4;++i){
		if(c==field[y+dy[i]][x+dx[i]])if(dfs(x+dx[i],y+dy[i]))return true;
	}
	return false;
}

int main(void)
{
	while(1){
		int w,h;
		int n;
		memset(field,0,sizeof(field));
		cin >> w >> h;
		if(w==0&&h==0)
			return 0;
		cin >> xs >> ys;
		cin >> xg >> yg;
		cin >> n;
		for(int i=0;i<n;++i){
			int c,d,x,y;
			cin >> c >> d >> x >> y;
			SetBlock(c,d,x,y);
		}
		if(field[ys][xs] == 0)
			cout << "NG" << endl;
		else
		{
			if(dfs(xs,ys))
				cout << "OK" << endl;
			else
				cout << "NG" << endl;
		}
	}
	return 0;
}