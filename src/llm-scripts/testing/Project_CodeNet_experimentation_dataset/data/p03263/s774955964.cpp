#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(int)(n); i++)

using namespace std;

int main(){
	int H, W;
	cin >> H >> W;
	int a[510][510];
	rep(i,H){
		rep(j,W) cin >> a[i][j];
	}
	int ans=0;
	vector<int> ys, xs, yg, xg;
	rep(i,H){
		rep(j,W){
			if(i==H-1 && j==W-1) break;
			if(a[i][j]%2==1){
				ans++;
				if(j!=W-1){
					a[i][j]--;
					a[i][j+1]++;
					ys.emplace_back(i+1);
					xs.emplace_back(j+1);
					yg.emplace_back(i+1);
					xg.emplace_back(j+2);
				}
				else{
					a[i][j]--;
					a[i+1][j]++;
					ys.emplace_back(i+1);
					xs.emplace_back(j+1);
					yg.emplace_back(i+2);
					xg.emplace_back(j+1);
				}
			}
		}
	}
	cout << ans << endl;
	rep(i,ans) cout << ys[i] << " " << xs[i] << " "
	<< yg[i] << " " << xg[i] << endl;

	return 0;
}