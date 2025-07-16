#include <iostream>
using namespace std;

string s;

int main() {
    cin >> s;
    if (s.length() % 2 != 0) {
        cout << "No\n";
        return 0;
    }
    bool works = true;
    for (int i=0; i<s.length(); i+=2) {
        if (s[i] != 'h' || s[i + 1] != 'i')
            works = false;
    }
    if (works)
        cout << "Yes\n";
    else
        cout << "No\n";
}