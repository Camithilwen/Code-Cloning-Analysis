#include<iostream>
#include<vector>
#include<cmath>
#include<cassert>
#include<bitset>
using namespace::std;
#define int long long int
int dp[1<<16],ar[20][20];

main(){
	ios_base::sync_with_stdio(0);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>ar[i][j];
	for(int j=1;j<(1<<n);j++){
			int t=j;
			vector<int> v;
			for(;t;t-=t&(-t))
				v.push_back((int)log2(t&(-t)));
			// cout<<(bitset<20>)j<<'\n';
			t=j;
			for(int i=0;i<v.size();i++)
				for(int j=i+1;j<v.size();j++)
					dp[t]+=ar[v[i]][v[j]];//,cout<<v[i]<<' '<<v[j]<<' '<<ar[v[i]][v[j]]<<' '<<dp[t]<<'\n';
			// for(auto a:v)
			// 	cout<<a<<' ';
			// cout<<dp[j]<<'\n';
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<(1<<n);j++)
			if(__builtin_popcount(j)==i)
				for(int k=((1<<n)-1)^(((1<<n)-1)&j);k;k--,k^=k&j){
						dp[j|k]=max(dp[j|k],dp[j]+dp[k]);
					}
	cout<<dp[(1<<n)-1]<<'\n';
	// for(int j=1;j<(1<<n);j++)
	// 	cout<<dp[j]<<'\n';
}