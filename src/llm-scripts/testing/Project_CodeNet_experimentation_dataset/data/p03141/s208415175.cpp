#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#define repeat(i, n) for (int i = 0; (i) < (n); ++(i))
#define repeat_from(i, m, n) for (int i = (m); (i) < (n); ++(i))
#define sz(x) int(x.size())
using namespace std;
template <class T>
void setmax(T &a, T const &b) {
    if (a < b) a = b;
}

template <class T>
void setmin(T &a, T const &b) {
    if (a > b) a = b;
}

template <typename T, typename X>
auto vectors(T a, X x) { return vector<T>(x, a); }

template <typename T, typename X, typename Y, typename... Zs>
auto vectors(T a, X x, Y y, Zs... zs) {
    auto cont = vectors(a, y, zs...);
    return vector<decltype(cont)>(x, cont);
}

// 高橋が料理i選んだらスコアはAi + Bi増え
// 青木が料理i選んだらスコアは-(Ai + Bi)増える

#define NDEBUG

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    vector<int> ab(n);
    repeat(i, n) {
        cin >> a[i] >> b[i];
        ab[i] = a[i] + b[i];
    }

    sort(ab.rbegin(), ab.rend());
    long long ans = 0;
    repeat(i, n) ans -= b[i];
    repeat(i, n) {
        if (i % 2 == 0) ans += ab[i];
    }

    cout << ans << endl;

    return 0;
}