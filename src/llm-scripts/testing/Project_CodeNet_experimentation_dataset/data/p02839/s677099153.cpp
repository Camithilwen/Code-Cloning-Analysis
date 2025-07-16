#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<ll> vl ;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;

#define rep(i,N) for(int i=0; i < (int)N; i++)
#define all(v) (v).begin(),(v).end()
#define chor(x,y) x = (x||y);

const int INF = 1001001001;

int main(){
	int h ,w; cin >> h >> w;
	vector<vi>a, b, c; a = b = c = vector<vi>(h, vi(w));
	rep(i,h) rep(j,w) cin >> a[i][j];
	rep(i,h) rep(j,w) cin >> b[i][j];
	rep(i,h) rep(j,w) c[i][j] =  a[i][j] - b[i][j];
	int bias = 7000;
	vector<vector<vector<bool>>> dp(h,vector<vector<bool>>(w,vector<bool>(14000, false)));
	dp[0][0][bias+c[0][0]] = true;
	rep(i,h)rep(j,w)rep(k, 14000){
		int d = c[i][j];
		if(i>0 && (k-d>0 && k-d<14000)) chor(dp[i][j][k], dp[i-1][j][k-d]);
		if(i>0 && (k+d>0 && k+d<14000)) chor(dp[i][j][k], dp[i-1][j][k+d]);
		if(j>0 && (k-d>0 && k-d<14000)) chor(dp[i][j][k], dp[i][j-1][k-d]);
		if(j>0 && (k+d>0 && k+d<14000)) chor(dp[i][j][k], dp[i][j-1][k+d]);
		
		// if(dp[i][j][k]) cout << i << " " << j <<" " <<k<<endl; 
	}
	int ans = INF;
	rep(i,14000){
		if(dp[h-1][w-1][i]) ans = min(ans, abs(i-bias));
	}
	// rep(i, 14000){
	// 	if(dp[h-1][w-1][i])cout <<i<< endl;
	// }
	cout << ans <<endl;
}