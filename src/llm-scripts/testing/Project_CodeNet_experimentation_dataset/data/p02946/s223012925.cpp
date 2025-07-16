#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
    int k, x;
    cin >> k >> x;

    for (int i = 1; i < 2 * k; i++) cout << x - k + i << ' ';
    cout << endl;
    return 0;
}
