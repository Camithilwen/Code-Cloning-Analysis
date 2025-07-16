#include <bits/stdc++.h>

using namespace std;

int main() {
    string S;
    cin >> S;

    vector<string> vec = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};

    int cnt = 0;
    for (string x:vec) {
        if (S == x) {
            cout << 7 - cnt << endl;
        } else {
            cnt++;
        }
    }
}