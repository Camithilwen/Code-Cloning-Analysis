#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int ans = 7;
    string w[] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };
    for (unsigned int i = 0; i < 7; i++) {
        if(s == w[i]) {
            ans -= i;
        }
    }
    cout << ans << endl;
}