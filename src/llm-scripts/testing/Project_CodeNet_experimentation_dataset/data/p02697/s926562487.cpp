#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m;
    cin >> n >> m;

    int k=m*2+1;
    // first part
    for ( int l=1,r=m; l<r; l++,r-- ) {
        cout << l << ' ' << r << '\n';
    }
    for ( int l=m+1,r=k; l<r; l++,r-- ) {
        cout << l << ' ' << r << '\n';
    }
    return 0;
}
