#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int N, X, T;
    cin >> N >> X >> T;

    cout << (int)(ceil(1.0*N / X) * T) << endl;

    return 0;
}