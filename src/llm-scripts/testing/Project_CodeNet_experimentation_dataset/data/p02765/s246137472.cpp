#include<iostream>
using namespace std;
long long int MOD = 1000000007;
long long modpow(long long a, long long n, long long mod);
long long modinv(long long a, long long mod);

int main() {
	
	//A
	int n, r;
	cin >> n >> r;
	if (n >= 10) {
		cout << r << endl;
	}
	else {
		cout << r + 100 * (10 - n) << endl;
	}
	return 0;

	//B
	/*int n;
	cin >> n;
	int k;
	cin >> k;
	int i = 0;
	while (n > 0) {
		n = (int)(n / k);
		i++;
	}
	cout << i << endl;
	return 0;*/
	//C
	/*int n;
	cin >> n;
	int x[100];
	int i;
	for (i = 0; i < n; i++) {
		cin >> x[i];
	}
	int sum, j, summin = 100000000;
	for (i = 0; i <= 100; i++) {
		sum = 0;
		for (j = 0; j < n; j++) {
			sum = sum + (x[j] - i) * (x[j] - i);
		}
		if (sum < summin)summin = sum;
	}
	cout << summin << endl;
	return 0;
	*/
	//D
	/*
	long long int n;
	cin >> n;
	long long int a, b;
	cin >> a >> b;
	if (n == 2) {
		cout << 0 << endl;
		return 0;
	}
	long long int sum = 1;
	int i;
	long long int x = 2, m = n;
	//2^nを計算
	while (m > 0) {
		if (m % 2 == 1) {
			sum = (sum * x) % MOD;
		}
		m = (int)(m / 2);
		x = (x * x) % MOD;
	}

	//cout << 1 << endl;
	
	long long int sum1 = 1;
	for (i = 1; i <= a; i++) {
		sum1 = (sum1 * (n + 1 - i)) % MOD;
	}
	for (i = 1; i <= a; i++) {
		sum1 = (sum1 * modinv(i, MOD)) % MOD;
	}
	sum = (sum - sum1 + MOD) % MOD;
	//cout << 2 << endl;

	sum1 = 1;
	for (i = 1; i <= b; i++) {
		sum1 = (sum1 * (n + 1 - i)) % MOD;
	}
	for (i = 1; i <= b; i++) {
		sum1 = (sum1 * modinv(i, MOD)) % MOD;
	}
	sum = (sum - sum1 + MOD) % MOD;
	sum = (sum + MOD - 1) % MOD;
	cout << sum << endl;
	return 0;
	*/
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