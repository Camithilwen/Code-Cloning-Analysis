#include <vector>
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int m = 1e9;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        m = min(__builtin_ctz(a), m);
    }
    cout << m << endl;
}