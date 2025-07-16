#include<bits/stdc++.h>
using namespace std;
int arr[55], pref[55];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
        pref[i] = arr[i] +  pref[i - 1];
    }
    int answer = -2e9;
    int sum1 = 0;
    for (int i = 0; i <= n; ++i) {
        int sum2 = 0;
        for (int j = i + 1; j <= n + 1; ++j) {
            if (i + n - j + 1 <= k) {
                multiset<int> l, r;
                for (int x = 1; x <= i; ++x) {
                    if (arr[x] < 0) {
                        l.insert(arr[x]);
                    }
                }
                for (int x = n; x >= j; --x) {
                    if (arr[x] < 0) {
                        r.insert(arr[x]);
                    }
                }
                int sum1 = 0;
                auto p1 = l.begin();
                for (int x = 0; x <= l.size(); ++x) {
                    if (x > 0) {
                        sum1 += *p1;
                        ++p1;
                    }
                    int sum2 = 0;    
                    auto p2 = r.begin();
                    for (int y = 0; y <= r.size(); ++y) {
                        if (y > 0) {
                            sum2 += *p2;
                            ++p2;
                        }
                        if (x + y <= k - (i + n - j + 1)) {
                            answer = max(answer, pref[i] + pref[n] - pref[j - 1] - sum1 - sum2);
                        } 
                    }
                }
            }
        }
    }
    cout << answer;
}