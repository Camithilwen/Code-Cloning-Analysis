#include <bits/stdc++.h>

using namespace std;

int main() {
	long long n;
	cin >> n;
	
	long long best = 0;
	long long curr = 0;
	
	for (long long i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			long long mul = n / i;
			
			long long digs_i = floor(log10(i) + 1);
			long long digs_mul = floor(log10(mul) + 1);
			
			curr = max(digs_i, digs_mul);
			best = max(best, curr);
		}
	}
	
	cout << curr << endl;
		
}