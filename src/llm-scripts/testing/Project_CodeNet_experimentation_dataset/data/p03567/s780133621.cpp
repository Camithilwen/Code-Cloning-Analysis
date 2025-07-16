#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
    string s;
    cin >> s;

    int l = s.length();

    if (s.find("AC") != string::npos) {
        cout << "Yes" << endl;
    } else {

        cout << "No" << endl;
    }
}