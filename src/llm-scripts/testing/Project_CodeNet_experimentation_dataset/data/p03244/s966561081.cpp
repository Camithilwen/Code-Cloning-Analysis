#include <iostream>
#include <vector>
#include <map>
using namespace std;
typedef pair<int, int> P;

int main() {
    int n; cin >> n;
    map<int, int> odd, even;

    for (int i = 1; i <= n; i++) {
        int v; cin >> v;
        if (i % 2)  odd[v]++;
        else even[v]++;
    }

    int o1 = 0, o2 = 0, odd_v;
    for (auto ite = odd.begin(); ite != odd.end(); ite++) {
        if (o1 < ite->second) {
            o2 = o1;
            o1 = ite->second;
            odd_v = ite->first;
        } else {
            if (o2 < ite->second) o2 = ite->second;
        }
    }
    int e1 = 0, e2 = 0, even_v;
    for (auto ite = even.begin(); ite != even.end(); ite++) {
        if (e1 < ite->second) {
            e2 = e1;
            e1 = ite->second;
            even_v = ite->first;
        } else {
            if (e2 < ite->second) e2 = ite->second;
        }
    }
    int ans;
    if (odd_v == even_v) {
        ans = min(n - o1 - e2, n - o2 - e1);
    } else {
        ans = n - o1 - e1;
    }
    cout << ans << endl;
}