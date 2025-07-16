#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;


int main(void) {
    int n, i, j, l[30] = {};
    ll ans = 1;
    string a;

    cin >> a;

    n = a.size();

    for (i = 0; i < n; i++) {
        l[a[i] - 'a']++;
    }

    for (i = 0; i < 26; i++) for (j = i + 1; j < 26; j++) {
        ans += (ll)l[i] * l[j];
    }

    cout << ans << endl;

    return 0;
}