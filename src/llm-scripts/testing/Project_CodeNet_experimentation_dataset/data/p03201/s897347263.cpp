#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    map<ll, int> nums;
    rep(i, n) {
        cin >> a[i];
        nums[a[i]]++;
    }

    sort(a.rbegin(), a.rend());
    int ans = 0, i = 0;
    while (i < n) {
        ll biggest_num = a[i++];
        if (nums[biggest_num] == 0) {
            continue;
        }
        nums[biggest_num]--;
        ll sumToBe = 0;
        while ((biggest_num >> sumToBe) > 0ll) {
            sumToBe++;
        }

        ll comp = (1 << sumToBe) - biggest_num;
        if (nums[comp]) {
            ans++;
            nums[comp]--;
        }
    }
    cout << ans << endl;
}