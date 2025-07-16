#include <bits/stdc++.h>

using namespace std;

int main() {
    int sum = 0;
    int mini = 101;
    for (int i = 0; i < 4; ++i) {
        int s;
        cin >> s;
        sum += s;
        mini = min(s, mini);
    }
    int s1, s2;
    cin >> s1 >> s2;
    cout << sum - mini + max(s1, s2) << '\n';
}
