#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int h, w;
	cin >> h >> w;
	vector<vector<vector<int>>>grid(h + 2, vector<vector<int>>(w + 2, vector<int>(2, 0)));
	vector<vector<int>>blacks(0, vector<int>(2));
	for (int i = 1; i < h + 1; i++) {
		for (int j = 1; j < w + 1; j++) {
			char s; cin >> s;
			if (s == '.')grid.at(i).at(j).at(0) = 1;
			else {
				grid.at(i).at(j).at(0) = 2;
				blacks.push_back({ i,j });
			}
			grid.at(i).at(j).at(1) = -1;
		}
	}
	int ct = 1;
	vector<vector<int>>bw(0, vector<int>(2,0));
	int btmp = 0;
	int wtmp = 0;
	for (int i = 0; i < blacks.size(); i++) {
		int x = blacks.at(i).at(0);
		int y = blacks.at(i).at(1);
		if (grid.at(x).at(y).at(1) != -1)continue;
		queue<pair<int, int>>sq;
		sq.push({ x,y });
		while (sq.size() > 0) {
			int xq = sq.front().first;
			int yq = sq.front().second;
			grid.at(xq).at(yq).at(1) = ct;
			int cl = grid.at(xq).at(yq).at(0);
			if (cl == 1) {
				cl++;
				wtmp++;
			}
			else {
				cl--;
				btmp++;
			}
			vector<int>xqa = { xq,xq,xq - 1,xq + 1 };
			vector<int>yqa = { yq - 1,yq + 1,yq,yq };
			for (int i = 0; i < 4; i++) {
				if (grid.at(xqa.at(i)).at(yqa.at(i)).at(0) == cl&& grid.at(xqa.at(i)).at(yqa.at(i)).at(1)== -1) {
					grid.at(xqa.at(i)).at(yqa.at(i)).at(1) = ct;
					sq.push({ xqa.at(i),yqa.at(i) });
				}
			}
			sq.pop();
		}
		bw.push_back({ btmp, wtmp });
		btmp = 0;
		wtmp = 0;
		ct++;
	}
	ll ans = 0;
	for (int i = 0; i < bw.size(); i++)ans += (ll)bw.at(i).at(0) * bw.at(i).at(1);
	cout << ans << endl;
}