#include <bits/stdc++.h>
#define int long long
using namespace std;

int n,b,m;

vector<vector<int> > vec;
vector<int> dp;	
	
int solve(int mask)
{
if(dp[mask]!=LLONG_MIN)
	return dp[mask];
// if all the rabbits in mask are 
// in the same group

int res=0;
for(int i=0; i<n; i++)
{
	for(int j=i+1; j<n; j++)
	{
		if((mask&(1LL<<i))&&(mask&(1LL<<j)))
			res+=vec[i][j];
	}
}

// iterate through all submasks now : O(3^n)

for(int i=mask&(mask-1); i; i=(i-1)&mask)
{
res=max(res,solve(i)+solve(i^mask));	
}

return dp[mask]=res;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	vec.assign(n,vector<int>(n));
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n;j++)
		{
			cin>>vec[i][j];
		}
	}
	dp.assign(1LL<<n,LLONG_MIN);
	cout<<solve((1LL<<n)-1);
	return 0;
}
