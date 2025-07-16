#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N=1e3+5;
const int MOD=1e9+7;
 
int n, a, b, c, d;
int cache[N][N], cache2[N][N];
int fact[N], invfact[N];
 
int pow(int a, int b, int m)
{
	int ans=1;
	while(b)
	{
		if(b&1)
			ans=(ans*a)%m;
		b/=2;
		a=(a*a)%m;
	}
	return ans;
}
 
int modinv(int k)
{
	return pow(k, MOD-2, MOD);
}
 
void precompute()
{
	fact[0]=fact[1]=1;
	for(int i=2;i<N;i++)
	{
		fact[i]=fact[i-1]*i;
		fact[i]%=MOD;
	}
	invfact[N-1]=modinv(fact[N-1]);
	for(int i=N-2;i>=0;i--)
	{
		invfact[i]=invfact[i+1]*(i+1);
		invfact[i]%=MOD;
	}
}
 
int nCr(int x, int y)
{
	if(y>x)
		return 0;
	int num=fact[x];
	num*=invfact[y];
	num%=MOD;
	num*=invfact[x-y];
	num%=MOD;
	return num;
}
 
int num(int r, int take)
{
	int &ans=cache2[r][take];
	if(ans!=-1)
		return ans;
	return modinv(pow(fact[r], take, MOD));
}
 
int dp2(int n, int r, int take)
{
	int ans=fact[n] * invfact[n-r*take];
	ans%=MOD;
	int den=num(r, take);
	ans*=den;
	ans%=MOD;
	return ans;
}
 
int dp(int remaining, int freq)
{
	if(remaining==0)
		return 1;
	if(freq==b+1)
		return 0;
	int &ans=cache[remaining][freq];
	if(ans!=-1)
		return ans;
	ans=dp(remaining, freq+1);
	for(int i=c;i<=d;i++)
	{
		int take=i*freq;
		if(take>remaining)
			break;
		int ways=dp2(remaining, freq, i);
		ways*=dp(remaining-take, freq+1);
		ways%=MOD;
		ways*=invfact[i];
		ways%=MOD;
		ans+=ways;
	}
	ans%=MOD;
	return ans;
}
 
int32_t main()
{
	IOS;
	precompute();
	memset(cache, -1, sizeof(cache));
	memset(cache2, -1, sizeof(cache2));
	cin>>n>>a>>b>>c>>d;
	int ans=dp(n, a);
	cout<<ans;
	cerr<<(double)clock()/CLOCKS_PER_SEC;
	return 0;
}