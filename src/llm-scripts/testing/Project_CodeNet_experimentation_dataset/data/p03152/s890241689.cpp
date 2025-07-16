#include <iostream>
#include <iomanip>
#include <map>
#include <list>
#include <set>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
#include <cstdint>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

constexpr ll inf = INT64_MAX / 4;
constexpr double pi = asin(1) * 2;
constexpr ll mod = 1000000007;

template<class T>
class set2 : public set<T> {
private:
    typename set<T>::iterator back_itr() {
        auto e = this->end();
        e--;
        return e;
    }

public:
    T front() {
        if (this->empty()) throw;
        return *this->begin();
    }

    T back() {
        if (this->empty()) throw;
        return *this->back_itr();
    }

    void erase_front() {
        if (!this->empty()) this->erase(this->begin());
    }

    void erase_back() {
        if (!this->empty()) this->erase(this->back_itr());
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (auto &e:a) cin >> e;
    for (auto &e:b) cin >> e;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    bool f = true;
    for (int i = 1; i < n; i++) if (a[i] == a[i - 1]) f = false;
    for (int i = 1; i < m; i++) if (b[i] == b[i - 1]) f = false;
    if (!f) {
        cout << 0 << endl;
        return 0;
    }
    auto in_r = [](vector<int> r, int e) { return binary_search(r.begin(), r.end(), e); };
    auto in_a = [&in_r, &a](int e) { return in_r(a, e); };
    auto in_b = [&in_r, &b](int e) { return in_r(b, e); };
    ll r = 1;
    for (int i = n * m; i > 0; i--) {
        if (in_a(i) && in_b(i)) {
            r *= 1;
        } else if (in_a(i)) {
            r *= b.end() - lower_bound(b.begin(), b.end(), i);
        } else if (in_b(i)) {
            r *= a.end() - lower_bound(a.begin(), a.end(), i);
        } else {
            r *= (a.end() - lower_bound(a.begin(), a.end(), i)) * (b.end() - lower_bound(b.begin(), b.end(), i)) -
                 (n * m - i);
        }
        r %= mod;
    }
    cout << r << endl;
}
