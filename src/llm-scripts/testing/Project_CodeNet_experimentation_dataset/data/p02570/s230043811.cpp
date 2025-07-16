//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("O3")
#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<cstdlib>
#include<set>
#include<vector>
#include<sstream>
#include<queue>
#include <iomanip>
#include<unordered_set>
#include <stack>
#include <unordered_map>
#include <map>
#include<numeric>
#include<chrono>
#include <fstream>
constexpr auto INF = 9223372036854775807;
typedef long long int ll;
typedef unsigned long long int ull;
typedef unsigned long int ul;
#define f(i,a,b) for(ll i=(ll)a;i<(ll)b;i+=1)
#define rf(i,a,b) for(ll i=(ll)a;i>=(ll)b;i-=1)
#define endl '\n'
#define N 1000000007 // prime modulo value 
#define M 998244353
#define all(x) x.begin(),x.end()
#define mkp(a,b) make_pair(a,b)
using namespace std;
struct custom_hash {
	static uint64_t splitmix64(uint64_t x) {
		// http://xorshift.di.unimi.it/splitmix64.c
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}

	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};
inline int mex(unordered_set<int> st)
{
	int m = 0;
	while (st.find(m) != st.end())
	{
		m += 1;
	}
	return m;
}
inline int calculateGrundy(int n)
{
	if (n == 1)
		return 0;
	unordered_set<int> mexi;
	for (int i = 1; i <= sqrt(n); i += 1)
	{
		if (n % i == 0)
		{
			if (n / i != n)
				mexi.insert(calculateGrundy(n / i));
			mexi.insert(calculateGrundy(i));
		}
	}
	return mex(mexi);
}
inline ll gcd(ll a, ll b)
{
	// This is code taken from geeksforgeek
	if (b == 0)
		return a;
	return gcd(b, a % b);
}
/*ll power(ll x, ll y)
{
	// This is code taken from geeksforgeek
	ll res = 1;

	x = x % N;
	if (x == 0) return 0;
	while (y > 0)
	{
		if (y & 1)
			res = (res * x) % N;
		y = y >> 1;
		x = (x * x) % N;
	}
	return res;
}*/
ll power(ll x, ll y)
{
	ll res = 1;

	x = x;

	while (y > 0)
	{

		if (y & 1)
			res = (res * x);

		y = y >> 1;
		x = (x * x);
	}
	return res;
}


/*ll modInverse(ll n, ll p)
{
	return power(n, p - 2, p);
}*/

ll sum(ll n)
{
	return (n * (n + 1)) / 2;
}
ll sum_digit(ll n)
{
	ll ans = 0;
	while (n)
	{
		ans += n % 10;
		n /= 10;
	}
	return ans;
}
ll gp(ll r, ll n)
{
	return (pow(r,n)-1)/(r-1);
}
int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll d,t,s;
	cin>>d>>t>>s;
	ll time=(d-s*t);
	if(time<=0)
	{
		cout<<"Yes";
	}
	else
	{
		cout<<"No";
	}
	
	return 0;
}