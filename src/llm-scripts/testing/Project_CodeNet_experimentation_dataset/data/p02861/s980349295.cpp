#include <bits/stdc++.h>
using namespace::std;

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef array<int, 3> tri;
typedef long double ld;

template <class T> istream& operator>>(istream& I, vector<T>& v) {for (T &e: v) I >> e; return I;}
template <class T> ostream& operator<<(ostream &O, const vector<T>& v) {for (const T &e: v) O << e << ' '; return O;}


void _main() {
        int n; cin >> n;
        vector<pair<int,int>> a(n);
        for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;


        sort(all(a));
        auto calc = [](vector<pair<int,int>> a) {
                double cnt = 0;
                for (int i = 1; i < a.size(); i++) {
                        double dist = sqrt(pow(a[i].first - a[i - 1].first,2) + pow(a[i].second - a[i - 1].second, 2));
                        cnt += dist;
                }
                return cnt;
        };


        double ans = 0, k = 0;
        sort(all(a));
        do {
                ans += calc(a);
                k++;
        } while (next_permutation(all(a)));


        ans /= k;
        cout << fixed << setprecision(10) << ans;
}



signed main() {
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//        freopen("input.txt", "r", stdin);
        int _t = 1;
//        cin >> _t;
        while (_t--) _main();
        return 0;
}