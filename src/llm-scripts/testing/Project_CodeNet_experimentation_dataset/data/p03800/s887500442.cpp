
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    auto check = [&](char out0, char out1) {
        auto a = out0;
        char out2;
        auto v = vector<char>();
        v.push_back(out0);
        v.push_back(out1);
        auto f = [](char in1, char out0, char out1) {
            char out2;
            if (in1 == 'o') {
                if (out0 == 'S' && out1 == 'S') out2 = 'S';
                if (out0 == 'S' && out1 == 'W') out2 = 'W';
                if (out0 == 'W' && out1 == 'S') out2 = 'W';
                if (out0 == 'W' && out1 == 'W') out2 = 'S';
            } else {
                if (out0 == 'S' && out1 == 'S') out2 = 'W';
                if (out0 == 'S' && out1 == 'W') out2 = 'S';
                if (out0 == 'W' && out1 == 'S') out2 = 'S';
                if (out0 == 'W' && out1 == 'W') out2 = 'W';
            }
            return out2;
        };
        for (int i = 1; i < n; i++) {
            char in1 = s[i];
            out2 = f(in1, out0, out1);
            v.push_back(out2);
            out0 = out1;
            out1 = out2;
        }

        if (out2 == a) {
            v.erase(v.end() - 1);
            if (f(s[0], v[n - 1], v[0]) == v[1]) {
                return v;
            }
        }
        return vector<char>();
    };

    auto intToC = [](int a) {
        return a == 0 ? 'S' : 'W';
    };

    for (int i = 0; i < 4; i++) {
        char out0 = intToC(i % 2);
        char out1 = intToC(i / 2 % 2);
        auto v = check(out0, out1);
        if (v.size() > 0) {
            for (auto c : v) {
                putchar(c);
            }
            puts("");
            return 0;
        }
    }

    puts("-1");
}
