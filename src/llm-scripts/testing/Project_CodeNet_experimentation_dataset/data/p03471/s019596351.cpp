#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <queue>
#include <cmath>
using namespace std;


int main() { 
    // 10x + 5y + z = Y
    // x + y + z = N
    // 9x + 4y = Y - N
    int n, yy;
    cin >> n >> yy;
    yy /= 1000;
    int x = -1, y = -1, z = -1;
    for (int i = 0; 4 * i <= yy - n; i++) {
        int t = yy - n - 4 * i;
        if (t >= 0 && t % 9 == 0 && n - t / 9 - i >= 0) {
            x = t / 9;
            y = i;
            z = n - x - y;
            break;
        }
    }
    cout << x << " " << y << " " << z << endl;
}


