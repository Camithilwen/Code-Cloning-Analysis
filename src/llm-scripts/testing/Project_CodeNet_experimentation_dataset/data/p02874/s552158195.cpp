#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

pair<int, int> intersect(const pair<int, int> &lhs, const pair<int, int> &rhs) {
    return {max(lhs.first, rhs.first), min(lhs.second, rhs.second)};
}

int length(const pair<int, int> &interval) {
    if (interval.first > interval.second) {
        return 0;
    } else {
        return interval.second - interval.first + 1;
    }
}

int main() {
    int n = 0;
    cin >> n;
    vector<pair<int, int>> seg(n);
    pair<int, int> left = {0, 1e9}, right = {0, 1e9};
    for (auto &i:seg) {
        cin >> i.first >> i.second;
        if (i.first > right.first) {
            right = i;
        }
        if (i.second < left.second) {
            left = i;
        }
    }
    for (int i = 0; i < seg.size(); ++i) {
        if (seg[i] == left) {
            seg.erase(begin(seg) + i);
            i--;
            if (seg.empty()) {
                break;
            } else {
                continue;
            }
        }
        if (seg[i] == right) {
            seg.erase(begin(seg) + i);
            i--;
            if (seg.empty()) {
                break;
            } else {
                continue;
            }
        }
    }
    int ans = 0;
    if (!seg.empty()) {
        pair<int, int> inter = {0, -1};
        for (const auto &i:seg) {
            if (length(i) > length(inter)) {
                inter = i;
            }
        }
        ans = length(inter) + length(intersect(left, right));
    } else {
        ans = length(left) + length(right);
    }
    if (!seg.empty()) {
        sort(begin(seg), end(seg));
        vector<int> suf(seg.size());
        suf[seg.size() - 1] = seg[seg.size() - 1].second;
        for (int i = static_cast<int>(seg.size()) - 2; i >= 0; --i) {
            suf[i] = min(suf[i + 1], seg[i].second);
        }
        for (int i = 0; i < seg.size(); ++i) {
            int first = length(intersect(seg[i], left)),
                second = i + 1 < seg.size() ? length(intersect({right.first, suf[i + 1]}, right)) : length(right);
            ans = max(ans, first + second);
        }
        ans = max(ans, length(left) + length(intersect({right.first, suf[0]}, right)));
    }
    cout << ans;
    return 0;
}