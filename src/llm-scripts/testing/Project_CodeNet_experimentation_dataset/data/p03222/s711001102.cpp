#define _USE_MATH_DEFINES

#include <iostream>
#include <iomanip>
#include <stdio.h>

#include <sstream>
#include <algorithm>
#include <iterator>
#include <cmath>
#include <complex>

#include <string>
#include <cstring>
#include <vector>
#include <bitset>

#include <queue>
#include <set>
#include <map>
#include <stack>
#include <list>

#include <ctime>
////
//#include <random>//
/////////

typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;

////定数
const int INF = (int)1e9 + 10;
const LL MOD = (LL)1e9 + 7;
const LL LINF = (LL)4e18 + 20;
const LD PI = acos(-1.0);
const double EPS = 1e-9; 
/////////
using namespace::std;
void chmax(LL& a, LL b) {
	a = max(a, b);
}
void chmin(LL& a, LL b) {
	a = min(a, b);
}
//////////////

void solve() {
	int H, W, K;
	cin >> H >> W >> K;
	/*
	縦棒がW本ある。W-1個のあるなしで全探索。って
	*/

	//左付きで棒があるかないか
	vector<vector<bool>> BF;
	vector<int> BF_num;
	for (int s = 0; s < (1 << (W-1)); ++s) {
		int ter = s;
		vector<bool> res(W - 1);
		int cnt = 0;
		for (int i = 0; i < W-1; ++i) {
			if (ter & 1) {
				res[i] = true;
				cnt++;
			}
			else {
				res[i] = false;
			}
			ter /= 2;
		}
		bool flag = true;
		for (int i = 0; i < W - 1 - 1; ++i) {
			if (res[i] == true && res[i + 1] == true) {
				flag = false;
				break;
			}
		}
		if (flag == true) {
			BF.push_back(res);
			BF_num.push_back(cnt);
		}
	}

	/*
	H+1 * W * (K+1)個必要
	*/
	//高さと位置のみ
	vector<vector<LL>> dp(H + 1,vector<LL>(W, 0));
	dp[0][0] = 1;
	int BF_len = BF.size();
	for (int h = 0; h < H; ++h) {//上から順に
		//dp[h]->dp[h+1]
		for (int s = 0; s < BF_len; ++s) {//全ての横棒で
			vector<bool> B = BF[s];
			
			for (int w = 0; w < W; ++w) {
				//dp[h][k]
				if (w+1 <W && B[w] == true) {//右へ
					dp[h + 1][w + 1] += dp[h][w];
					dp[h + 1][w + 1] %= MOD;
				}
				else if (w - 1 >= 0 && B[w - 1] == true) {//左
					dp[h + 1][w - 1] += dp[h][w];
					dp[h + 1][w - 1] %= MOD;
				}
				else{//真下へ
					dp[h + 1][w] += dp[h][w];
					dp[h + 1][w] %= MOD;
				}
			}
		}
	}
	//[H][K-1]
	LL ans = dp[H][K-1];
	
	cout << ans << endl;
}

signed main(void) {
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);
	std::cout << std::fixed;//小数を10進数表示
	cout << setprecision(16);//小数点以下の桁数を指定//coutとcerrで別	

	solve();
}
