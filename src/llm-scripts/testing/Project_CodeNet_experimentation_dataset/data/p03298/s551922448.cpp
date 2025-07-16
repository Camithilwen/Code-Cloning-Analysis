#include "bits/stdc++.h"
using namespace std;
using ll     = long long;
using pii    = pair<int, int>;
using pll    = pair<ll, ll>;
using vi     = vector<int>;
using vl     = vector<ll>;
using vvi    = vector<vi>;
using vvl    = vector<vl>;
const ll INF = 1LL << 60;
const ll MOD = 1000000007;
template <class T>
bool chmax(T &a, const T &b) {
    return (a < b) ? (a = b, 1) : 0;
}
template <class T>
bool chmin(T &a, const T &b) {
    return (b < a) ? (a = b, 1) : 0;
}
template <class C>
void print(const C &c, std::ostream &os = std::cout) {
    std::copy(std::begin(c), std::end(c), std::ostream_iterator<typename C::value_type>(os, " "));
    os << std::endl;
}

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<pair<string, string>, int> cnt;
    for (int i = 0; i < (1 << n); ++i) {
        string red  = "";
        string blue = "";
        for (int j = 0; j < n; ++j) {
            if (1 << j & i) {
                red += s[j];
            } else {
                blue = s[j] + blue;
            }
        }
        cnt[make_pair(red, blue)]++;
    }
    ll ret = 0;
    for (int i = 0; i < (1 << n); ++i) {
        string red  = "";
        string blue = "";
        for (int j = 0; j < n; ++j) {
            if (1 << j & i) {
                red = s[j + n] + red;
            } else {
                blue += s[j + n];
            }
        }
        ret += cnt[make_pair(red, blue)];
    }
    cout << ret << "\n";
    return 0;
}