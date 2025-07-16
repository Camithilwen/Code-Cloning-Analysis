#include <iostream>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int sum = max(a, b);
    if (max(a, b) - min(a, b) >= 2) {
        sum += max(a,b) - 1;
    }
    else {
        sum += min(a,b);
    }
    cout << sum;
    return 0;
}
