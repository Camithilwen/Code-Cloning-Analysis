#include <bits/stdc++.h>
using namespace std;

int main(void) {
    string s;
    cin >> s;
    map<char, int> m;
    for (int i = 0; i < (int)s.size(); i++) {
        m[s.at(i)]++;
    }
    for (char i = 'a'; i <= 'z'; i++) {
        if (m[i] == 0) {
            cout << i << endl;
            return 0;
        }
    }
    cout << "None" << endl;
    return 0;
}