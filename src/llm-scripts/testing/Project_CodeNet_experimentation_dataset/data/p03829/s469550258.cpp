#include <iostream>

using namespace std;

int main() {
    int n;
    long long a, b;
    long long xi, x;
    long long ans=0;
    cin >> n >> a >> b;
    cin >> x;
    for (int i =0; i < n-1; ++i) {
        cin >> xi;
        if (a*(xi - x) > b)
            ans += b;
        else
            ans += a*(xi-x);
        x = xi;
    }
    cout << ans;
    return 0;
}
