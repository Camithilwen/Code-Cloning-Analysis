#include <bits/stdc++.h>
using namespace std;

int main() {
    //
    int num;
    string str;
    long long cnt = 0;
    long long all = 0;

    cin >> num >> str;
    vector<int> r;
    vector<int> g;
    vector<int> b;

    for (int i = 0; i < num; i++) {
        if (str.at(i) == 'R')
            r.push_back(i);
        else if (str.at(i) == 'G')
            g.push_back(i);
        else if (str.at(i) == 'B')
            b.push_back(i);
    }

    all = r.size() * g.size() * b.size();
    for (int i = 0; i < num; i++) {
        for (int j = i+1; j < num; j++) {
            long long k = j * 2 - i;

            if (k >= num || str.at(i) == str.at(j)) continue;
            if (str.at(k) == str.at(i) || str.at(k) == str.at(j)) continue;
            all--;
            /*
            for (int k = 0; k < b.size(); k++) {
                if (g.at(j) - r.at(i) == b.at(k) - g.at(j)) continue;
                if (b.at(k) - g.at(j) == r.at(i) - b.at(k)) continue;
                if (r.at(i) - b.at(k) == g.at(j) - r.at(i)) continue;
                cnt++;
            }
            */
        }
    }

    cout << all;
    //
}
