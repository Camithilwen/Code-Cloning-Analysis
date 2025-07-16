#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    string N;
    cin >> N;
    for(int i = 0; i < 8; i++) {
        string ans;
        ans += N.at(0);
        int sum = N.at(0) - '0';
        for(int j = 0; j < 3; j++) {
            //cout << (i >> (j + 1)) << endl;
            if(i >> j & 1) {
                sum += N.at(j + 1) - '0';
                ans += '+';
                ans += N.at(j + 1);
            } else {
                sum -= N.at(j + 1) - '0';
                ans += '-';
                ans += N.at(j + 1);
            }
        }
        //˜cout << sum << endl;
        if(sum == 7) {
            cout << ans << "=7" << endl;
            break;
        }

    }
    return 0;
}