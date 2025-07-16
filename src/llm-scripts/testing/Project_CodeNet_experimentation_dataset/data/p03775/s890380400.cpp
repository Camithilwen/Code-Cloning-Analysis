#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)

using int64 = uint64_t;
using namespace std;

vector<int64> prime_factor(int64 n) {
    vector<int64> primes;
    for (int64 i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            primes.push_back(i);
            if (n / i != i)
                primes.push_back(n / i);
        }
    }
    sort(primes.begin(), primes.end());
    return primes;
}

int digits(int64 n) {
    int cnt = 0;
    while (n > 0) {
        n /= 10;
        cnt++;
    }
    return cnt;
}

int main() {
    fastIO;
    int64 n;

    cin >> n;
    vector<int64> primes = prime_factor(n);

    int digit = 11;
    int l = 0, r = (int)primes.size() - 1;
    while (l <= r) {
        if (primes.at(l) * primes.at(r) == n) {
            int l_digit = digits(primes.at(l));
            int r_digit = digits(primes.at(r));
            digit = max(l_digit, r_digit);
            r--;
        } else {
            l++;
        }
    }
    cout << digit << endl;
}

