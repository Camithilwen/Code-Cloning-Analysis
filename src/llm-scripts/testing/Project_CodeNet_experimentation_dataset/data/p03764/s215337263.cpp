#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(long long i=0;i<x;i++)
#define repn(i,x) for(long long i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
vector<pair<string,P> >vec;

void solve(long long n, long long m, vector<long long> x, vector<long long> y){
	ll sumx = 0, sumy = 0;
	rep(i, n) {
		sumx = (sumx + (2*i-n+1) * x[i]) % mod;
	}
	rep(i, m) {
		sumy = (sumy + (2*i-m+1) * y[i]) % mod;
	}
	cout << sumx * sumy % mod << endl;
}

int main(){	
	long long m;
	long long n;
	scanf("%lld",&n);
	vector<long long> x(n-1+1);
	scanf("%lld",&m);
	vector<long long> y(m-1+1);
	for(int i = 0 ; i <= n-1 ; i++){
		scanf("%lld",&x[i]);
	}
	for(int i = 0 ; i <= m-1 ; i++){
		scanf("%lld",&y[i]);
	}
	solve(n, m, x, y);
	return 0;
}

