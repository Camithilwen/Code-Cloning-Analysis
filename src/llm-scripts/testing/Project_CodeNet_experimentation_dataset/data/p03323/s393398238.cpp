#include "bits/stdc++.h"

using namespace std;

void Main() {
    int A, B;
    cin >> A >> B;

    if (A <= 8 && B <= 8) {
        cout << "Yay!" << endl;
    }
    else {
        cout << ":(" << endl;
    }
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
