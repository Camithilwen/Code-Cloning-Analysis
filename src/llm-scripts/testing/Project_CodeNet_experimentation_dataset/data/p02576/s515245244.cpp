#include <bits/stdc++.h>          
using namespace std;               

int main() {
    int N, X, T;
    cin >> N >> X >> T;
    int count=N/X;
    if (N%X!=0) {
        count++;
    }
    cout << count*T << endl;
}