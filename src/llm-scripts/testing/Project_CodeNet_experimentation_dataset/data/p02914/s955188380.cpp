#include<bits/stdc++.h>
#define Rint register int
using namespace std;
typedef unsigned long long LL;
const int N = 100003;
int n;
LL a[N], b[61], sum, res;
inline void insert(LL x){
	for(Rint i = 60;~i;-- i)
		if((x >> i) & 1)
			if(!b[i]){
				b[i] = x; return;
			} else x ^= b[i];
}
int main(){
	scanf("%d", &n);
	for(Rint i = 1;i <= n;i ++) scanf("%llu", a + i), sum ^= a[i];
	for(Rint i = 1;i <= n;i ++) insert(a[i] &= ~sum);
	for(Rint i = 60;~i;-- i) res = max(res, res ^ b[i]);
	printf("%llu\n", res * 2 + sum);
}