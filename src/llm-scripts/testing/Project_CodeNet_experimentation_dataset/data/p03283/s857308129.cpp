#include <bits/stdc++.h>
using namespace std;

typedef int64_t Int;
#define all(x) (x).begin(), (x).end()
 
const double EPS = 1e-10;
const Int INF = 1e18;
const int inf = 1e9;
const Int mod = 1e9+7;

bool print_space_enable = false;
void print() { 
    cout << '\n'; 
    print_space_enable = false;
}

template <class Head, class... Tail>
void print(Head&& head, Tail&&... tail) {
    if (print_space_enable) cout << " ";
    cout << fixed << setprecision(15) << head;
    print_space_enable = true;
    print(std::forward<Tail>(tail)...);
}

template<typename T>
void print(vector<T> v) {
    for (size_t i = 0; i < v.size(); i++) {
        if (i > 0) std::cout << " ";
        std::cout << v[i];
    }
    std::cout << std::endl;
}

int main() {
    Int n, m, q;
    cin >> n >> m >> q;
    vector<pair<Int, Int>> a(m);
    for (Int i = 0; i < m; i++) {
        cin >> a[i].first >> a[i].second;
        a[i].first--, a[i].second--;
    }
    vector<pair<Int, Int>> b(q);
    for (Int i = 0; i < q; i++) {
        cin >> b[i].first >> b[i].second;
        b[i].first--, b[i].second--;
    }
    vector<vector<Int>> v(n);
    for (Int i = 0; i < m; i++) {
        v[a[i].first].push_back(a[i].second);
    }
    for (Int i = 0; i < n; i++) {
        sort(all(v[i]));
        v[i].push_back(INF);
    }
    for (Int i = 0; i < q; i++) {
        Int res = 0;
        for (Int j = 0; j < n; j++) {
            if (j < b[i].first) continue;
            if (b[i].second < j) break;
            res += upper_bound(all(v[j]), b[i].second) - v[j].begin();
        }
        print(res);
    }
    return 0;
}
