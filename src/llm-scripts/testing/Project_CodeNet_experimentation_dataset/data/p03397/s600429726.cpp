#include <iostream>
#include <string>
#define llint long long
#define mod 1000000007

using namespace std;

string s;
llint dp[300005][2][2][2][3];

int main(void)
{
	cin >> s;
	s += "1";
	int n = s.size();
	s = "#" + s;
	
	dp[0][0][0][0][0] = 1;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 2; j++){
			for(int k = 0; k < 2; k++){
				for(int l = 0; l < 2; l++){
					for(int m = 0; m < 3; m++){
						if(s[i+1] != '1'){
							(dp[i+1][(j+1)%2][1][l][m] += dp[i][j][k][l][m]) %= mod;
						}
						if(s[i+1] != '0'){
							if(j % 2){
								(dp[i+1][0][0][l][m] += dp[i][j][k][l][m]) %= mod;
								continue;
							}
							int nm = m;
							if(k == 0){
								if(m == 0 && l % 2 == 0) nm = 1;
								else if(m == 1 && l % 2) nm = 2;
							}
							(dp[i+1][0][0][(l+1)%2][nm] += dp[i][j][k][l][m]) %= mod;
						}
					}
				}
			}
		}
	}
	llint ans = 0;
	for(int l = 0; l < 2; l++) ans += dp[n][0][0][l][2], ans %= mod;
	cout << ans << endl;
	
	return 0;
}