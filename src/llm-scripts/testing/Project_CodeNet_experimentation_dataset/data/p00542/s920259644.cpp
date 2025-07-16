#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> a(4);
    vector<int> b(2);
    for (int i = 0; i<4; i++) {
        cin >> a[i];
    }
    for (int i = 0; i<2; i++) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    cout << a[3] + a[1] + a[2] +b[1] << endl;
    
    return 0;
}

