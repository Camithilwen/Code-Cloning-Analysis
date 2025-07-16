#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, X, T;
    cin >> N >> X >> T;
    int q = (N / X) + (N % X != 0);
    cout << q*T;

    return 0;
}
