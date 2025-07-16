#include <bits/stdc++.h>
using namespace std;

int main(void){
    int a, b, c, d, in;
    cin >> in;
    a = in / 1000;
    b = in % 1000 / 100;
    c = in % 1000 % 100 / 10;
    d = in % 1000 % 100 % 10;
    vector<char> op(3);
    if (a + b + c + d == 7) {
        op[0] = '+';
        op[1] = '+';
        op[2] = '+';
    } else if (a + b + c - d == 7) {
        op[0] = '+';
        op[1] = '+';
        op[2] = '-';
    } else if (a + b - c + d == 7) {
        op[0] = '+';
        op[1] = '-';
        op[2] = '+';
    } else if (a - b + c + d == 7) {
        op[0] = '-';
        op[1] = '+';
        op[2] = '+';
    } else if (a + b - c - d == 7) {
        op[0] = '+';
        op[1] = '-';
        op[2] = '-';
    } else if (a - b + c - d == 7) {
        op[0] = '-';
        op[1] = '+';
        op[2] = '-';
    } else if (a - b - c + d == 7) {
        op[0] = '-';
        op[1] = '-';
        op[2] = '+';
    } else if (a - b - c - d == 7) {
        op[0] = '-';
        op[1] = '-';
        op[2] = '-';
    }
    cout << a << op[0] << b << op[1] << c << op[2] << d << "=7\n";    
}
