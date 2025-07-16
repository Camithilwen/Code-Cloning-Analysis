#include <bits/stdc++.h>
using namespace std;

int main() {
    while (true) {
        int n, m;
        cin >> n >> m;
        
        if (n==0 && m==0) {
            break;
        }
        
        int p[n];
        int s = 0;
        
        for (int i=0; i<n; i++) {
            cin >> p[i];
            s += p[i];
        }
        
        sort(p, p+n, greater<int>());
        
        for (int i=1; i*m-1<n; i++) {
            s -= p[i*m-1];
        }
        
        cout << s << endl;
    }
}
