#include <iostream>

using namespace std;

int main()
{
    string s;
    cin >> s;
    if ((s[0] == 'R') && (s[1] == 'R') && (s[2] == 'R')) {
        cout << "3";
    }
    else if (((s[0] == 'R') && (s[1] == 'R')) || ((s[1] == 'R') && (s[2] == 'R'))) {
        cout << "2";
    }
    else if (s[0] == 'R' || s[1] == 'R' || s[2] == 'R') {
        cout << "1";
    }
    else
        cout << "0";

    return 0;
}