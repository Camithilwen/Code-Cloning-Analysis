#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main() {
    int N, sum, digit;
    cin >> N;
    digit = log10(N);
    sum = 0;
    for (int i = 0; i <= digit; i++) {
        sum += N % (int (pow(10, i + 1))) / (int (pow(10, i)));
    }
    if (N % sum == 0) {
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}
