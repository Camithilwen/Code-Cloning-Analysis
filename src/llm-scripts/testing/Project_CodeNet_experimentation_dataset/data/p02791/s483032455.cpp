#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> p(n);
    int cnt = 0, min = 200001;
    for (int i = 0; i < n; i++) {
        cin >> p.at(i);
        if (p.at(i) <= min) cnt++;
        if (p.at(i) < min) min = p.at(i);
    }

    cout << cnt << endl;

    return 0;
}
