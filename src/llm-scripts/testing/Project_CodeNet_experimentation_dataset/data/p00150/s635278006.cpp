#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    const int MAX = 10001;
    bool isPrime[MAX];
    fill_n(isPrime, MAX, true);
    for (int i = 4; i < MAX; i += 2) {
        isPrime[i] = false;
    }
    for (int i = 3; i * i <= MAX; i += 2) {
        if (isPrime[i]) {
            for (int j = i * 2; j < MAX; j += i) {
                isPrime[j] = false;
            }
        }
    }
    while (true) {
        int n;
        cin >> n;
        if (n == 0) {
            break;
        }
        if (n % 2 == 0) {
            n--;
        }
        for (int i = n; i >= 5; i -= 2) {
            if (isPrime[i] && isPrime[i - 2]) {
                cout << i - 2 << " " << i << endl;
                break;
            }
        }
    }
}