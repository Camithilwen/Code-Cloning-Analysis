#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cmath>

using namespace std;


bool is_balanced(int s, int e, vector<int>& v) {
    int len = e - s + 1;
    for (auto i: v) {
        if (i > len / 2 && len >= 2) {
            return true;
        }
    }
    return false;
}

void print(vector<int> v) {
    cout << "{ ";
    for (auto i : v) {
        cout << i << ", ";
    }
    cout << " }" << endl;
}

int main() {
    string s;
    cin >> s;
    vector<int> v(26, 0);

    int i = 0, j = 0;
    int len = (int) s.size();
    int start, end;

    while (j < len) {
        v[s[j] - 'a']++;
        if (is_balanced(i, j, v)) {
            start = i + 1;
            end = j + 1;
            cout << start << " " << end << endl;
            return 0;
        } else {
            if (j > i + 1) {
                v[s[i] - 'a']--;
                i++;
            }
        }
        j++;
    }

    cout << -1 << " " << -1 << endl;

    return 0;
}