#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)

lli x, y;

int main(void){
	cin >> x >> y;
	lli ans = 1e18;
	rep(i, 2){
		rep(j, 2){
			lli xc, yc;
			xc = x;
			yc = y;
			lli c = 0;
			if(i == 1) xc*=-1, c++;
			if(j == 1) yc*=-1, c++;
			if(xc <= yc) c+=yc-xc;
			else c+=1e18;
			ans = min(ans, c);
		}
	}
	cout << ans << endl;
	return 0;
}
