/*
* @Author: wxyww
* @Date:   2020-05-21 15:53:33
* @Last Modified time: 2020-05-21 16:09:36
*/
#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#include<ctime>
#include<cmath>
using namespace std;
typedef long long ll;
const int N = 200010;
#define int ll
ll read() {
	ll x = 0,f = 1;char c = getchar();
	while(c < '0' || c > '9') {
		if(c == '-') f = -1; c = getchar();
	}
	while(c >= '0' && c <= '9') {
		x = x * 10 + c - '0'; c = getchar();
	}
	return x * f;
}
int n;
ll tmp[N];
void mul(int *a,int *b) {
	for(int i = 1;i <= n;++i) {
		tmp[i] = a[b[i]];
	}
	for(int i = 1;i <= n;++i) a[i] = tmp[i];
}
int a[N],p[N];
void qm(ll y) {
	int ret[N];
	for(int i = 1;i <= n;++i) ret[i] = i;

	for(;y;y >>= 1,mul(p,p))
		if(y & 1) mul(ret,p);
	for(int i = 1;i <= n;++i) p[i] = ret[i];
}
signed main() {
	n = read();
	for(int i = 1;i <= n;++i) {
		a[i] = read();p[i] = i;
	}
	
	int m = read();ll K = read();
	
	for(int i = n;i >= 1;--i) a[i] -= a[i - 1];
	
	for(int i = 1;i <= m;++i) {
		int x = read();
		swap(p[x],p[x + 1]);
	}

	qm(K);

	for(int i = 1;i <= n;++i) tmp[i] = a[p[i]];
	// for(int i = 1;i <= n;++i) printf("%d ",tmp[i]);
	// puts("");
	for(int i = 1;i <= n;++i) {
		printf("%lld.0\n",tmp[i] += tmp[i - 1]);
	}
	return 0;
}