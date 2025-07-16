#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int x, y;
    cin >> x >> y;
    cout << (100000 * (max(0, 4 - x) + max(0, 4 - y)) + (x == 1 && y == 1 ? 400000 : 0)) << endl;
}
