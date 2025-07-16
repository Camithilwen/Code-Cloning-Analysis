#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1e6 + 100;

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

int main(){
    long long a, b;
    cin >> a >> b;
    long long GCD = gcd(a, b);
    vector<bool> primes(MAX, true);
    primes[0] = primes[1] = false;
    int ans = 1;
    for (int i = 2; i < MAX; ++i) {
        if (!primes[i]) continue;
        for (int j = 2 * i; j < MAX; j += i) {
            primes[j] = false;
        }

        if (GCD % i) continue;
        while (GCD % i == 0) GCD /= i;
        ans++;
    }
    if (GCD != 1) ans++;
    cout << ans << endl;
}