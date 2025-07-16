// ABC178F.cpp

#include <iostream>
#include <vector>
#include <algorithm> // sort
#include <string>

#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;
using P = pair<int, char>;
using Pi = pair<int, int>;
int main()
{
    int n;
    cin >> n;
    vector<P>a(n), b(n);
    vector<P>c(n * 2);
    vector<int>count(200005);
    int num;
    int num_mx = 0;
    rep(i, n) {
        cin >> num;
        a[i].first = num;
        a[i].second = 'A';
        c[i] = a[i];
        count[num]++;
        if (i == n - 1) num_mx = num;
    }
    rep(i, n) {
        cin >> num;
        b[i].first = num;
        b[i].second = 'B';
        c[n + i] = b[i];
        count[num]++;
        if (i == n - 1) num_mx = max(num, num_mx);
    }
    int mx = 0;
    for (int i = 1; i <= num_mx; i++) {
        mx = max(mx, count[i]);
    }
    // 同じ数が半分以上あるとき、作れない
    if (mx > n) {
        cout << "No" << endl;
        return 0;
    }
    sort(c.begin(), c.end());

    vector<P> d(n), e(n);
    rep(i, n) {
        d[i] = c[i];
        e[i] = c[i + n];
    }
    vector<int>aal,bbl,abl,bal;

    rep(i, n) {
        if (d[i].second == 'A' && e[i].second == 'A') aal.push_back(i);
        if (d[i].second == 'B' && e[i].second == 'B') bbl.push_back(i);
    }

// AAの組み合わせの時は、bbの組とeを入れ替えるか、eとdを入れ替える
    rep(i, aal.size()) {
        if (d[aal[i]].first != e[bbl[i]].first) {
            swap(e[aal[i]], e[bbl[i]]);
            continue;
        }
        if (d[aal[i]].first == e[bbl[i]].first) {
            swap(e[aal[i]], d[bbl[i]]);
            continue;
        }
        if (d[bbl[i]].first != e[aal[i]].first) {
            swap(e[aal[i]], e[bbl[i]]);
            continue;
        }
        if (d[bbl[i]].first == e[aal[i]].first) {
            swap(d[aal[i]], e[bbl[i]]);
            continue;
        }
    }

    cout << "Yes" << endl;
    vector<Pi>f;
    rep(i, n) {
        if (d[i].second == 'A') f.emplace_back(d[i].first, e[i].first);
        if(e[i].second=='A') f.emplace_back(e[i].first, d[i].first);
    }
    sort(f.begin(), f.end());

    rep(i, n) {
        cout << f[i].second << " ";
    }
    cout << endl;
}
/*
6
1 1 2 2 2 3
1 2 2 2 3 3
*/
