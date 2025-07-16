#include<iostream>
using namespace std;
int main () {
    long n, b, min, max;
    long total = 0;
    min = 1000000;
    max = -1000000;
    cin >> n;
    for(int i=0; i < n; i++) {
        cin >> b;
        if (b < min) {
            min = b;
        }
        if (b > max) {
            max = b;
        }
        total = total + b;
    }
    cout << min << " " << max << " " << total << endl;
    return 0;
}

