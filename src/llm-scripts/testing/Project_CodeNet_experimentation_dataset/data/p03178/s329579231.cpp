#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <algorithm>
using namespace std;
string a;
int d,n,mod=1e9+7;

int digitSum(int idx,int sum,bool tight,vector<vector<int> > &dp){
	if(idx==n)
		return sum==0?1:0;
	if(!tight&&dp[n-idx-1][sum]!=-1)
		return dp[n-idx-1][sum];
	int ans =0;
	int k = tight?a[idx]-48:10;
	for(int i=0;i<k;i++)
		ans = (digitSum(idx+1,(sum+i)%d,0,dp)+ans)%mod;
	if(tight){
		ans = (digitSum(idx+1,(sum+k)%d,1,dp)+ans)%mod;
	} else {
		dp[n-idx-1][sum] = ans;
	}
	return ans;
}

int main()
{	
	cin >> a >> d;
	n = a.size();
	vector<vector<int> > dp(n,vector<int>(d,-1));
	cout << (digitSum(0,0,1,dp)-1+mod)%mod;
    return 0;
}