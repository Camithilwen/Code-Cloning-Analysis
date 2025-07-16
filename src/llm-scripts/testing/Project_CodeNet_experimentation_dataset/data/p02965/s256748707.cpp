#include <cstdio>
#include <cstdlib>

using namespace std;

const int mod = 998244353;

class inverse {
    public:
    inverse(int n, int mod);
    ~inverse();
    long long get_inv(int x);
    long long get_fact(int x);
    long long get_invfact(int x);
    long long get_comb(int x, int y);
    
    private:
    int mod;
    long long* inv;
    long long* fact;
    long long* invfact;
};

inverse::inverse(int n, int mod) : mod(mod) {
    inv = (long long *)malloc(sizeof(long long) * (n + 1));
    fact = (long long *)malloc(sizeof(long long) * (n + 1));
    invfact = (long long *)malloc(sizeof(long long) * (n + 1));
    inv[1] = 1;
    for (int i = 2; i <= n; i++) inv[i] = inv[mod % i] * (mod - mod / i) % mod;
    fact[0] = invfact[0] = 1;
    for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i % mod;
    for (int i = 1; i <= n; i++) invfact[i] = invfact[i - 1] * inv[i] % mod;
}

inverse::~inverse() {
    free(inv);
    free(fact);
    free(invfact);
}

long long inverse::get_inv(int x) {
    return inv[x];
}

long long inverse::get_fact(int x) {
    return fact[x];
}

long long inverse::get_invfact(int x) {
    return invfact[x];
}

long long inverse::get_comb(int x, int y) {
    return fact[x] * invfact[y] % mod * invfact[x - y] % mod;
}

int main() {
    int n, m, i;
    long long ans;
    inverse inv(3000000, mod);
    
    scanf("%d %d", &n, &m);
    
    ans = inv.get_comb(m * 3 + n - 1, n - 1);
    
    for (i = m * 2 + 1; i <= m * 3; i++) {
        ans -= inv.get_comb(m * 3 - i + n - 2, n - 2) * n % mod;
        if (ans < 0) ans += mod;
    }
    
    for (i = m + 1; i <= m * 3 && i <= n; i++) {
        if ((m * 3 - i) % 2 == 1) continue;
        
        ans -= inv.get_comb((m * 3 - i) / 2 + n - 1, n - 1) * inv.get_comb(n, i) % mod;
        if (ans < 0) ans += mod;
    }
    
    printf("%lld\n", ans);
    
    return 0;
}
