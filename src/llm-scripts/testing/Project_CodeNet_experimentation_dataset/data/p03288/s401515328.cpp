#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int R;
    cin >> R;
    if(R < 1200) {
        cout << "ABC\n";
    } else if(R<2800) {
        cout << "ARC\n";
    } else {
        cout << "AGC\n";
    }
    return 0;
}
