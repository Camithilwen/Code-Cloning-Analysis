#include <algorithm>
#include <bitset>
#include <cstdio>
#include <cassert>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;

typedef long long LL;
typedef pair<int, int> P;
typedef pair<LL, LL> PLL;

constexpr int LIM = 10006;

char isprime[LIM];
int twinprime[LIM];

void setprime() {
    fill(isprime, isprime+LIM, 1);
    isprime[0] = isprime[1] = 0;
    for (int x = 2; x * x < LIM; ++x) {
        if (isprime[x]) {
            for (int y = x * x; y < LIM; y += x) {
                isprime[y] = 0;
            }
        }
    }
    for (int x = 5; x < LIM; ++x) {
        if (isprime[x-2] && isprime[x]) {
            twinprime[x] = x;
        } else {
            twinprime[x] = twinprime[x-1];
        }
    }
}

bool solve() {
    int n;
    cin >> n;
    if (n == 0) { return false; }
    int ans = twinprime[n];
    cout << (ans - 2) << ' ' << ans << endl;
    return true;
}

int main() {
    setprime();
    while(solve());
    return 0;
}