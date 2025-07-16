#pragma GCC optimize("O3")
#pragma GCC target("sse4")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const double PI=acos(-1.0);
#define t1(x)             cerr<<#x<<"="<<x<<endl
#define t2(x, y)          cerr<<#x<<"="<<x<<" "<<#y<<"="<<y<<endl
#define t3(x, y, z)       cerr<<#x<<"=" <<x<<" "<<#y<<"="<<y<<" "<<#z<<"="<<z<<endl
#define t4(a,b,c,d)       cerr<<#a<<"="<<a<<" "<<#b<<"="<<b<<" "<<#c<<"="<<c<<" "<<#d<<"="<<d<<endl
#define t5(a,b,c,d,e)     cerr<<#a<<"="<<a<<" "<<#b<<"="<<b<<" "<<#c<<"="<<c<<" "<<#d<<"="<<d<<" "<<#e<<"="<<e<<endl
#define t6(a,b,c,d,e,f)   cerr<<#a<<"="<<a<<" "<<#b<<"="<<b<<" "<<#c<<"="<<c<<" "<<#d<<"="<<d<<" "<<#e<<"="<<e<<" "<<#f<<"="<<f<<endl
#define GET_MACRO(_1,_2,_3,_4,_5,_6,NAME,...) NAME
#define t(...) GET_MACRO(__VA_ARGS__,t6,t5, t4, t3, t2, t1)(__VA_ARGS__)
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define fastio() ios::sync_with_stdio(0);cin.tie(0)
#define MEMS(x,t) memset(x,t,sizeof(x));
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
/*-------------------------------------------------------------------------------------------------------------------------------------*/
// #define MOD 1000000007
#define endl "\n" 
#define int long long
#define inf 1e18
#define ld long double

/*-------------------------------------------------------------------------------------------------------------------------------------*/

int dp[6005][12005];
int n,MOD;
int rec(int ind,int balance)
{
	if(ind==0)
	{
		return (balance>=0 && balance%3==0);
	}
	int &ans=dp[ind][balance+3*n];
	if(ans>=0)return ans;
	ans=rec(ind-1,balance+1);
	if(ind>1)
		ans+=(ind-1)*rec(ind-2,balance-1);
	if(ind>2)
		ans+=(ind-1)*(ind-2)*rec(ind-3,balance);
	ans%=MOD;
	return ans;
}
int32_t main()
{
	fastio();
	cin>>n>>MOD;
	MEMS(dp,-1);
	cout<<rec(3*n,0)<<endl;
}
