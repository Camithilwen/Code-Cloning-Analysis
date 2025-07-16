#include <bits/stdc++.h>
using namespace std;

// これだとWAになる・・・
int main() {
    int N, M;
    cin >> N >> M;
    map<int, int> waCountMap;
    map<int, bool> acMap;
    int p;
    string s;
    for (int i = 0; i < M; i++) {
        cin >> p >> s;
        if (acMap.find(p) == acMap.end()) {
            if (s == "AC") {
                acMap[p] = true;
            } else {
                waCountMap[p]++;
            }
        }
    }
    int waCount = 0;
    for (auto itr = waCountMap.begin(); itr != waCountMap.end(); itr++) {
        if (acMap.find(itr->first) != acMap.end()) {
            waCount += itr->second;
        }
    }
    cout << acMap.size() << " " << waCount;
}
