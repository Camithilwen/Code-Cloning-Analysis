#include <bits/stdc++.h>

using namespace std;

const int N = 510;
int p[10010];
vector<int> primes;
int a[N * 2], b[N * 2];

void init() {
    for (int i = 2; i < 10000; i++) {
        if (!p[i]) {
            for (int j = i + i; j < 10000; j += i) {
                p[j] = 1;    
            }
            primes.push_back(i);
        }
    }
}

long long res[N][N];
set<long long> has;

long long lcm(long long a, long long b) {
    long long c = __gcd(a, b);
    return (a / c) * b;
}

int main() {
    init();    
    int n;
    scanf("%d", &n);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        a[i] = primes[cnt++];
    }   
    for (int i = 0; i < n; i++) {
        b[i] = primes[cnt++];
    }
    memset(res, -1, sizeof res);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((i + j) % 2 == 0) {
                int aa = i + j >> 1;
                int bb = (i - j + n) >> 1;
                res[i][j] = 1ll * a[aa] * b[bb];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((i + j) % 2 == 0) {
                continue;
            }
            long long foo = 1ll;
            if (i > 0) {
                foo = lcm(foo, res[i - 1][j]);
            }
            if (i + 1 < n) {
                foo = lcm(foo, res[i + 1][j]);
            }
            if (j > 0) {
                foo = lcm(foo, res[i][j - 1]);
            }
            if (j + 1 < n) {
                foo = lcm(foo, res[i][j + 1]);
            }
            int it = 1;
            while (has.count(foo * it)) {
                it++;
            }
            has.insert(foo * it);
            res[i][j] = foo * it + 1;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%lld ", res[i][j]);
        }
        printf("\n");
    }
    return 0;
}