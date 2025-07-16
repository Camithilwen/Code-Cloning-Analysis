#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    if (s.length()%2 != 0) {
        cout << "No" << endl;
        return 0;
    }
    else {
        for (int i = 0; i < s.length(); i++) {
            if (i%2==0 && s[i]!='h' || i%2==1 && s[i]!='i') {
                cout << "No" << endl;
                return 0;
            }
        }
    }

    cout << "Yes" << endl;
}