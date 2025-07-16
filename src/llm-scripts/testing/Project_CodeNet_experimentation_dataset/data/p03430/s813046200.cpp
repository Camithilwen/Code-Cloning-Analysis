#include <bits/stdc++.h>
#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define N 305
using namespace std;

int n, k, dp[N][N][N];
char s[N];

int f(int bas, int son, int k){
	if(bas == son)
		return 1;
	if(bas > son)
		return 0;
	int &r = dp[bas][son][k];
	if(r != -1)
		return r;
	if(s[bas] == s[son])
		r = f(bas + 1, son - 1, k) + 2;
	if(k)
		r = max(r, f(bas + 1, son - 1, k - 1) + 2);
	r = max(r, f(bas + 1, son - 1, k));
	r = max(r, f(bas, son - 1, k));
	r = max(r, f(bas + 1, son, k));
	return r;
}

int main() {
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	memset(dp, -1, sizeof dp);
	scanf("%s %d",s + 1, &k);
	n = strlen(s + 1);
	printf("%d\n", f(1, n, k));
	return 0;
}