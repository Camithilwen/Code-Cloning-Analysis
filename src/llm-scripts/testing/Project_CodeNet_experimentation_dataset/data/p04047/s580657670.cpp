#include <iostream>
#include <algorithm>
using namespace std;

int N;
int L[200];

int main() {
    int total = 0;
    cin >> N;
    for (int i = 0; i < 2 * N; i++) {
        cin >> L[i];
    }
    sort(L, L + 2 * N);
    for (int i = 0; i < 2 * N; i += 2) {
        total += min(L[i], L[i + 1]);
    }
    cout << total;
}