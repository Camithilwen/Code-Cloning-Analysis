#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N; cin >> N;
    long long x; cin >> x;
    vector<long long> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    int res = 0;
    for (int i = 0; i < N; ++i) {
        if (x >= a[i]) ++res, x -= a[i];
        else break;
    }
    if (res == N && x) --res;
    cout << res << endl;
}