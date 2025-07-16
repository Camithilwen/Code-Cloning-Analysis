#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <string>
#include <bitset>
#include <utility>
#include <numeric>
#include <queue>
#include <stack>

using ll = long long;
using namespace std;

constexpr int MOD = 1e9 + 7;
constexpr ll MOD_LL = ll(1e9 + 7);

template<typename T>
vector<T> prime_factorization(T n) {
	vector<T> ret;
	vector<bool> is_prime(n + 1, true);
	
	for(T i = 2; i <= n; ++i) {
		
		if( is_prime[i] ) {
			for(T j = 2 * i; j <= n; j += i) {
				is_prime[j] = false;
			}
			
			if( i % 5 == 1 ) ret.push_back(i);
		}
	}
	
	return ret;
}

int main(void) {
	int n;
	cin >> n;
	
	vector<int> primes = prime_factorization(55555);
	
	for(int i = 0; i < n; ++i) {
		cout << primes[i] << " ";
	}
	
	cout << endl;
	
	return 0;
}
