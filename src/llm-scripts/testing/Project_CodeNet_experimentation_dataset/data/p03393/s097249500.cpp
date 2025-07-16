#include <bits/stdc++.h>
using namespace std;

int main() {
    //
    string str;
    vector<int> vec(26, 0);

    cin >> str;

    if (str == "zyxwvutsrqponmlkjihgfedcba") {
        cout << -1;
    } else if (str.size() == 26) {
        string tmp = str;
        next_permutation(str.begin(), str.end());

        string kekka = "";
        for (int i = 0; i < str.size(); i++) {
            kekka += str.at(i);
            if (str.at(i) > tmp.at(i)) break;
        }

        cout << kekka;
    } else {
        for (int i = 0; i < str.size(); i++) vec.at(str.at(i) - 'a')++;

        for (int i = 0; i < vec.size(); i++) {
            if (vec.at(i) == 0) {
                cout << str << (char)(i + 'a');
                break;
            }
        }
    }

    //
}
