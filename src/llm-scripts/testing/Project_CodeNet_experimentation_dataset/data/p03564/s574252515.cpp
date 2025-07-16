#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    int k;
    int numShow = 1;
    int minNumber = 9999999;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        // 操作Aの処理
        for (int a = i; a < n; a++) {
            numShow *= 2;
            if (numShow > minNumber) {
                break;
            }
        }

        // 操作Bの処理
        for (int b = n - i; b < n; b++) {
            numShow += k;
            if (numShow > minNumber) {
                break;
            }
        }

        if (numShow < minNumber) {
            minNumber = numShow;
        }

        numShow = 1;
    }
    
    cout << minNumber << endl;
}