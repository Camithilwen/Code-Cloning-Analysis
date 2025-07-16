#include <iostream>

using namespace std;

int main() {
    int A;
    int B;
    cin >> A;
    cin >> B;
    int eatA = 0;
    int eatB = 0;
    for (int i = 0; i < 16; i++) {
        if (i % 2 == 0) {
            eatA++;
        } else {
            eatB++;
        }
    }
    if (eatA >= A && eatB >= B) {
        cout << "Yay!" << endl;
    } else {
        cout << ":(" << endl;
    }
}