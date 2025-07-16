#include <iostream>
#include <map>
typedef long long ll;
using namespace std;

// 素数 -> 個数
map<ll, ll> mp;

// 素数
map<ll, bool> prime;

bool isPrime(ll n) {
    if (prime.find(n) != prime.end()) return prime[n];
    if (n == 2) {
        prime[2] = true;
        return true;
    }
    else {
        bool flg = true;
        for (ll i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                flg = false;
                break;
            }
        }
        prime[n] = flg;
        return flg;
    }
}
void prime_split(ll n) {
    ll gen = 2;
    while (true) {
        if (isPrime(gen)) {
            if (mp.find(gen)==mp.end()) mp[gen] = 0;
            while (n % gen == 0) {
                n /= gen;
                mp[gen] += 1;
            }
        }
        if (n == 1) break;
        gen++;
    }
}
int main(void) {
    int N;cin>>N;
    ll result = 1;
    for (int i = 2; i <= N; i++) {
        prime_split(i);
    }
    for (map<ll,ll>::iterator it = mp.begin(); it != mp.end(); ++it) {
        result *= it->second + 1;
        result %= 1000000007;
    }
    cout << result << endl;
    return 0;
}