#include <iostream>
using namespace std;

int main() {
    while (true) {
        int n;
        cin >> n;
        if (n == 0) {
            break;
        }
        for (int i = 0; i < n; i++) {
            int pm, pe, pj;
            cin >> pm >> pe >> pj;
            char output;
            if ((pm == 100 || pe == 100 || pj == 100)
                || (180 <= pm + pe)
                || (240 <= pm + pe + pj)) {
                output = 'A';
            } else if ((210 <= pm + pe + pj)
                       || (150 <= pm + pe + pj && (80 <= pm || 80 <= pe))) {
                output = 'B';
            } else {
                output = 'C';
            }
            cout << output << endl;
        }
    }
}