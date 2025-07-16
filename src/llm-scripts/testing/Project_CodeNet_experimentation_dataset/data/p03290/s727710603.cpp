#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
const int MOD = 1e9+7;
const int MOOD = 998244353;
#define PI 3.14159265359
typedef long long ll;
using namespace std;

int dp[200000][11];

int main(){
	int d, g;
	cin >> d >> g;
	vector<int> p(d+1), c(d+1);
	g /= 100;
	for (int i = 0; i < 200000; i++){
		for (int j = 0; j <= 10; j++){
			dp[i][j] = MOD;
		}
	}

	for (int i = 1; i <= d; i++){
		cin >> p[i] >> c[i];
		c[i] /= 100;
	}
	dp[0][0] = 0;
	for (int i = 0; i <= g; i++){
		for (int j = 1; j <= d; j++){
			if (dp[i][j-1] != MOD){
				for (int k = 0; k < p[j]; k++){
					dp[i+j*k][j] = min(dp[i][j-1] + k, dp[i+j*k][j]);
				}
				dp[i+j*p[j]+c[j]][j] = min(dp[i][j-1] + p[j], dp[i+j*p[j]+c[j]][j]);
			}
		}
	}
	int ans = MOD;
	for (int i = g; i <= g+20000; i++){
		for (int j = 1; j <= d; j++){
			ans = min(ans, dp[i][j]);
		}
	}
	cout << ans << endl;
	return 0;
}