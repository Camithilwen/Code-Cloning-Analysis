// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")



#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// #include <ext/rope>
// using namespace __gnu_pbds;
// using namespace __gnu_cxx;
// template <typename T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// #define Find order_of_key
// #define at find_by_order
#define x first
#define y second
#define ll long long
#define lll __int128
#define ull unsigned long long
#define ulll unsigned __int128
#define pii pair<int,int>
#define pb push_back
#define eb emplace_back
#define gu getchar_unlocked()
#define pu putchar_unlocked()
#define all(x) x.begin(),x.end()
#define endl '\n'

ll arr[20][20];
int n;
ll dp[(1<<17)];
ll dp1[(1<<17)];
ll val(int m){
	ll &s=dp1[m];
	if(~s)return s;
	s=0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(m&(1<<i) && m&(1<<j)){
				s+=arr[i][j];
			}
		}
	}return s;
}

ll f(int m){
	if(m==0)return 0;
	ll &ma=dp[m];
	if(~ma)return ma;
	ma=0;
	for (int s=m; s; s=(s-1)&m){
		ma=max(ma,val(s)+f(m^s));
	}return ma;
}
//resub
int main()
{
	fast;
	memset(dp,-1,sizeof dp);
	memset(dp1,-1,sizeof dp1);
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>arr[i][j];
		}
	}cout<<f((1<<n)-1)<<endl;
	return 0;
}