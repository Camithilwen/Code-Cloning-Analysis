#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0; i<(n); i++)
ll d, c, ans, u;
int main(){
	scanf("%lld", &d);
	for(int i=1; i<=18; i++) rep(j,1<<(i-1)){
		c = d; u = 1;
		int a[20] = {};
		rep(k,i){
			a[k] = c % 10;
			if(j>>k&1){
				a[k] -= 10;
				c += 10;
			}
			if(a[k] < -9 && a[k] > 9) u = 0;
			c /= 10;
		}
		if(c) u = 0;
		rep(k,(i+1)/2){
			if(a[k] + a[i-1-k]) u = 0;
			u *= 10 - abs(a[k]-(!k&&a[0]<=0));
		}
		ans += u;
	}
	printf("%lld\n", ans);
}