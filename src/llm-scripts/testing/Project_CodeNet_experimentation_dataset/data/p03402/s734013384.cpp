#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define debug(var) cerr << (#var) << " = " << (var) << endl;
#else
#define debug(var)
#endif

void init() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

const int K = 50;

char r[K*2][K*2];

void solve() {
    int a, b; scanf("%d%d", &a, &b);
    for (int i = 0; i < K; ++i) {
        for (int j = 0; j < 2*K; ++j) {
            r[i][j] = '.';
            r[i+K][j] = '#';
        }
    }
    --a; --b;
    for (int i = 0; i < K-1 && b; i+=2) {
        for (int j = 0; j < 2*K; j+=2) {
            r[i][j] = '#';
            if (!--b) goto Astuff;
        }
    }
    Astuff:
    for (int i = 0; i < K-1 && a; i+=2) {
        for (int j = 0; j < 2*K; j+=2) {
            r[i+K+1][j] = '.';
            if (!--a) goto end;
        }
    }
    end:
    puts("100 100");
    for (int i = 0; i < 2*K; ++i) {
        for (int j = 0; j < 2*K; ++j) {
            putchar(r[i][j]);
        }
        puts("");
    }
}

int main() {
    init();
    int t = 1; //scanf("%d", &t);
    while (t--) {
        solve();
    }
    return 0;
}