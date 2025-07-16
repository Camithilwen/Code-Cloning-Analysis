#include<stdio.h>
#include<iostream>
#include <algorithm>
#include <functional>
#include <array>
using namespace std;
long long modpow(long long a, long long n, long long mod);
long long modinv(long long a, long long mod);
//void margesort(int a[], int a_len, int left, int right);
//void margesortD(int a[], int b[], int a_len, int left, int right);
//int temp[100000];
//int tempb[100000];
//int b[100000];
//int c[100000];
int main() {
	/*
		int a, b;
		cin >> a;
		cin >> b;
		if (a <= 5) {
			cout << 0;
		}
		else if (a <= 12) {
			cout << b / 2;
		}else{
			cout << b;
		}

		return 0;
		*/
		//B
		/*long long int r, d, x;
		cin >> r;
		cin >> d;
		cin >> x;

		int i;
		for (i = 0; i < 10; i++) {
			x = r * x - d;
			cout << x;
			cout <<'\n';
		}


		return 0;*/
		//C
		/*int n, m;
		int l, r;
		cin >> n;
		cin >> m;

		int lmax, rmin;
		lmax = 1;
		rmin = n;
		int i;
		for (i = 0; i < m; i++) {
			cin >> l;
			cin >> r;
			if (l > lmax) {
				lmax = l;
			}
			if (r < rmin) {
				rmin = r;
			}
		}
		if (lmax <= rmin) {
			cout << (rmin - lmax + 1);
		}
		else {
			cout << 0;
		}

		return 0;*/

		//D
	/*int n, m;
	cin >> n;
	cin >> m;
	int i;
	int a[100000];
	for (i = 0; i < n; i++) {
		cin >> a[i];
	}
	margesort(a, n, 0, n - 1);


	for (i = 0; i < m; i++) {
		cin >> b[i];
		cin >> c[i];

	}
	margesortD(c, b, m, 0, m - 1);
	//sort(b.begin(), b.end());

	long long int d;
	d = 0;
	int j, k, flag;
	i = 0;
	j = m - 1;
	flag = 0;
	while (flag == 0) {
		for (k = i; k < i + b[j]; k++) {
			if (a[k] < c[j]) {
				a[k] = c[j];
				
			}
			else {
				flag = 1;
			}
			if (k == n) {
				flag = 1;
				break;
			}
		}
		i = i + b[j];
		j--;
		if (j == -1) { flag = -1; }
	}
	for (i = 0; i < n; i++) {
		d = d + a[i];
	}
	cout << d;

	return 0;
	*/
	
	//E
	long long int n, m, k;
	cin >> n;
	cin >> m;
	cin >> k;
	long long int p;
	p = 1000000007;
	long long int c;
	c = 0;
	//2駒総コストを求める.
	int i;
	int j;
	c = (((((((n * m) % p) * (n + m)) % p) * (n * m - 1)) % p) * modinv(6, p)) % p;
	//それを(nm-2)C(k-2)倍する.
	j = 1;
	for (i = n*m-2; i > (n * m - 2)-(k-2); i--) {
		c = (c * i) % p;
		c = (c * modinv(j, p)) % p;
		j++;
	}
	cout << c;
	return 0;

}
/*void margesort(int a[], int a_len, int left, int right)
{
	int i, j, mid, L, R;

	if (right <= left)
		return;

	mid = (left + right) / 2;
	margesort(a, mid, left, mid);
	margesort(a, a_len - mid, mid+1, right);

	for (i = left; i <= mid; i++)
		temp[i] = a[i];
	for (i = mid+1, j = right; i <= right; i++, j--)
		temp[i] = a[j];

	L = left;
	R = right;

	for (i = left; i <= right; i++)
	{
		if (temp[L] <= temp[R])
		{
			a[i] = temp[L];
			L++;
		}
		else
		{
			a[i] = temp[R];
			R--;
		}
	}
}

void margesortD(int a[], int b[], int a_len, int left, int right) {
	int i, j, mid, L, R;

	if (right <= left)
		return;

	mid = (left + right) / 2;
	margesortD(a, b, mid, left, mid);
	margesortD(a, b, a_len - mid, mid+1, right);

	for (i = left; i <= mid; i++) {
		temp[i] = a[i];
		tempb[i] = b[i];
	}
	for (i = mid+1, j = right; i <= right; i++, j--) {
		temp[i] = a[j];
		tempb[i] = b[j];
	}

	L = left;
	R = right;

	for (i = left; i <= right; i++)
	{
		if (temp[L] <= temp[R])
		{
			a[i] = temp[L];
			b[i] = tempb[L];
			L++;
		}
		else
		{
			a[i] = temp[R];
			b[i] = tempb[R];
			R--;
		}
	}
}*/

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