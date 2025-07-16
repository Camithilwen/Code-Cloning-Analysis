#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 20;
LL a[maxn], power[maxn], n, m, ans;

LL dfs1(LL k, LL n, LL pre){
	if (2*k+1 == m){
		LL res; a[k] = n / (power[k] + power[k-1]) - pre;
		if (a[1] <= -10 || 10 <= a[1]) return 0;
		if ((pre + a[k]) * (power[k] + power[k-1]) != n) return 0;
		if (a[1] >= 0) res = 10 - abs(a[1]) - 1;
		else res = 10 - abs(a[1]);
		for (int i=2; i<=k; i++)
			if (a[i] <= -10 || 10 <= a[i]) return 0;
			else res *= 10 - abs(a[i]);
		return res * 10;
	}
	LL res = 0, d = power[k-1] + power[m-1-k], t;
	a[k] = ((n / power[k-1] - pre) % 10 + 10) % 10; t = a[k] + pre;
	res = dfs1(k+1, n-t*d, t);
	if (t){
		a[k] -= 10; t -= 10; 
		res += dfs1(k+1, n-t*d, t);
	}
	return res;
}

LL dfs2(LL k, LL n, LL pre){
	if (2*k == m){
		LL res; a[k] = n / power[k-1] - pre;
		if (a[1] <= -10 || 10 <= a[1]) return 0;
		if (a[1] >= 0) res = 10 - abs(a[1]) - 1;
		else res = 10 - abs(a[1]);
		for (int i=2; i<=k; i++)
			if (a[i] <= -10 || 10 <= a[i]) return 0;
			else res *= 10 - abs(a[i]);
		return res;
	}
	LL res = 0, d = power[k-1] + power[m-1-k], t;
	a[k] = ((n / power[k-1] - pre) % 10 + 10) % 10; t = a[k] + pre;
	res = dfs2(k+1, n-t*d, t);
	if (t){
		a[k] -= 10; t -= 10; 
		res += dfs2(k+1, n-t*d, t);
	}
	return res;
}

int main(){
	scanf("%lld", &n);
	if (n % 9) { puts("0"); return 0; }
	n /= 9; power[0] = 1;
	for (int i=1; i<=18; i++) power[i] = power[i-1] * 10;
	for (int i=2; i<=18; i++){
		if (i&1) { m = i; ans += dfs1(1, n, 0); }
		else { m = i; ans += dfs2(1, n, 0); }
	}
	printf("%lld\n", ans);
	return 0;
}