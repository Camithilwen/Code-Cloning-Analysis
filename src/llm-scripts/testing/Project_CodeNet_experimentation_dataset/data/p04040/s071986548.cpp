#include<iostream>
using namespace std;
long long int MOD = 1000000007;
long long modpow(long long a, long long n, long long mod);
long long modinv(long long a, long long mod);
int main() {

	//D
	long long int h, w, a, b;
	cin >> h >> w >> a >> b;
	long long int sum = 1;
	long long int i, j;
	for (i = 1; i <= h - a - 1 + b; i++) {
		sum = (sum * i) % MOD;
	}
	for (i = 1; i <= w - b - 1 + a - 1; i++) {
		sum = (sum * i) % MOD;
	}
	for (i = 1; i <= h - a - 1; i++) {
		sum = (sum * modinv(i, MOD)) % MOD;
	}
	for (i = 1; i <= b; i++) {
		sum = (sum * modinv(i, MOD)) % MOD;
	}
	for (i = 1; i <=w-b-1; i++) {
		sum = (sum * modinv(i, MOD)) % MOD;
	}
	for (i = 1; i <= a - 1; i++) {
		sum = (sum * modinv(i, MOD)) % MOD;
	}
	//cout << sum << endl;
	long long int sumsum = 0;
	for (i = b; i <= w - 1; i++) {
		sumsum = (sum + sumsum) % MOD;
		//cout << "sumsum" << sumsum;
		sum = (sum * (w - i - 1)) % MOD;
		sum = (sum * (h - a - 1 + i + 1)) % MOD;
		sum = (sum * modinv(w - i - 1 + a - 1, MOD)) % MOD;
		sum = (sum * modinv(i + 1, MOD)) % MOD;
		//cout << sum << endl;
	}
	cout << sumsum << endl;
	return 0;
	//C
	/*int n,k;
	int d[10];
	cin >> n >> k;
	int i;
	for (i = 0; i < k; i++) {
		cin >> d[i];
	}
	int x,j;
	int flag;
	for (i = n; i < 99999; i++) {
		x = i;
		flag = 0;
		while (x > 0) {
			for (j = 0; j < k; j++) {
				if ((x % 10) == d[j]) {
					flag = 1;
					break;
				}
			}
			if (flag == 1)break;
			x = (x - (x % 10)) / 10;
		}
		if (flag == 0) {
			cout << i << endl;
			return 0;
		}
	}*/



}
// a^n mod を計算する
long long modpow(long long a, long long n, long long mod) {
	long long res = 1;
	while (n > 0) {
		if (n & 1) res = res * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return res;
}

// a^{-1} mod を計算する
long long modinv(long long a, long long mod) {
	return modpow(a, mod - 2, mod);
}