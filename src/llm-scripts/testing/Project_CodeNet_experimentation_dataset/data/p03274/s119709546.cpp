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
typedef vector<ll> vll;
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

void solve(int test_case) {//209
	int n,k;
	cin>>n>>k;
	k--;
	vi arr(n);
	for(int &i:arr)cin>>i;
	int mi = INT_MAX;
	REP(i,0,n-k-1) {
		if(arr[i+k]<0){
			mi=min(mi, -arr[i]);
		} else if(arr[i]<0) {
			mi = min(mi, min(-2*arr[i]+arr[i+k],2*arr[i+k]-arr[i]));
		} else mi=min(mi, arr[i+k]);
	}
	cout<<mi;
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
