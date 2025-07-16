#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int n,m;
	cin>>n>>m;
	vector<int>pf(n+2);
	for(int i=0; i<m; i++){
		int a,b;
		cin>>a>>b;
		pf[a]++;
		pf[b+1]--;
	}
	for(int i=1; i<=n; i++){
		pf[i]+=pf[i-1];
	}
	int cnt=0;
	for(int i=1; i<=n; i++){
		if(pf[i]==m)
		 cnt++;
	}
	cout<<cnt;
	return 0;
	
}