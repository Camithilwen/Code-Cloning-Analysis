#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int main() {
    int n;
    long long int ans = 3;
    cin >> n;
    int a[n], rgb[3] = {0};
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
  	if(a[0] != 0) {
    	cout << 0 << '\n';
      	return 0;
    }
    rgb[0] = 1;
    for(int i = 1; i < n; ++i) {
        int sum = 0;
        for(int j = 0; j < 3; ++j) {
            if(rgb[j] == a[i]) sum++;
        }
        ans *= sum;
        ans %= MOD;
        for(int j = 0; j < 3; ++j) {
            if(rgb[j] == a[i]) {
                rgb[j]++;
                break;
            }
        }
    }
    cout << ans << '\n';

    return 0;
}
