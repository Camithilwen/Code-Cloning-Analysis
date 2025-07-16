#include <iostream>
#include <vector>
#include <string>
#include <cmath>
 
using namespace std;
using Int = long long int;
using UInt = unsigned long long int;
using VI = vector<long long int>;
int main(void) {
    Int r;
    cin >> r;
    if (r < 1200) {
        cout << "ABC" << endl;
    } else if (r < 2800) {
        cout << "ARC" << endl;
    } else {
        cout << "AGC" << endl;
    }
    return 0;
}

