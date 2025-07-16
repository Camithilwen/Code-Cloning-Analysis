#include <stdio.h>
#include <iostream>
 
using namespace std;
 
int main() {
 
    int a[5];
    int kari;
    char d;
     
    while (cin >> a[0] >> d >> a[1] >> d >> a[2] >> d >> a[3] >> d >> a[4]) {
        for (int i = 4; i > 0; i--) {
            for (int j = 0; j < i; j++) {
                if (a[j] > a[j+1]) {
                    kari = a[j];
                    a[j] = a[j+1];
                    a[j+1] = kari;
                }
            }
        }
        if (a[0] == a[1] || a[1] == a[2] || a[2] == a[3] || a[3] == a[4]) {
            if ((a[0] == a[1] && a[1] == a[2]) || (a[1] == a[2] && a[2] == a[3]) || (a[2] == a[3] && a[3] == a[4])) {
                if (((a[0] == a[1] && a[1] == a[2]) && (a[3] == a[4])) || ((a[0] == a[1]) && (a[2] == a[3] && a[3] == a[4]))) {
                    cout << "full house" << endl;
                } else if ((a[0] == a[1] && a[1] == a[2] && a[2] == a[3]) || (a[1] == a[2] && a[2] == a[3] && a[3] == a[4])){
                    cout << "four card" << endl;
                }else {
                    cout << "three card" << endl;
                }
            } else if ((a[0] == a[1] && a[2] == a[3]) || (a[0] == a[1] && a[3] == a[4]) || (a[1] == a[2] && a[3] == a[4])) {
                if ((a[0] == a[1] && a[1] == a[2] && a[2] == a[3]) || (a[1] == a[2] && a[2] == a[3] && a[3] == a[4])) {
                    cout << "four card" << endl;
                } else {
                    cout << "two pair" << endl;
                }
            } else {
                cout << "one pair" << endl;
            }
        } else if ((a[1] == a[0] + 1 && a[2] == a[1] + 1 && a[3] == a[2] + 1 && a[4] == a[3] + 1) || (a[0]  == 1 && a[1] == 10 && a[2] == a[1] + 1 && a[3] == a[2] + 1 && a[4] == a[3] + 1)){
            cout << "straight" << endl;
        } else {
            cout << "null" << endl;
        }
    }
    return 0;
}