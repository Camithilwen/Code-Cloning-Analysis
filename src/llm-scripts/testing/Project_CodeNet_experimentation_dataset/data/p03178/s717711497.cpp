#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int mod=1e9+7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	string k;
	cin>>k;
	int d;
	cin>>d;
	//dp[0][0]=1;
	vector< vector<int> >dp(d,vector<int>(2));
	dp[0][0]=1;
//	dp[0][1]=1;
	int n=k.length();
	for(int i=0;i<n;i++)
	{
	//	cout<<"s";
		vector< vector<int> >new_dp(d,vector<int>(2));
		for(int sum=0;sum<d;sum++)
		{
			//cout<<"x";
			for(bool j:{false,true})
			{
				for(int digit=0;digit<10;digit++)
				{
					if(digit>k[i]-'0'&& !j)
					{
						break;
					}
					new_dp[(sum+digit)%d][j||(digit< k[i]-'0')]=(new_dp[(sum+digit)%d][j||(digit< k[i]-'0')]+dp[sum][j])%mod;
				
				}
			}
		}
		dp=new_dp;
	}
	int ans=(dp[0][false]+dp[0][true])%mod;
	ans--;
	if(ans==-1)
	{ans=mod-1;
	}
	cout<<ans;
	return 0;
}