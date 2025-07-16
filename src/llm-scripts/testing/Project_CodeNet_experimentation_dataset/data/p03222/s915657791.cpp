#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <stack>
#include <vector>
#include <set>
#include <tuple>
#include <utility>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef tuple<int,int,int> T;
const int INF = 1000000000;
const int MOD = 1000000007;
int main(){
	int h,w,k;
	cin >> h >> w >> k;

	//前処理,0~w-2の辺があったとき,それぞれが隣り合った辺を選んでいない場合の数.

	map<int,int> mp;
	ll sum = 0;
	for(int i = 0;i < (1 << w-1);i++){
		vector<int> now;
		for(int j = 0;j < w-1;j++){
			if((i >> j) & 1)now.push_back(j);
		}

		bool flag = true;
		for(int j = 0;j < (int)now.size() - 1;j++){
			if(now[j+1] == now[j] + 1)flag = false; 
		}

		if(!flag)continue;
		for(int j = 0;j < now.size();j++)mp[now[j]]++;
		sum++;
	}

	vector<vector<vector<ll>>> dp(h+1,vector<vector<ll>>(w,vector<ll>(w,0)));
	for(int i = 0;i < w;i++)dp[0][i][i] = 1;

	for(int i = 0;i < h;i++){//今見ている高さ.
		for(int j = 0;j < w;j++){
			for(int k = 0;k < w;k++){
				//dp[i][j][k]:=高さiにおいてj->kとなる場合の数.
				//j-が取れる.
				if(k-1 >= 0){
					dp[i+1][j][k-1] += dp[i][j][k] * mp[k-1];
					dp[i+1][j][k-1] %= MOD;
				}
				if(k+1 <= w-1){
					dp[i+1][j][k+1] += dp[i][j][k] * mp[k];
					dp[i+1][j][k+1] %= MOD;
				}
				dp[i+1][j][k] += dp[i][j][k] * (sum - mp[k-1] - mp[k]);
				dp[i+1][j][k] %= MOD;
			}
		}
	}
	cout << dp[h][0][k-1] << endl;
}
