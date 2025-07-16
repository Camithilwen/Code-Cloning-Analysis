#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double Double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

// chmax, chmin
template<class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}

template<class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}

void solve(long long N, std::string S, long long Q, std::vector<long long> k) {
    auto solve = [&](long long K) {
        long long sum = 0;
        long long ans = 0;
        deque<pair<char, int>> Q;

        int dC = 0;
        int mC = 0;
        for (int i = 0; i < S.size(); i++) {
            while (Q.size() && i - K >= Q.front().second) {
                if (Q.front().first == 'D') {
                    sum -= mC;
                    dC--;
                } else {
                    mC--;
                }
                Q.pop_front();
            }
            if (S[i] == 'D') {
                Q.push_back({'D', i});
                dC++;
            } else if (S[i] == 'M') {
                Q.push_back({'M', i});
                mC++;
                sum += dC;
            } else if (S[i] == 'C') {
                ans += sum;
            }
        }
        return ans;
    };
    for (auto kv : k) {
        cout << solve(kv) << endl;
    }

}

int main() {
    long long N;
    scanf("%lld", &N);
    std::string S;
    std::cin >> S;
    long long Q;
    scanf("%lld", &Q);
    std::vector<long long> k(Q - 1 - 0 + 1);
    for (int i = 0; i < Q - 1 - 0 + 1; i++) {
        scanf("%lld", &k[i]);
    }
    solve(N, S, Q, std::move(k));
    return 0;
}
