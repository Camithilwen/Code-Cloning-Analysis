#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
#define loop(i,a,b) for(int i=(a);i<ull(b);++i)
#define rep(i,n) loop(i,0,n)
#define all(a) (a).begin(), (a).end()

const double eps = 1e-10;
const double pi  = acos(-1.0);
const double inf = (int)1e8;

string field[12];
bool b[12][12];

int f(int x, int y){
	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, 1, 0, -1};
	for(int i=0; i< 4; i++){
		int nx = x+dx[i], ny=y+dy[i];
		if(!(0 <= nx && nx < 12 && 0 <= ny && ny < 12)) continue;
		if(field[nx][ny] == '1' && b[nx][ny]){
			b[nx][ny] = false;
			f(nx, ny);
		}
	}
}

int main(){
	while(cin >> field[0]){
		int ret = 0;
		for(int i=0; i <12; i++) for(int j=0; j < 12;j++) b[i][j] = true;
		for(int i=1; i< 12; i++) cin >> field[i];
		for(int i=0; i<12; i++){
			for(int j=0; j < 12; j++){
				if(field[i][j] == '1' && b[i][j]){
					b[i][j] = false;
					f(i, j);
					ret++;
				}
			}
		}
		cout << ret << endl;
	}
}