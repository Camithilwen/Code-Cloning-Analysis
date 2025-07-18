#include <bits/stdc++.h>
using namespace std;

#define INF 1.1e9
#define LINF 1.1e18
#define FOR(i,a,b) for (int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define BIT(x,n) bitset<n>(x)
#define PI 3.14159265358979323846

typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> PP;

//-----------------------------------------------------------------------------


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n,a,b,c;
	cin>>n;
	if(n==2) {
		cin>>a>>b;
		FOR(i,1,min(a,b)+1) {
			if(a%i==0&&b%i==0) cout<<i<<endl;
		}
	}
	else {
		cin>>a>>b>>c;
		FOR(i,1,min(a,min(b,c))+1) {
			if(a%i==0&&b%i==0&&c%i==0) cout<<i<<endl;
		}
	}

	return 0;
}

