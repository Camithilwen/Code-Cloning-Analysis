#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <queue>
#include <utility>
#include <vector>
#include <set>
#include <memory.h>
#include <iomanip>
#include <bitset>
#include <list>
#include <stack>
#include <deque>
#include <numeric>

using namespace std;

#define mod 1000000007

// seiyaku[i][0] : 値iは行seiyaku[i][0]で最大値でないといけない
// seiyaku[i][1] : 値iは列seiyaku[i][0]で最大値でないといけない
int seiyaku[1000001][2] = {};

int main()
{
	int n, m;
	cin >> n >> m;
	long long int ans = 1;
	for(int i = 1; i <= n; i++){
		int a;
		cin >> a;
		if(seiyaku[a][0] > 0) ans = 0;
		else seiyaku[a][0] = i;
	}
	for(int i = 1; i <= m; i++){
		int b;
		cin >> b;
		if(seiyaku[b][1] > 0) ans = 0;
		else seiyaku[b][1] = i;
	}
	// i行目にはすでに最大値が埋められている
	bool alreadymax_g[1001];
	// i列目にはすでに最大値が埋められている
	bool alreadymax_r[1001];
	for(int i = 1; i <= n; i++){
		alreadymax_g[i] = false;
	}
	for(int i = 1; i <= m; i++){
		alreadymax_r[i] = false;
	}

	for(int i = n * m; i>= 1; i--){
		int g = seiyaku[i][0];
		int r = seiyaku[i][1];
		if(g > 0 && r > 0){
			// 行と列どちらにも制約がある(最大値となる)場合
			// g行目r列目にiを埋めないといけない
			if(alreadymax_g[g] || alreadymax_r[r]){
				ans = 0;
			} else {
				alreadymax_g[g] = true;
				alreadymax_r[r] = true;
			}
		} else if(g > 0 && r == 0){
			// 行にのみ制約がある場合
			// g行目に埋めることは確定しているが、列は確定していない
			if(alreadymax_g[g]){
				// g行目にすでに最大値が埋まっていたらアウト
				ans = 0;
			} else {
				alreadymax_g[g] = true;
				// g行目で制約を気にせず入れられるマスの数を求める
				int tmp = 0;
				for(int j = 1; j <= m; j++){
					if(alreadymax_r[j]) tmp++;
				}
				ans = (ans * tmp) % mod;
			}
		} else if(g == 0 && r > 0){
			// 列のみに制約がある場合
			// 上と同様
			if(alreadymax_r[r]){
				ans = 0;
			} else {
				alreadymax_r[r] = true;
				int tmp = 0;
				for(int j = 1; j <= n; j++){
					if(alreadymax_g[j]) tmp++;
				}
				ans = (ans * tmp) % mod;
			}
		} else {
			// 行にも列にも制約がない場合
			int tmp_g = 0;
			int tmp_r = 0;
			for(int j = 1; j <= n; j++){
				if(alreadymax_g[j]) tmp_g++;
			}
			for(int j = 1; j <= m; j++){
				if(alreadymax_r[j]) tmp_r++;
			}
			ans =(ans * (tmp_r * tmp_g - (n * m - i))) % mod;
		}
	}
	cout << ans << endl;
}