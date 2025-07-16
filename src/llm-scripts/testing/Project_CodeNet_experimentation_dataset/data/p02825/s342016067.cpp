#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using WGraph = vector<vector<pair<int, ll>>>;

vector<string> three = {
    "a..",
    "a..",
    ".bb"
};
vector<string> four = {
    "ahff",
    "ahgg",
    "bbde",
    "ccde"
};
vector<string> five = {
    "ahhgg",
    "ai..f",
    "bi..f",
    "b.jje",
    "ccdde"
};
vector<string> six = {
    "aa..hi",
    "bb..hi",
    "cc..jk",
    "..ddjk",
    "..eelm",
    "..fflm"
};
vector<string> seven = {
    "ahhii..",
    "aj..mm.",
    "bjk....",
    "b.k..oo",
    "c..l..p",
    "c..l..p",
    ".ddeeff"
};

int main() {
    int n = 0;
    cin >> n;
    if (n == 2) {
        cout << -1 << endl;
    } else if (n == 3) {
        for (auto s : three) {
            cout << s << endl;
        }
    } else {
        vector<string> ans(n);
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                ans.at(i).push_back('.');
            }
        }
        int mod = n%4;
        if (mod == 0) {
            for (int i=0; i<4; i++) {
                for (int j=0; j<4; j++) {
                    ans.at(i).at(j) = four.at(i).at(j);
                }
            }
        } else if (mod == 1) {
            for (int i=0; i<5; i++) {
                for (int j=0; j<5; j++) {
                    ans.at(i).at(j) = five.at(i).at(j);
                }
            }
        } else if (mod == 2) {
            for (int i=0; i<6; i++) {
                for (int j=0; j<6; j++) {
                    ans.at(i).at(j) = six.at(i).at(j);
                }
            }
        } else if (mod == 3) {
            for (int i=0; i<7; i++) {
                for (int j=0; j<7; j++) {
                    ans.at(i).at(j) = seven.at(i).at(j);
                }
            }
        }
        int cur = 4 + mod;
        while (cur + 4 <= n) {
            for (int i=0; i<4; i++) {
                for (int j=0; j<4; j++) {
                    ans.at(cur+i).at(cur+j) = four.at(i).at(j);
                }
            }
            cur += 4;
        }
        for (auto s : ans) {
            cout << s << endl;
        }
    }
    return 0;
}
