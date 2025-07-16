#include<iostream>
#include<cmath>
using namespace std;

#define MAX_N 3700000

int prime[MAX_N], twin[MAX_N];

void isprime(int c) {
	prime[2] = 1;
	for (int i = 3; i < c; i += 2) {
		for (int j = 3; j <= sqrt(i); j += 2) {
			if (i%j == 0) { 
				goto E; 
			}
		}
		prime[i] = 1;
	E:;
	}
}

void istwin(int d) {
	for (int i = 5; i < d; i++) {
		if (prime[i - 2] + prime[i] == 2) {
			twin[i] = i;
		}
		else {
			twin[i] = twin[i - 1];
		}
	}
}

int n;

int main() {
	isprime(MAX_N);
	istwin(MAX_N);
	while (true) {
		cin >> n;
		if (n == 0) {
			break;
		}
		cout << twin[n] - 2 << ' ' << twin[n] << endl;
	}
}