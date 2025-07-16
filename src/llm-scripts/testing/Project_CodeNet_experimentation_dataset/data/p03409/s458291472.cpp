#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

int main()
{
    int n;

    cin >> n;
    vector<pair<int, int>> red;
    vector<pair<int, int>> blue;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        red.emplace_back(b, a);
    }
    for (int i = 0; i < n; i++) {
        int c, d;
        cin >> c >> d;
        blue.emplace_back(c, d);
    }

    sort(red.begin(), red.end(), greater<pair<int, int>>());
    sort(blue.begin(), blue.end());
    int ans = 0;

    for (auto bit = blue.begin(); bit != blue.end(); bit++) {
        auto it = red.begin();
        while (it != red.end()) {
            if (it->first < bit->second && it->second < bit->first) {
                ans++;
                red.erase(it);
                break;
            }
            it++;
        }
    }

    cout << ans << endl;
    return 0;
}