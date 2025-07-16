#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 11;
#define LL long long 
int n;
LL ans, s, x[N];
LL a[N];
LL sol(int l, int r){
	//printf("l=%d r=%d al=%lld ar=%lld\n", l, r, a[l], a[r]);
	if(x[l] > s){
		ans += x[r] - s;
		return x[r];
	}
	if(x[r] < s){
		ans += s - x[l];
		return x[l];
	}
	if(a[l] >= a[r]){
		a[l] += a[r];
		ans += abs(x[r] - sol(l, r - 1));
		return x[r];
	}
	else{
		a[r] += a[l];
		ans += abs(x[l] - sol(l + 1, r));
		return x[l];
	}
}
int main(){
	cin>>n>>s;
	for(int i = 1;i <= n; i++){
		scanf("%lld%lld", &x[i], &a[i]);
	}
	sol(1, n);
	cout<<ans<<endl;
	return 0;
}
