#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main() {
	int n;
	cin >> n;
	vector<int> primes;
	vector<int> is_prime(55556, -1);
	for (int i = 2; i <= 55555; i++) {
		if (is_prime[i] != -1) continue;
		primes.push_back(i);
		is_prime[i] = 1;
		for (int j = i+i; j <= 55555; j+=i) {
			is_prime[j] = 0;
		}
	}
	int k = 0;
	for (int x: primes) {
		if (k == n) break;
		if (x % 5 == 1) {
			cout << x << " ";
			k++;
		}
	}
	cout << endl;
}