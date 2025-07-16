#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
using ll = long long int;
int main()
{
    int x, y;
    cin >> x >> y;

    int prize = 0;

    if (x <= 3) {
        prize += (4-x) * 100000;
    }
    if (y <= 3) {
        prize += (4-y) * 100000;
    }
    if (x == 1 && y == 1) {
        prize += 400000;
    }
    cout << prize << endl;
}