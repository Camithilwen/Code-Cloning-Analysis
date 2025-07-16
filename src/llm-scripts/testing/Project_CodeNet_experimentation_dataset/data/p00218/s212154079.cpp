#include <iostream>

using namespace std;

char divide(int m, int e, int j) {
    if (m == 100 || e == 100 || j == 100) return 'A';
    if ( (m+e)/2 >= 90 ) return 'A';
    if ( (m+e+j)/3 >= 80 ) return 'A';
    if ( (m+e+j)/3 >= 70 ) return 'B';
    if ( (m+e+j)/3 >= 50 && (m >= 80 || e >= 80) ) return 'B';
    return 'C';
}

int main() {
    int n;
    while (cin >> n, n) {
        while (n--) {
            int pm, pe, pj;
            cin >> pm >> pe >> pj;
            cout << divide(pm, pe, pj) << endl;
        }
    }
    return 0;
}