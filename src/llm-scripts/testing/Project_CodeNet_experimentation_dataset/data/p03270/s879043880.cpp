#include <bits/stdc++.h>
using namespace std;

const int N = 4005;
const long long mod = 998244353;

long long C[N][N];
long long pow2[N];

void init(){
	C[0][0] = C[1][0] = C[1][1] = 1;
	for (int i = 2; i <= 4000; i++){
		C[i][0] = 1;
		for (int j = 1; j < i; j++) C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
		C[i][i] = 1;
	}
	pow2[0] = 1;
	for (int i = 1; i <= 4000; i++) pow2[i] = pow2[i - 1] * 2 % mod;
}

int main(){
	init();
	int n, k, num1, num2, num3;
	long long ans;
	scanf("%d %d",&k,&n);
	for (int i = 2; i <= k * 2; i++){
		ans = 0;
		num1 = (min(i - 1, k) - max(i - k, 1) + 1) / 2;
		num2 = 1 - i & 1;
		num3 = k - num1 * 2 - num2;
		for (int p = 0; p <= num2; p++){
			for (int j = 0; j <= num1; j++){
				ans += C[num1][j] * pow2[j] % mod * C[n - 1 - p + num3][j + num3 - 1] % mod;
				ans %= mod;
			}
		}
		printf("%I64d\n", ans);
	}
	return 0;
}