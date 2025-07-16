#include <iostream>
#include <memory>
#include <string>
#include <vector>

#define rep(i, n) for (int i = 0; i < (n); ++i)

using namespace std;

int main() {
    string x;
    cin >> x;
    for (auto ch : x) {
        if (ch == '7') {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}

