/*
ID: anonymo14
TASK: wormhole
LANG: C++                 
*/
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<pair<int,int>> vpii;

#define F first
#define S second
#define PU push
#define PUF push_front
#define PUB push_back
#define PO pop
#define POF pop_front
#define POB pop_back

#define REP(i,a,b) for(int i=a; i<=b; i++)

#define MOD 1000000007

void solve(int test_case) {
	int n;
	cin>>n;
	vi arr(n);
	for(int &i:arr)cin>>i;
	sort(arr.rbegin(),arr.rend());
	ll ans=1;
	int cnt = 0;
	for(int i=0;i<n-1;i++) {
		if(arr[i]==arr[i+1])ans*=arr[i],i++,cnt++;
		if(cnt==2)break;
	}
	if(cnt!=2)cout<<0;
	else
	cout<<ans;
}

int main() {
	
	////// FILE BASED IO////
	//freopen("wormhole.in", "r", stdin);
	//freopen("wormhole.out", "w", stdout);
	///////////////
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t=1;
	//cin>>t;
	REP(i,1,t) {
		solve(i);
	}
	return 0;
}	
