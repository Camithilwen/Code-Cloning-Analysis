#include<bits/stdc++.h>
using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main() {
	int h, w; cin >> h >> w;
	char s[h+2][w+2];
	for(int i = 0; i < w+2; i++) s[0][i] = '.';
	for (int i = 1; i <= h; i++)
	{
		s[i][0] = '.';
		for (int j = 1; j <= w; j++)
		{
			cin >> s[i][j];
		}
		s[i][h+1] = '.';
	}
	for(int i = 0; i < w+2; i++) s[h+1][i] = '.';

	bool res = true;
	for (int i = 1; i <= h; i++)
	{
		for (int j = 1; j <= w; j++)
		{
			if(s[i][j] == '.') continue;
			bool tmp = false;
			for (int k = 0; k < 4; k++)
			{
				if(s[i+dx[k]][j+dy[k]] == '#')
					tmp = true;
			}
			if(!tmp) res = false;
		}
	}

	if(res) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
