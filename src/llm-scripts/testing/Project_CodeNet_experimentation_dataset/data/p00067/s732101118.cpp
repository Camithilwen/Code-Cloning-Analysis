#include <cmath>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <iomanip>
#include <cstdio>
#include <cctype>
#include <queue>
#include <complex>
#include <climits>

typedef long long ll;

using namespace std;

char field[12][12];

void dfs(int x, int y){
	field[x][y] = '0';
	for(int dx=-1; dx<=1; ++dx){
		for(int dy=-1; dy<=1; ++dy){
			if(dx != 0 && dy != 0) continue;
			int nx = x+dx, ny = y+dy;
			if(0 <= nx && nx < 12 && 0 <= ny && ny < 12 && field[nx][ny] == '1'){
				dfs(nx,ny);
			}
		}
	}
}

int main(void){
	while(1){
		if(cin >> field[0][0] == 0) break;
		for(int i=0; i<12; ++i){
			for(int j=0; j<12; ++j){
				if(i==0&&j==0)continue;
				cin >> field[i][j];
			}
		}
			
		int count = 0;

		for(int i=0; i<12; ++i){
			for(int j=0; j<12; ++j){
				if(field[i][j] == '1'){
					dfs(i, j);
					count++;
				}
			}
		}

		cout << count << endl;

	}
	return 0;
}