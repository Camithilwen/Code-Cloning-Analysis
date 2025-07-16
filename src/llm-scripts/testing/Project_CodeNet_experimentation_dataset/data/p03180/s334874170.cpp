#include <bits/stdc++.h>
#define int long long
#define mod 998244353
#define foi(i,n) for(int i = 0; i < n ; ++i)
#define pi pair<int,int>
#define pb push_back
#define debug cout << "here" << endl;
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;

int dp[100000];

int findProfit(int mask,int arr[16][16]){
	int answer =0 ;
	vector<int> points;
	int ctr =0 ;
	while(mask){
		if(mask&1) points.pb(ctr);
		ctr++;
		mask = mask>>1;
	}

	for(int i = 0 ;i < points.size();i++){
		for(int j = i+1 ; j < points.size();j++) answer += arr[points[i]][points[j]];
	}

	//for(auto y : points ) cout << y << " ";
	//cout << endl;
	return answer;
}

void init(int n,int arr[16][16]){
	dp[0] = 0;

	for(int i = 1 ; i <= (((1)<<n)-1) ; i++){
		int answer = findProfit(i,arr);
		for(int j = i-1 ; j>=0 ; j--){
			if((j|i) == i) answer = max(answer , dp[j] + dp[(i^j)]);
		}
		dp[i] = answer;
	}


}


int32_t main(){

    memset(dp,0,sizeof(dp));

	int n;
	cin >> n;

	int arr[16][16];

	foi(i,n){
		foi(j,n) cin >> arr[i][j] ;
	}

	init(n,arr);

	cout << dp[((1LL)<<n)-1];

}

