#include<bits/stdc++.h>
#define rep(i,n)for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;

bool is_prime[10001];
int prime[10001];
int main() {
	memset(is_prime, 1, sizeof(is_prime));
	is_prime[0] = is_prime[1] = false;
	int p = 0;
	for (int i = 2; i <= 10000; i++) {
		if (is_prime[i]) {
			prime[p++] = i;
			for (int j = i * 2; j <= 10000; j += i)is_prime[j] = false;
		}
	}
	int n;
	while (scanf("%d", &n), n) {
		int a = upper_bound(prime, prime + p, n) - prime - 1;
		for (int i = a; i > 0; i--) {
			if (prime[i] - prime[i - 1] == 2) {
				printf("%d %d\n", prime[i - 1], prime[i]);
				break;
			}
		}
	}
}