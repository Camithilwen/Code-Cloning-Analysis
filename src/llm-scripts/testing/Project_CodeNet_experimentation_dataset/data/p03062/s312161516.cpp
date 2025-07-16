#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    int n;
    cin >> n;
    vector<ll> a(n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        sum += a[i];
    }

    ll ans = sum;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] < 0) {
            a[i] *= -1;
            a[i+1] *= -1;
            sum += 2 * a[i];
            sum += 2 * a[i+1];
        }
        ans = max(sum, ans);
    }

    for (int i = n; i >= 1; i--) {
        if (a[i] < 0) {
            a[i] *= -1;
            a[i-1] *= -1;
            sum += 2 * a[i];
            sum += 2 * a[i-1];
        }
        ans = max(sum, ans);
    }
    
    printf("%lld\n", ans);

}