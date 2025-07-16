#include <bits/stdc++.h>
#include <iostream>
#include<math.h>
using namespace std;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
int main()
{
    int N;
    cin >> N;
    map<int64_t, int>d;
    for (int i=0; i<N; i++) {
        int64_t n;
        cin >> n;
        if (d.count(n) > 0) {
            d[n] = d[n] + 1;
        } else {
            d[n] = 1;
        }
    }
    int64_t sum = 0;
    for (auto c: d) {
        if (c.second % 2 != 0) {
            sum += 1;
        }
    }

    cout << sum << endl;
    return 0;
}