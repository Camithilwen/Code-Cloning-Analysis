#include<iostream>
#include<string>
using namespace std;

#define W 12
#define H 12

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
string mass[W];

void rec(int x, int y)
{
	int xx, yy;
	int i;
	mass[x][y] = '2';
	for (i = 0; i < 4; i++) {
		yy = y+dy[i];
		xx = x+dx[i];
		if (yy<0 || H<=yy || xx<0 || W<=xx) continue;
		if (mass[xx][yy]!='1') continue;
		rec(xx, yy);
	}
}

int main()
{
	int count, i, j;
	string c;

	while ( cin>>mass[0] ) {
		for (i = 1; i < W; i++)
			cin>>mass[i];

		count = 0;
		for (i = 0; i < W; i++) {
			for (j = 0; j < H; j++) {
				if (mass[i][j] != '1') continue;
				count++;
				rec(i, j);
			}
		}
		cout<<count<<endl;
	}

	return 0;
}