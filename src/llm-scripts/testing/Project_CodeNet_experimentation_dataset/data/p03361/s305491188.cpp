#include<bits/stdc++.h>
using namespace std;

int H, W;

const int di[] = {1, -1, 0, 0};
const int dj[] = {0, 0, 1, -1};

int main(void){
	cin >> H >> W;
	vector<vector<char>> m(H+2, vector<char>(W+2));
	for(int i = 1; i <= H; i++){
		for(int j = 1; j <= W; j++){
			cin >> m[i][j];
		}
	}
	bool ans = true;
	for(int i = 1; i <= H; i++){
		for(int j = 1; j <= W; j++){
			if(m[i][j] == '#'){
				if(m[i-1][j] == '.' && m[i+1][j] == '.' && m[i][j-1] == '.' && m[i][j+1] == '.') ans = false;
			}
		}
	}
	if(ans) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
