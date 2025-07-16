#include<bits/stdc++.h>
using namespace std;

#define ll double
#define mod 1e9+7

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)

ll dp[301][301][301];

ll solve(int one, int two, int three, int& n)
{
	if(one < 0 || two < 0 || three < 0) return 0;
	if(one == 0 && two == 0 && three == 0) return 0;
	if(dp[one][two][three] > 0) return dp[one][two][three];
	int rem = one + two + three;
	ll exp_val = n + one*solve(one-1, two, three, n) + two*solve(one+1, two-1, three, n) + three*solve(one, two+1, three-1, n);

	return dp[one][two][three] = exp_val/rem;

}

int main()
{
	int i, j, n, m, p, k, x;
	cin>>n;
	int one = 0, two = 0, three = 0;
	for(i = 0; i < n; i++)
	{
		cin>>x;
		if(x == 1) one++;
		else if(x == 2) two++;
		else three++;
	}
	memset(dp, -1, sizeof(dp));
	cout<<fixed<<setprecision(9)<<solve(one, two, three, n);
	return 0;
}
