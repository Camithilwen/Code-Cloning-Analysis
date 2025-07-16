#include <iostream>
using namespace std;
int main() {
    string s;
    cin >> s;
    for (char c='a'; c<='z'; c++) {
        if (s.find(c) == string::npos) {
            cout << c << endl;
            return 0;
        }
    }
    cout << "None" << endl;
}