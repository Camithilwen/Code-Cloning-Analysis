#include <bits/stdc++.h>
using namespace std;

int main() {
    //
    int num, l;
    int sum = 0;
    int small = 999999;

    cin >> num >> l;

    for (int i = 1; i <= num; i++) {
        int tmp;
        tmp = l + i - 1;
        sum += tmp;
        if (abs(tmp) < abs(small)) small = tmp;
    }
    
    cout << sum - small;
    //
}
