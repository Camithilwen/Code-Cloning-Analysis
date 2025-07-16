#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int MAXN = 1e5 + 10;
int N;
int a[1001][1001], vis[MAXN], prime[MAXN], tot;
void GetPhi() {
	vis[1] = 1;
	for(int i = 2; i; i++) {
		if(!vis[i]) prime[++tot] = i;
		if(tot == 1000) break; 
		for(int j = 1; j <= tot && (i * prime[j] <= 10000); j++) {
			vis[i * prime[j]] = 1;
			if(!(i % prime[j])) break;
		}
	}
}
int lcm(int x, int y) {
	if(x == 0 || y == 0) return x + y;
	return x / __gcd(x, y) * y;
}
main() {
	GetPhi();
	cin >> N;
	if(N == 2) {
		printf("4 7\n23 10");
		return 0;
	}
	for(int i = 1; i <= N; i++) 
		for(int j = 1; j <= N; j++)
			if(!((i + j) & 1)) a[i][j] = prime[(i + j) / 2] * prime[N + (i - j) / 2 + (N + 1) / 2];
	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= N; j++)
			if(!a[i][j]) 
				a[i][j] = lcm(lcm(a[i - 1][j], a[i][j - 1]), lcm(a[i][j + 1], a[i + 1][j])) + 1;
	for(int i = 1; i <= N; i++, puts(""))
		for(int j = 1; j <= N; j++)
			cout << a[i][j] << " ";
	return 0;
}
