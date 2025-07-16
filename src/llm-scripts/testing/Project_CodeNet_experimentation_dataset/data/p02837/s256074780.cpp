#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int main() {
    int n;
    cin >> n;
    vector<vector<pair<int, bool>>> shougen(n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a.at(i);
        for (int j = 0; j < a.at(i); j++) {
            int x;
            bool y;
            cin >> x >> y;
            shougen.at(i).push_back(make_pair(x, y));
        }
    }

    int cnt_max = 0;
    for (int i = 0; i < (1 << n); i++) {
        bitset<15> s(i);
        bool flag = true;
        for (int j = 0; j < n; j++) {
            if (s.test(j)) {
                for (int k = 0; k < a.at(j); k++) {
                    if (s.test(shougen.at(j).at(k).first - 1) !=
                        shougen.at(j).at(k).second) {
                        flag = false;
                        break;
                    }
                }
                if (flag == false) {
                    break;
                }
            }
        }
        if (flag == true) {
            cnt_max = (cnt_max > (int)s.count()) ? cnt_max : (int)s.count();
        }
    }
    cout << cnt_max << endl;
    return 0;
}