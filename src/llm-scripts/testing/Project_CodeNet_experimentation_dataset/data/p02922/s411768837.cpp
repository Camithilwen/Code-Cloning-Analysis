#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B;
    cin >> A >> B;
    if ((B-1)%(A-1) == 0){
        cout << (B-1)/(A-1) << endl;
    }
    else {
        cout << (B-1)/(A-1) + 1 << endl;
    }
}