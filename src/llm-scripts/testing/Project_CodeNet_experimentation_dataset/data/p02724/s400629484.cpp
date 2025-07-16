#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;
using ll = long long;


int main() {
    int x;
    cin >> x;
    int a = x / 500;
    int b = (x % 500) / 5;
    cout << a * 1000 + b * 5 << endl;
}