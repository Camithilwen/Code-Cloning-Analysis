#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <cmath>
#include <bitset>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
const int INF=1e9;
int main()
{
	int n, m;
	cin>>n>>m;
	vector<P> g[15];
	for(int i=0; i<m; i++){
		int a, b, c;
		cin>>a>>b>>c;
		a--; b--;
		g[a].push_back(P(b, c));
		g[b].push_back(P(a, c));
	}
	int dp[14][1<<14];
	for(int i=0; i<n-1; i++){
		if(i==0) fill(dp[i], dp[i]+(1<<(n-1)), 0);
		else fill(dp[i], dp[i]+(1<<(n-1)), INF);
	}
	int s[1<<15]={};
	for(int i=0; i<(1<<n); i++){
		for(int x=0; x<n; x++){
			if((i&(1<<x))==0) continue;
			for(auto pr:g[x]){
				int y=pr.first;
				if((i&(1<<y))==0) continue;
				s[i]+=pr.second;
			}
		}
		s[i]/=2;
	}
	for(int i=1; i<(1<<(n-1)); i++){
		for(int j=i; j>0; j=(j-1)&i){
			int sum=s[i]-s[i-j]-s[j];
			for(int x=0; x<n-1; x++){
				if((j&(1<<x))==0) continue;
				for(auto pr:g[x]){
					int y=pr.first;
					if(((i-j)&(1<<y))==0) continue;
					dp[y][i]=min(dp[y][i], dp[x][j]+sum-pr.second);
				}
			}
		}
	}
	int ans=INF;
	for(int i=1; i<(1<<(n-1)); i++){
		int sum=s[(1<<n)-1]-s[i]-s[(1<<n)-1-i];
		for(auto pr:g[n-1]){
			int y=pr.first;
			if((i&(1<<y))==0) continue;
			ans=min(ans, dp[y][i]+sum-pr.second);
		}
	}
	cout<<ans<<endl;
	return 0;
}