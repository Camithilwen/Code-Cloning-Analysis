#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin>>a[i];
    int ans = 0;
    sort(a.begin(), a.end());
    for (int i = 0; i<n-2; i++) {
        int j1 = i+1;
        while (j1 < n-1 && a[j1] == a[i]) j1++;
        for (int j=j1; j<n-1; j++) {
            int k1 = j+1;
            while (k1<n && a[k1] == a[j]) k1++;
            for (int k = k1; k<n; k++) {
                if (a[k] < a[i] + a[j]) ans++;
                else break;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}