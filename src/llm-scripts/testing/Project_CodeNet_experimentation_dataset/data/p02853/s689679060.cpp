#include <iostream>
using namespace std;

int main() {
    int x,y;
    cin >> x >> y;
    if (x == 1 && y == 1) {
        cout << 1000000 << endl;
    } else {
        cout << (max(0,4-x)+max(0,4-y))*100000 << endl;
    }
    return 0;
}