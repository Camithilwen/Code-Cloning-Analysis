#include <iostream>
#include <algorithm>
#include <array>
#include <set>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> graph[n];
    array<int, 3> points[n];
    int cost[n];
    for (int i = 0; cin >> points[i][0] >> points[i][1]; i++) {
        points[i][2] = i;
        cost[i] = INT_MAX;
    }
    sort(points, points + n, [](const array<int, 3>& left, const array<int, 3>& right) {
        return left[0] < right[0];
    });
    for (int i = 1; i < n; i++) {
        auto dist = min(abs(points[i - 1][0] - points[i][0]), abs(points[i - 1][1] - points[i][1]));
        graph[points[i - 1][2]].emplace_back(points[i][2], dist);
        graph[points[i][2]].emplace_back(points[i - 1][2], dist);
    }
    sort(points, points + n, [](const array<int, 3>& left, const array<int, 3>& right) {
        return left[1] < right[1];
    });
    for (int i = 1; i < n; i++) {
        auto dist = min(abs(points[i - 1][0] - points[i][0]), abs(points[i - 1][1] - points[i][1]));
        graph[points[i - 1][2]].emplace_back(points[i][2], dist);
        graph[points[i][2]].emplace_back(points[i - 1][2], dist);
    }
    long long result = 0;
    set<int> mst = {0};
    set<pair<int, int>> set;
    auto update = [&](const vector<pair<int, int>>& nodes) {
        for (auto& p : nodes) {
            if (mst.find(p.first) != end(mst)) {
                continue;
            }
            if (cost[p.first] > p.second) {
                set.erase({cost[p.first], p.first});
                cost[p.first] = p.second;
                set.emplace(p.second, p.first);
            }
        }
    };
    update(graph[0]);
    do {
        auto current = set.begin()->second;
        auto weight = set.begin()->first;
        set.erase(set.begin());
        mst.emplace(current);
        result += weight;
        update(graph[current]);
    } while (!set.empty());
    cout << result;
    return 0;
}
