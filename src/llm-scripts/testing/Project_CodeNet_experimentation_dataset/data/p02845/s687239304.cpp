#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
#define mod 1000000007
int main() {
    int n;
    cin >> n;
    int k = 0, l = 0, m = 0;
    ll ret = 1;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (k == a) {
            int count = 1;
            k++;
            if (l == a) count++;
            if (m == a) count++;
            ret = ret * count % mod;
        }
        else if (l == a) {
            int count = 1;
            l++;
            if (m == a) count++;
            ret = ret * count % mod;
        }
        else if (m == a) {
            m++;
        }
        else {
            ret = 0;
            break;
        }
    }
    cout << ret << endl;
    return 0;
}