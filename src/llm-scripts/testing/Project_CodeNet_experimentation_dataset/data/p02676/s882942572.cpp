#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
    /* Input */
    int K;
    string S;
    cin >> K;
    cin >> S;
   
    /* Main Logic */
    if ((int)S.size() <= K) {
        cout << S << endl;
        return 0;
    } else {
        cout << S.substr(0, K) + "..." << endl;
        return 0;
    }
}