#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
multiset<int> s;

int main() {
    int n;
    cin >> n;
    s.clear();
    for (int i = 1; i <= n; i++) {
        int tmp;
        scanf("%d", &tmp);
        auto id = s.lower_bound(tmp);
        if (id != s.begin()) s.erase(--id);
        s.insert(tmp);
    }
    cout << s.size();

}