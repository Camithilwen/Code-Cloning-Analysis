#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void printVector(vector<int> v) {
    for (auto x : v) {
        cout << x << ' ';
    }
    cout << '\n';
}

void printArray(ll A[], int size) {
    for (int i = 0; i <= size - 1; i++) cout << A[i] << ' ';
}

int main() {
    int a, b, c, d, e, k;
    cin >> a >> b >> c >> d >> e >> k;
    if (e - a > k) cout << ":(" << '\n';
    else cout << "Yay!" << '\n';
    return 0;
}