#include <iostream>
#include <queue>
#include <map>

using namespace std;

typedef pair<int, int> P;

int B[101][101];

bool bfs(int w, int h, int xs, int ys, int xg, int yg);

int main(int argc, char** argv)
{
	int w, h;
	int xs, ys;
	int xg, yg;
	int n;
	int c, d, x, y;

	while( 1 )
	{
		cin >> w;
		cin >> h;
		if(w==0 && h==0) break;
		
		cin >> xs;
		cin >> ys;
		cin >> xg;
		cin >> yg;
		cin >> n;

		for(int i=0; i<n; i++)
		{
			cin >> c; cin >> d; cin >> x; cin >> y;
			if(d==0)
			{
				for(int dx=0; dx<4; dx++)
				{
					for(int dy=0; dy<2; dy++)
					{
						B[x+dx][y+dy] = c;
					}
				}
			}
			else
			{
				for(int dx=0; dx<2; dx++)
				{
					for(int dy=0; dy<4; dy++)
					{
						B[x+dx][y+dy] = c;
					}
				}
			}
		}

		cout << (bfs(w, h, xs, ys, xg, yg) ? "OK" : "NG") << endl;
	}

	return 0;
}

bool bfs(int w, int h, int xs, int ys, int xg, int yg)
{
	int x, y, c, xx, yy;
	int offset[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
	queue<P> q;
	P p;

	c = B[xs][ys];
	B[xs][ys] = 0;
	p.first = xs, p.second = ys;
	
	q.push(p);
	while(!q.empty())
	{
		p = q.front();
		q.pop();
		x = p.first;
		y = p.second;
		if(x==xg && y==yg) return true;
		B[x][y] = 0;

		for(int i=0; i<4; i++)
		{
			xx = x + offset[i][0];
			yy = y + offset[i][1];
			if(x>=1 && y>=1 && x<=w && y<=h)
			{
				if(B[xx][yy] == c)
				{
					p.first = xx;
					p.second = yy;
					q.push(p);
				}
			}
		}
	}

	return false;
}