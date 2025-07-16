#include "bits/stdc++.h"

using namespace std;

void Main() {
    long long N, T;
    cin >> N >> T;
    long long ans = 0LL;
    long long prevt;
    cin >> prevt;
    for (long long i = 1; i < N; ++i) {
        long long t;
        cin >> t;
        if (T <= t - prevt) {
            ans += T;
        }
        else {
            ans += t - prevt;
        }
        prevt = t;
    }
    ans += T;
    cout << ans << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
