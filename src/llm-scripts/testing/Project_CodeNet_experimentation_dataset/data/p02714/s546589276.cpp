
#include <bits/stdc++.h>
using namespace std;


#define M 1000000007
#define pb push_back
#define mp make_pair
#define s second
#define f first
#define mod 998244353
#define sz(v) (int)(v).size()

#define pii pair<int, int>
#define vi vector<int>
#define ll long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(0)

ll add(ll a,ll b)
{
	a%=M;
	b%=M;
	ll p = (a+b)%M;
	return (p+M)%M;
}

ll mul(ll a,ll b)
{
	a%=M;
	b%=M;
	ll p = (a*b)%M;
	return (p+M)%M;
}


int main()
{
	fastio;
	ll i,j,n,ans=0;
	cin>>n;
	string str;
	cin>>str;
	ll c1=0,c2=0,c3=0;
	for(i=0;i<n;i++)
	{
		if(str[i]=='R')
			c1++;
		else if(str[i]=='G')
			c2++;
		else
			c3++;
	}
	ans = c1*c2*c3;
	for(i=0;i<n;i++)
	{
		for(j=1;(j<=i)&&(i+j<n);j++)
		{
			if((str[i]!=str[i-j])&&(str[i]!=str[i+j])&&(str[i-j]!=str[i+j]))
				ans--;
		}
	}
	cout<<ans<<endl;
    return 0;
}



