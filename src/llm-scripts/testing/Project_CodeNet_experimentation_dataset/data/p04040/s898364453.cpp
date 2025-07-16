
//include
//------------------------------------------
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <climits>
#include <set>
#include <unordered_set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <queue>
#include <random>
#include <complex>
#include <regex>
#include <locale>
#include <random>
#include <type_traits>

using namespace std;

#define SHOW_VECTOR(v) {std::cerr << #v << "\t:";for(const auto& xxx : v){std::cerr << xxx << " ";}std::cerr << "\n";}
#define SHOW_MAP(v){std::cerr << #v << endl; for(const auto& xxx: v){std::cerr << xxx.first << " " << xxx.second << "\n";}}

using LL = long long;

//------------------------------------------
//------------------------------------------

constexpr int MAX_N = 200200;
constexpr LL mod = 1e9 + 7;

LL mul[MAX_N];
LL inv[MAX_N];

LL POW_MOD(LL N, LL P, LL M) {
    LL ret = 1;
    while (P > 0) {
        if (P & 1LL) ret = (ret * N) % M;
        N = (N * N) % M;
        P >>= 1LL;
    }
    return ret;
}

void setup() {
    mul[0] = mul[1] = 1;
    inv[0] = inv[1] = 1;
    for (LL i = 2; i <= MAX_N - 2; i++) {
        mul[i] = mul[i - 1] * i;
        mul[i] %= mod;
        inv[i] = POW_MOD(mul[i], mod - 2, mod);
    }
}

LL nCr_mod(LL n, LL r) {
    if (n < r) return 0;
    return mul[n] * inv[r] % mod * inv[n - r] % mod;
}

int main() {

    int H, W, A, B;
    cin >> H >> W >> A >> B;

    setup();

    LL ans = 0;

    int y = H - A - 1;
    int x = B;
    while (y >= 0 && x < W) {
        LL n = y + x;
        LL r = y;
        ans += (nCr_mod(n, r) * nCr_mod(W - x - 1 +  H - y - 1, H - y - 1)) % mod;
        ans %= mod;
        y--;
        x++;
    }

    cout << ans << endl;

    return 0;
}


































