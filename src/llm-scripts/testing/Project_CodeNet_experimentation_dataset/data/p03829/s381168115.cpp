#include<bits/stdc++.h>
using namespace std;

typedef long long llint;
typedef long double ld;
#define inf 1e18
#define mod 1000000007
priority_queue<llint,vector<llint>,greater<llint> > que;
priority_queue<llint> q;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

void solve(){
	llint n,a,b;
	cin >> n >> a >> b;
	vector<llint>x(n);
	for(int i=0;i<n;i++)cin >> x[i];
	llint ans=0;
	for(int i=1;i<n;i++){
		ans+=min((x[i]-x[i-1])*a,b);
	}
	cout << ans << endl;
}

int main(int argc, char *argv[]) {
  solve();
  return 0;
}
