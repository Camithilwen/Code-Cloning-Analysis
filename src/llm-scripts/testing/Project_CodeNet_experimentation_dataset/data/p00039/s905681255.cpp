#include <iostream>
using namespace std;

int main() {
    char input[1000];
    while (cin >> input) {
        char pre = '0';
        int output = 0;
        for (int i = 0; input[i] != '\0'; i++) {
            switch (input[i]) {
            case 'M':
                output += (pre == 'C') ? 800 : 1000;
                break;
            case 'D':
                output += (pre == 'C') ? 300 : 500;
                break;
            case 'C':
                output += (pre == 'X') ? 80 : 100;
                break;
            case 'L':
                output += (pre == 'X') ? 30 : 50;
                break;
            case 'X':
                output += (pre == 'I') ? 8 : 10;
                break;
            case 'V':
                output += (pre == 'I') ? 3 : 5;
                break;
            case 'I':
                output++;
                break;
            }
            pre = input[i];
        }
        cout << output << endl;
    }
}