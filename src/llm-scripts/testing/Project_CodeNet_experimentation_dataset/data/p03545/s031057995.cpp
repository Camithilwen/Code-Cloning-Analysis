#include <bits/stdc++.h>
using namespace std;

int main() {
    string a;
    cin >> a;
    vector<int> X(4);
    for (int i = 0; i < 4; ++i) {
        X[i] = a[i]-'0';
    }
    
    for (int i = 0; i < (1 << 3); ++i) {
        bitset<3> bit(i);
        int sum = X[0];
        vector<string> ans(7);
        ans.push_back(to_string(X[0]));
        for (int j = 0; j < 3; ++j) {
            if (bit.test(j)) {
                sum += X[j+1];
                ans.push_back("+");
            }
            else
            {
                sum -= X[j+1];
                ans.push_back("-");
            }
            ans.push_back(to_string(X[j+1]));
        }
        if (sum == 7) {
            string answer = "";
            for (auto s : ans) {
                answer += s;
            }
            cout << answer << "=7" << endl;
            return 0;
        }
    }
}