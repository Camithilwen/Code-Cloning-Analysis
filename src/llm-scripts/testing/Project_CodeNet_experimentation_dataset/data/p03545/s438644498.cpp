#include <iostream>
using namespace std;

int main() {
    int abcd;
    cin >> abcd;
    int num[4] = {abcd / 1000, (abcd / 100) % 10, (abcd / 10) % 10, abcd % 10};
    int sum;
    bool match = false;

    for (int bit = 0; bit < (1 << 3); bit++) {
        sum = num[0];
        for (int i = 0; i < 3; i++) {
            if (bit & (1 << i)) sum -= num[i + 1];
            else
                sum += num[i + 1];
        }
        if (sum == 7) {
            match = true;
            cout << num[0];
            for (int j = 0; j < 3; j++) {
                if (bit & (1 << j)) cout << "-" << num[j + 1];
                else
                    cout << "+" << num[j + 1];
            }
            cout << "=7" << endl;
            break;
        }
        if (match) break;
    }

    return 0;
}