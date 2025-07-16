// 解説見たやつ
#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#define repeat(i, n) for (int i = 0; (i) < (n); ++(i))
#define repeat_from(i, m, n) for (int i = (m); (i) < (n); ++(i))
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

int main() {
    int h, w;
    cin >> h >> w;

    map<int, int> s;
    multiset<int> vals;

    repeat(i, w) s[i] = i;
    repeat(i, w) vals.insert(0);

    repeat(i, h) {
        int l, r;
        cin >> l >> r;
        --l;
        auto it = s.lower_bound(l);
        int mr = -1;
        while (it != s.end() && it->first <= r) {
            setmax(mr, it->second);
            int x = it->first - it->second;
            vals.erase(vals.find(x));
            //https://ox8000ffff.hatenadiary.org/entry/20100225/1267201650
            //後置インクリメントはオブジェクトのコピーがeraseの引数になる
            s.erase(it++);
        }
        if (mr != -1 && r < w) {
            vals.insert(r - mr);
            s[r] = mr;
        }
        int ans = -1;
        if (vals.size() > 0) {
            ans = *vals.begin() + (i + 1);
        }
        cout << ans << endl;
    }
}