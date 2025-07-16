#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define len(x) int((x).size())

ll dp_real[2][301][301];
ll dp_suff[2][301][301];
ll dp_diag[2][301][301];

const ll p = 998244353LL;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	#ifdef ARTHUR_LOCAL
		ifstream cin("input.txt");
	#endif

	string s;
	int k;

	cin>>s>>k;

	k=min(k,300);

	int n = len(s);
	int zi=0;

	int initial_ones = 0;
	int ind=n-1;

	while(ind>=0 && s[ind]=='1')
	{
		ind--;
		initial_ones++;
	}

	// initialise the dp

	for(int i=0; i<=min(k,initial_ones); i++)
	{
		dp_real[0][i][i]=1;
		//cout << 0 << " " << i << " " << i << " " << 1 << endl;
	}

	// diag dudes is pretty easy to do

	for(int i=0; i<=k; i++)
	{
		for(int j=0; j<=k; j++)
		{
			dp_diag[0][i][j]=dp_real[0][i][j];

			if(i>0&&j>0)
			{
				dp_diag[0][i][j] += dp_diag[0][i-1][j-1];
				dp_diag[0][i][j] %= p;
			}
		}
	}
	// suff dudes ... not so bad either ???

	for(int i=0; i<=k; i++)
	{
		for(int j=k; j>=0; j--)
		{
			dp_suff[0][i][j]=dp_real[0][i][j];

			if(j<k)
			{
				dp_suff[0][i][j]+=dp_suff[0][i][j+1];
				dp_suff[0][i][j]%=p;
			}
		}
	}

	for(int ii=n-1; ii>=0; ii--)
	{
		if(s[ii]=='1') continue;
		
		// if(!skip_first)
		// {
		// 	skip_first=1;
		// 	continue;
		// }

		zi=1-zi;

		int a = 0;
		int copy_i = ii-1;

		while(copy_i>=0 && s[copy_i]=='1')
		{
			a++;
			copy_i--;
		}

		//cout << a << endl;

		for(int i=0; i<=k; i++)
		{
			for(int j=0; j<=k; j++)
			{
				// compute new real_dp[zi][i][j] value

				dp_real[zi][i][j] = dp_suff[1-zi][i][j];

				dp_real[zi][i][j] += dp_diag[1-zi][i][j];
				dp_real[zi][i][j] %= p;

				if(i-a > 0 && j-a > 0) // maybe add conditions on j < i or whatever
				{
					dp_real[zi][i][j] += p - dp_diag[1-zi][i-a-1][j-a-1];
					dp_real[zi][i][j] %= p;
				}

				dp_real[zi][i][j] += p-dp_real[1-zi][i][j];
				dp_real[zi][i][j] %= p;

				//cout << ii << " " << i << " " << j << " " << dp_real[zi][i][j] << endl;

				dp_diag[zi][i][j] = dp_real[zi][i][j];

				if(i>0&&j>0)
				{
					dp_diag[zi][i][j] += dp_diag[zi][i-1][j-1];
					dp_diag[zi][i][j] %= p;
				}
			}

			dp_suff[zi][i][k]=dp_real[zi][i][k];

			for(int j=k-1; j>=0; j--)
			{
				dp_suff[zi][i][j] = dp_real[zi][i][j];
				dp_suff[zi][i][j] += dp_suff[zi][i][j+1];
				dp_suff[zi][i][j] %= p;
			}
		}
	}

	ll ans=0LL;

	for(int i=0; i<=k; i++)
	{
		ans += dp_real[zi][i][0];
		ans %= p;
	}

	cout << ans << endl;
}