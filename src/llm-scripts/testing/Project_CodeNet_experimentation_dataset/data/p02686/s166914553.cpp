#include<bits/stdc++.h>
using namespace std;

struct Stat {
    int unmatchedOpening, unmatchedClosing, index;
    Stat(int _uo, int _uc, int _index): unmatchedOpening(_uo), unmatchedClosing(_uc), index(_index) {}
};

//Comparing two stats which unmatchedOpening - unmatchedClosing >= 0
bool cmpFirst(Stat a, Stat b) {
    return a.unmatchedClosing < b.unmatchedClosing;
}

//Comparing two stats which unmatchedOpening - unmatchedClosing < 0
bool cmpSecond(Stat a, Stat b) {
    return a.unmatchedOpening > b.unmatchedOpening;
}

//{unmatchedOpening, unmatchedClosing}
pair<int, int> getStat(string s) {
    int unmatchedOpening = 0;
    int unmatchedClosing = 0;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            unmatchedOpening += 1;
        } else {
            if (unmatchedOpening > 0)
                unmatchedOpening -= 1;
            else
                unmatchedClosing += 1;
        }
    }

    return make_pair(unmatchedOpening, unmatchedClosing);
}

int main() {
    int n;
    vector<Stat> first; //unmatchedOpening - unmatchedClosing >= 0
    vector<Stat> second; //unmatchedOpening - unmatchedClosing < 0

    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        auto stat = getStat(s);
        if (stat.first - stat.second >= 0)
            first.push_back(Stat(stat.first, stat.second, i));
        else
            second.push_back(Stat(stat.first, stat.second, i));
    }

    sort(first.begin(), first.end(), cmpFirst);
    sort(second.begin(), second.end(), cmpSecond);

    bool valid = true;
    int balance = 0;

    for (auto f: first) {
        if (balance - f.unmatchedClosing < 0) {
            valid = false;
            break;
        }

        balance -= f.unmatchedClosing;
        balance += f.unmatchedOpening;
    }

    for (auto s: second) {
        if (balance - s.unmatchedClosing < 0) {
            valid = false;
            break;
        }

        balance -= s.unmatchedClosing;
        balance += s.unmatchedOpening;
    }

    if (balance != 0)
        valid = false;

    if (valid) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}

/*
Test cases:

4
(
))(((
)((
)))
*/
