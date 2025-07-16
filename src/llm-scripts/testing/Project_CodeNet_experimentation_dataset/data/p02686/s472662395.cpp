#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

#define debug(x) (cout << # x ": " << x << endl)
#define ll long long int
#define repeat(n) for (int i = 0; i < n; ++i)
#define all(x) x.begin(), x.end()

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> s1, s2;

    repeat(n) {
        string s;
        cin >> s;

        for(auto it = s.find("()"); it != string::npos; it = s.find("()")) {
            s.erase(it, 2);
        }

        int lc = count(all(s), ')');
        int rc = count(all(s), '(');

        if (rc - lc >= 0) {
            s1.push_back(make_pair(lc, rc));
        } else {
            s2.push_back(make_pair(lc, rc));
        }
    }

    sort(all(s1), [](const auto& lhs, const auto& rhs){ 
        return lhs.first < rhs.first;
    });
    sort(all(s2), [](const auto& lhs, const auto& rhs){ 
        return lhs.second > rhs.second;
    });

    int le = 0, re = 0;
    for (auto& s: s1) {
        le = le + s.first - min(s.first, re);
        re = re - min(s.first, re) + s.second;
    }
    for (auto& s: s2) {
        le = le + s.first - min(s.first, re);
        re = re - min(s.first, re) + s.second;
    }


    if (le == 0 && re == 0) {
        cout << "Yes";
    } else {
        cout << "No";
    }

    return 0;
}