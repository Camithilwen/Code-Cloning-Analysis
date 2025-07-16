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

void solve(int test_case) {//211
	ll n;
	cin>>n;
	vector<bool> prime(n+1,1);
	REP(i,2,n) {
		if(prime[i])for(int j=i+i;j<=n;j+=i)prime[j]=0;
	}
	ll ans = 1;
	for(ll i=2;i<=n;i++) {
		if(prime[i]) {
			ll now = i,cnt=0;
			while(now<=n){cnt=cnt+(n/now);now*=i;}
			ans = (ans*(cnt+1))%1000000007;
		}
	}
	//if(n!=1)ans = (ans*2)%1000000007;
	cout<<ans;
}//1, 2, 4, 8, 12, 30, 60, 96

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
