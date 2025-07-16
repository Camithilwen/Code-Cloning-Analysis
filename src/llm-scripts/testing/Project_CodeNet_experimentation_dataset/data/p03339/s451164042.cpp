#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    int ans = n - 1, num = 0;
    for (int i = 1; i < n; i++) {
        if (s.at(i) == 'E') num++;
    }
    //cout << num << endl;
    ans = min(ans, num);
    for (int i = 0; i < n - 1; i++) {
        if (s.at(i) == 'W') num++;
        if (s.at(i + 1) == 'E') num--;
        ans = min(ans, num);
        //cout << num << endl;
    }
    cout << ans << endl;
}