#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    string res = "AC";
    int C_cnt = 0;
    if (s.at(0) == 'A') {
        for (int i = 1; i < s.size(); i++) {
            if (s.at(i) == 'C') {
                if (2 <= i && i <= (s.size()-2)) {
                    C_cnt++;
                } else {
                    res = "WA";
                }
            } else {
                if (!('a' <= s.at(i) && s.at(i) <= 'z')) res = "WA";
            }
        }
        if (C_cnt != 1) res = "WA";
    } else {
        res = "WA";
    }
    
    cout << res << endl; 

    return 0;
}
