#include<iostream>
using namespace std;

int main() {
    int n, Y, x = 0, y, z;
    cin >> n >> Y;
    bool can = false;

    int t = Y / 1000 - n;
    while (t >= 0) {
        y = t / 4; // >= 0
        z = n - x - y;
        if (t % 4 == 0 && z >= 0) {
            can = true;
            break;
        }
        t -= 9;
        x++;
    }

    if (can) cout << x << ' ' << y << ' ' << z << endl;
    else cout << "-1 -1 -1" << endl;
}