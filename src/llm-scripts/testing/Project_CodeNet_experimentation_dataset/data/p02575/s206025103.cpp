#include <bits/stdc++.h>
using namespace std;

int main(void){
    int h, w;
    cin >> h >> w;
    map<int, int> cur2start;
    multiset<int> values;

    for (int i = 0; i < w; i++) {
        cur2start[i] = i;
        values.insert(0);
    }

    for (int i = 0; i < h; i++) {
        int left, right;
        cin >> left >> right;
        auto it = cur2start.lower_bound(left - 1);
        int right_bound_of_start = -1;
        while (it != cur2start.end() && it->first <= right) {
            right_bound_of_start = max(right_bound_of_start, it->second);
            values.erase(values.find(it->first - it->second));
            cur2start.erase(it++);
        }
        if (right_bound_of_start != -1 && right < w) {
            values.insert(right - right_bound_of_start);
            cur2start[right] = right_bound_of_start;
        }
        int ans = -1;
        if (values.size() > 0) {
            ans = *values.begin() + i + 1;
        }
        cout << ans << endl;
    }
}