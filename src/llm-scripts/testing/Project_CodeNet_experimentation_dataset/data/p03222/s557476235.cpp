#include <iostream>
#include <vector>
using namespace std;
const int MOD = 1000000007;
int main(){
	int H, W, K;
	cin >> H >> W >> K;
	vector<vector<int>> dp(H + 1, vector<int>(W, 0));
	dp[0][0] = 1;
	for (int i = 0; i < H; i++){
		for (int j = 0; j < (1 << (W - 1)); j++){
			bool ok = true;
			for (int k = 0; k < W - 2; k++){
				if ((j >> k & 1) && (j >> (k + 1) & 1)){
					ok = false;
				}
			}
			if (ok){
				vector<int> p(W);
				for (int k = 0; k < W; k++){
					p[k] = k;
				}
				for (int k = 0; k < W - 1; k++){
					if (j >> k & 1){
						swap(p[k], p[k + 1]);
					}
				}
				for (int k = 0; k < W; k++){
					dp[i + 1][p[k]] += dp[i][k];
					dp[i + 1][p[k]] %= MOD;
				}
			}
		}
	}
	cout << dp[H][K - 1] << endl;
}