#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <queue>
#include <cmath>
using namespace std;

int main() { 
    int a, b;
    cin >> a >> b;
    string s;
    cin >> s;
    if (s.size() != a + b + 1) {
        cout << "No" << endl;
        return 0;
    }
    for (int i = 0; i < s.size(); i++ ) {
        if (i == a) {
            if (s[i] != '-') {
                cout << "No" << endl;
                return 0;
            }
        } else {
            if (s[i] < '0' || s[i] > '9') {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
}


