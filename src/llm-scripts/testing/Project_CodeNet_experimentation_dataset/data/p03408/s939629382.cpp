#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <queue>
#include <cmath>
using namespace std;

int main() { 
    
    int n, m;
    cin >> n;
    unordered_map<string, int> um;
    int res = 0;
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        um[s]++;
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> s;
        um[s]--;
    }
    for (auto p : um) {
        res = max(res, p.second);
    }
    cout << res << endl;
}


