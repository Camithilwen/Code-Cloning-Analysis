#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)

lli n;
string s, t;

int main(void){
	cin >> n >> s >> t;
	lli ans = 2*n;
	rep(i, n){
		if(s.substr(i, n-i) == t.substr(0, n-i)){
			ans = min(ans, n+i);
		}
	}
	cout << ans << endl;
	return 0;
}
