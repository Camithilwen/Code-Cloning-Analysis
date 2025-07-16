#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
#define ll long long

void add_self(ll& a, ll b) {
    a += b;
    if(a >= mod) {
        a -= mod;
    }
}

int main()
{
	string k;
	cin >> k;
	int d;
	cin >> d;
	vector<vector<ll>> dp(d,vector<ll>(2));
	int n = k.size();
	dp[0][0] = 1;
	for(int i = 0;i < n;i++)
	{
		auto new_dp = vector<vector<ll>> (d,vector<ll>(2));
		for(int sum = 0;sum < d;sum++)
		{
			for(bool sm_already : {false,true})
			{
				for(int digit = 0;digit < 10;digit++)
				{
					if(digit > k[i]-'0' && !sm_already)
						break;
					add_self(new_dp[(sum+digit)%d][sm_already || (digit < k[i]-'0')],dp[sum][sm_already]);
				}
			}
		}
		dp = new_dp;
	}

	auto ans = (dp[0][true] + dp[0][false])%mod;
	--ans;
	if(ans == -1)
		ans = mod-1;
	cout << ans << endl;
	return 0;
}